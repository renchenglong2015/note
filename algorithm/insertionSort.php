<?php
include_once("./function.php");

//插入排序排序 算法复杂度为O(n^2);

function insertionSort(&$data){
    $n = count($data);
    for($i = 1; $i < $n; $i++){
        for($j = $i; ($j > 0 && $data[$j] < $data[$j-1]); $j--){
            swap($data[$j],$data[$j-1]);
        }
    }
}



