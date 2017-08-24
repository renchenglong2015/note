<?php
include_once("insertionSort.php");
include_once("selectionSort.php");

$data = range(0, 10000);
shuffle($data);

$data1 = $data;
testTime("selectionSort", $data);
testTime("insertionSort", $data1);

