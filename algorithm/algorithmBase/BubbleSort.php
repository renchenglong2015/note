<?php

include_once("../Common.php");

/**
 * 冒泡排序，对相邻两元素进行两两比较，顺序相反则进行交换，每一次交换会把最大的元素浮到尾部，最终达到有序
 */
function bubbleSort(&$data)
{
    $len = count($data);
    //设定一个标记，若为true，则表示此次循环没有进行交换，也就是待排序列已经有序，排序已然完成。
    $flag = true;
    for ($i = 0; $i < $len - 1; $i++) {
        for ($j = 0; $j < $len - $i - 1; $j++) {
            if ($data[$j] > $data[$j + 1]) {
                swap($data[$j], $data[$j + 1]);
                $flag = false;
            }
        }
        if ($flag) {
            break;
        }
    }
}

testSort("bubbleSort", 100);
testSort("bubbleSort", 1000);

