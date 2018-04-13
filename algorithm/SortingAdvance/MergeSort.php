<?php

/*
 * 归并排序：是利用归并的思想实现的排序方法，该算法采用经典的分治策略。
 * 将已有序的子序列合并，得到完全有序的序列。
 */
include_once("../Common.php");

/**
 * 将arr[l...mid] 和arr[mid+1...r]两部分进行归并
 * @param type $data
 * @param type $l
 * @param type $mid
 * @param type $r
 */
function __merge(&$data, $l, $mid, $r)
{
    //开辟临时空间
    $temp = [];
    for ($i = $l; $i <= $r; $i++) {
        $temp[$i - $l] = $data[$i];
    }
    $i = $l;
    $j = $mid + 1;
    for ($k = $l; $k <= $r; $k++) {
        //比较索引的合法性,当$i超出范围大于$mid,如果$k仍然没有遍历完成，说明此时$j未遍历完成
        if ($i > $mid) {
            $data[$k] = $temp[$j - $l];
            $j++;
        } elseif ($j > $r) {
            $data[$k] = $temp[$i - $l];
            $i++;
        } elseif ($temp[$i - $l] < $temp[$j - $l]) {
            $data[$k] = $temp[$i - $l];
            $i++;
        } else {
            $data[$k] = $temp[$j - $l];
            $j++;
        }
    }
}

/**
 * 递归使用归并排序，对arr[l...r]的范围进行排序
 * @param type $data
 * @param type $l
 * @param type $r
 */
function __mergeSort(&$data, $l, $r)
{
    //首先处理递归到底的情况
    if ($l >= $r) {
        return;
    }
    $mid = (int) (($l + $r) / 2);

    __mergeSort($data, $l, $mid);
    __mergeSort($data, $mid + 1, $r);
    __merge($data, $l, $mid, $r);
}

function mergeSort(&$data)
{
    $n = count($data);
    __mergeSort($data, 0, $n - 1);
}

testSort("mergeSort", 1000000);
