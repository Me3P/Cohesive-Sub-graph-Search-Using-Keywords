#!/bin/bash
make


files='144.txt DD_g138.txt MANN-a45.txt'
for file in $files
do
    current=$(date +%s%N)
    echo $file
    ./output $file
    after=$(date +%s%N)
    time_diff=$(($after-$current))
    echo $time_diff
done

