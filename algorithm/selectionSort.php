<?php
//选择排序法 算法复杂度为O(n^2);
$data = range(0, 20);
shuffle($data);

function selectionSort(&$data){
    $n = count($data);
    for($i = 0; $i < $n; $i++){
        //最小值的下标
        $minIndex = $i;
        for($j = $i+1; $j < $n; $j++){
            if($data[$j] < $data[$minIndex]){
                $minIndex = $j;
            }    
        }
        swap($data[$i], $data[$minIndex]);
    }
}

function swap(&$a, &$b){
    $c = $a;
    $a = $b;
    $b = $c;
}

selectionSort($data);

var_dump($data);
