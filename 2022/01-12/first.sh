#!/bin/bash
res=0
cur=0
while read line
do
    if [ -z $line ]
    then
        res=$((res > cur ? res : cur))
        cur=0
    else
        cur=$(($line + $cur))
    fi
done

echo $((res > cur ? res : cur))