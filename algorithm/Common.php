<?php

function swap(&$a, &$b)
{
    $a = $a ^ $b;
    $b = $b ^ $a;
    $a = $a ^ $b;
//    $c = $a;
//    $a = $b;
//    $b = $c;
//    list($a, $b) = [$b, $a];
}

function microtime_float()
{
    list($usec, $sec) = explode(" ", microtime());
    return ((float) $usec + (float) $sec);
}

/**
 * 是否排好序
 */
function isSorted($data): bool
{
    $n = count($data);
    for ($index = 0; $index < $n - 1; $index++) {
        if ($data[$index] > $data[$index + 1]) {
            return false;
        }
    }
    return true;
}

/**
 *
 * @param type $functionName  函数名称
 * @param type $len           所生成数组的长度
 */
function testSort($functionName, $len = 99)
{

    //生成一个数组，随机打乱
    $data = range(1, $len);
    shuffle($data);
    $time_start = microtime_float();
    $functionName($data);
    $time_end = microtime_float();
    $time = $time_end - $time_start;
    if (!isSorted($data)) {
        echo "$functionName 排序算法失败";
        exit;
    }
    echo "Did $functionName in $time seconds\n";
}
