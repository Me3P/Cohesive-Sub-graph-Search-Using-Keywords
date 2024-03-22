#!/bin/bash
make
mkdir logs


file=$1
current=$(date +%s%N)
echo $file
./output $file
after=$(date +%s%N)
time_diff=$(($after-$current))
echo $time_diff >> logs/$file


