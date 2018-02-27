<?php

/**
 * 多任务协作：它要求当前正在运行的任务自动把控制传回给调度器，这样就可以运行其他任务了。
 * 这与抢占多任务相反，抢占多任务：调度器可以中断运行了一段时间的任务。
 * 协程与任务调度之间的关系，yield指令提供了中断任务自身的方法，然后把控制交回给任务调度器。
 * 因此协程可以运行多个任务。
 */
class Task
{

    protected $taskId;
    protected $coroutine;
    protected $sendValue;
    protected $beforeFirstYield = true;

    public function __construct($taskId, Generator $coroutine)
    {
        $this->taskId = $taskId;
        $this->coroutine = $coroutine;
    }

    public function getTaskId()
    {
        return $this->taskId;
    }

    public function setSendValue($sendValue)
    {
        $this->sendValue = $sendValue;
    }

    public function run()
    {
        if ($this->beforeFirstYield) {
            $this->beforeFirstYield = false;
            return $this->coroutine->current();
        } else {
            $retval = $this->coroutine->send($this->sendValue);
            $this->sendValue = null;
            return $retval;
        }
    }

    public function isFinished()
    {
        return !$this->coroutine->valid();
    }

}

/**
 * 调度器
 */
class Scheduler
{

    protected $maxTaskId = 0;
    protected $taskMap = []; //taskId = task
    protected $taskQueue;

    public function __construct()
    {
        $this->taskQueue = new SplQueue();
    }

    public function newTask(Generator $coroutine)
    {
        $tid = ++$this->maxTaskId;
        $task = new Task($tid, $coroutine);
        $this->taskMap[$tid] = $task;
        $this->schedule($task);
        return $tid;
    }

    public function schedule(Task $task)
    {
        $this->taskQueue->enqueue($task);
    }

    public function run()
    {
        while (!$this->taskQueue->isEmpty()) {
            $task = $this->taskQueue->dequeue();

            $retval = $task->run();
            if ($retval instanceof SystemCall) {
                $retval($task, $this);
                continue;
            }

            if ($task->isFinished()) {
                unset($this->taskMap[$task->getTaskId()]);
            } else {
                $this->schedule($task);
            }
        }
    }

    //杀掉任务
    public function killTask($tid)
    {
        if (!isset($this->taskMap[$tid])) {
            return false;
        }

        unset($this->taskMap[$tid]);

        foreach ($this->taskQueue as $i => $task) {
            if ($task->getTaskId() === $tid) {
                unset($this->taskQueue[$i]);
                break;
            }
        }
        return true;
    }

}

class SystemCall
{

    protected $callback;

    public function __construct(callable $callback)
    {
        $this->callback = $callback;
    }

    public function __invoke(Task $task, Scheduler $scheduler)
    {
        $callback = $this->callback;
        return $callback($task, $scheduler);
    }

}

/**
 * 返回任务id
 * @return \SystemCall
 */
function getTaskId()
{
    return new SystemCall(function (Task $task, Scheduler $scheduler) {
        $task->setSendValue($task->getTaskId());
        $scheduler->schedule($task);
    });
}

/**
 * 要创建新的任务，然后再杀死它们的话，需要两个以上的系统调用
 */
function newTask(Generator $coroutine)
{
    return new SystemCall(
        function (Task $task, Scheduler $scheduler) use($coroutine) {
        $task->setSendValue($scheduler->newTask($coroutine));
        $scheduler->schedule($task);
    });
}

function killTask($tid)
{
    return new SystemCall(function (Task $task, Scheduler $scheduler) use($tid) {
        $task->setSendValue($scheduler->killTask($tid));
        $scheduler->schedule($task);
    });
}

//测试新脚本
function childTask()
{
    $tid = (yield getTaskId());
    while (1) {
        echo "child task $tid still alive\n";
        yield;
    }
}

function task()
{
    $tid = (yield getTaskId());

    $childTid = (yield newTask(childTask()));

    for ($i = 1; $i <= 6; ++$i) {
        echo "Parent task $tid iteration $i.\n";
        yield;
        if ($i == 3)
            yield killTask($childTid);
    }
}

/**
 * 经过三次迭代以后子任务将被杀死。
 */
$scheduler = new Scheduler;
$scheduler->newTask(task());
$scheduler->run();

