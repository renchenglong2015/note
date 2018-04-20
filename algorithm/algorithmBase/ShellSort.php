<?php

include_once("../Common.php");

/**
 * 希尔排序,属于插入类排序，是将整个无序列分割成若干个子序列分别插入的方法。
 */
function shellSort(&$data)
{
    //$data = [2, 1, 10, 8, 6, 9, 4, 7, 3, 5];
    $len = count($data);
    //计算间隔
    $h = 1;
    while ($h < (int) ($len / 3)) {
        $h = 3 * $h + 1;
    }
    while ($h >= 1) {
        for ($i = $h; $i < $len; $i++) {
            $e = $data[$i];
            for ($j = $i; $j >= $h && $e < $data[$j - $h]; $j -= $h) {
                $data[$j] = $data[$j - $h];
            }
            $data[$j] = $e;
        }
        $h = (int) ($h / 3);
    }
    
}

testSort("shellSort", 1000);
