<?php

include_once("./Common.php");

/**
 * 为什么要学习O(n^2)的排序算法
 * 基础：编码简单，易于实现，是一些简单场景的首选
 * 在一些特殊情况下，简单的排序方法更有效。
 * 简单的排序算法思想衍生出复杂的排序算法。
 * 作为子过程，改进更复杂的算法。
 */

/**
 * 选择排序法：每一次从待排序的数据元素中选出最小（最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
 */
function selectionSort(&$data)
{

    $cnt = count($data);
    for ($i = 0; $i < $cnt; $i++) {
        //寻找区间[$i, $cnt)之间的最小值
        $minIndex = $i;
        for ($j = $i + 1; $j < $cnt; $j++) {
            if ($data[$j] < $data[$minIndex]) {
                $minIndex = $j;
            }
        }
        swap($data[$i], $data[$minIndex]);
    }
}

/**
 * Did selectionSort in 0.00039792060852051 seconds
 * Did selectionSort in 0.026356935501099 seconds
 * Did selectionSort in 2.151398897171 seconds
 */
testSort("selectionSort");
testSort("selectionSort", 1000);
testSort("selectionSort", 10000);



