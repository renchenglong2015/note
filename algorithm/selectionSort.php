<?php
include_once("./function.php");
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

