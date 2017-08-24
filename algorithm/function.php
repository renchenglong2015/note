<?php
function swap(&$a, &$b){
    $c = $a;
    $a = $b;
    $b = $c;
}

function microtime_float()
{
    list($usec, $sec) = explode(" ", microtime());
    return ((float)$usec + (float)$sec);
}
function testTime($functionName,&$data)
{
     $time_start = microtime_float();
     $functionName($data);
     $time_end = microtime_float();
     $time = $time_end - $time_start;
     echo "Did {$functionName} in $time seconds\n";
}
