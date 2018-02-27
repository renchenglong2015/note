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

function getTaskId()
{
    return new SystemCall(function (Task $task, Scheduler $scheduler) {
        $task->setSendValue($task->getTaskId());
        $scheduler->schedule($task);
    });
}

/**
 * 这个函数设置了任务id为下一次发送的值，并再次调度了这个任务。由于使用了系统调用，所以调度器不能自动调用任务
 * 我们需要手工调度任务。
 * @param type $max
 */
function task($max)
{
    $tid = (yield getTaskId());
    for ($i = 1; $i <= $max; ++$i) {
        echo "This is task $tid iteration $i.\n";
        yield;
    }
}

/**
 * 1.先进入task函数，
 */
$scheduler = new Scheduler;
$scheduler->newTask(task(10));
$scheduler->newTask(task(5));

$scheduler->run();









