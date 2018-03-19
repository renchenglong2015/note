<?php

function swap(&$a, &$b)
{
    list($a, $b) = [$b, $a];
}

function microtime_float()
{
    list($usec, $sec) = explode(" ", microtime());
    return ((float) $usec + (float) $sec);
}
