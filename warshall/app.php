<?php

$INF = 9999;

function PrintResult($distance, $verticesCount)
{
    global $INF;

    echo "Shortest distances between every pair of vertices:" . "\n";

    for ($i = 0; $i < $verticesCount; ++$i)
    {
        for ($j = 0; $j < $verticesCount; ++$j)
        {
            if ($distance[$i][$j] == $INF)
                echo str_pad("INF", 7);
            else
                echo str_pad($distance[$i][$j], 7);
        }

        echo "\n";
    }
    echo  "\n";
}

function FloydWarshall($graph, $verticesCount)
{
    $distance = array();

    for ($i = 0; $i < $verticesCount; ++$i)
        for ($j = 0; $j < $verticesCount; ++$j)
            $distance[$i][$j] = $graph[$i][$j];

    for ($k = 0; $k < $verticesCount; ++$k)
    {
        for ($i = 0; $i < $verticesCount; ++$i)
        {
            for ($j = 0; $j < $verticesCount; ++$j)
            {
                if ($distance[$i][$k] + $distance[$k][$j] < $distance[$i][$j])
                    $distance[$i][$j] = $distance[$i][$k] + $distance[$k][$j];
            }
        }
    }

    PrintResult($distance, $verticesCount);
}

$graph = array(
    array(0, 1, $INF, $INF, $INF, $INF),
    array($INF, 0, 1, 3, 2, $INF),
    array(3, $INF, 0, 2, $INF, $INF),
    array($INF, $INF, $INF, 0, $INF, 2),
    array($INF, $INF, $INF, -3, 0, $INF),
    array($INF, $INF, $INF, $INF, 3, 0)

);

FloydWarshall($graph, 6);

?>