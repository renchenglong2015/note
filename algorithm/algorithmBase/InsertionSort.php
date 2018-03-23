<?php

include_once("./Common.php");

/**
 * 插入排序，时间复杂度o(n^2)。是稳定的排序方法。
 * 每步将一个待排序的记录，按其关键码值的大小插入到前面已经排序的文件中的适当位置上，
 * 直到全部排完为止。
 * 类似现实场景中的打扑克。
 *
 * $data = [2, 1, 10, 8, 6, 9, 4, 7, 3, 5];
 * 选择排序,每一对元素之间一定会进行一次比较，所以他是比较次数最多的排序算法;
 * 插入排序,每次比较都会交换，所以他是交换次数最多的排序算法.
 */
function insertionSort(&$data)
{
    $len = count($data);
    for ($i = 1; $i < $len; $i++) {
        for ($j = $i; $j > 0 && $data[$j] < $data[$j - 1]; $j--) {
            swap($data[$j], $data[$j - 1]);
        }
    }
}

/**
 * Did insertionSort in 0.00075602531433105 seconds
 * Did insertionSort in 0.083398103713989 seconds
 * Did insertionSort in 6.9242198467255 seconds
 */
testSort("insertionSort");
testSort("insertionSort", 1000);
testSort("insertionSort", 10000);

/**
 * 优化后的插入排序算法，减少交换次数，插入排序可以提前终止内层循环，在近乎有序的集合中，时间复杂度接近O(n);
 */
function insertionSort1(&$data)
{
    $len = count($data);
    for ($i = 1; $i < $len; $i++) {
        $e = $data[$i];
        for ($j = $i; $j > 0 && $e < $data[$j - 1]; $j--) {
            $data[$j] = $data[$j - 1];
        }
        $data[$j] = $e;
    }
}

testSort("insertionSort1");
testSort("insertionSort1", 1000);
testSort("insertionSort1", 10000);
