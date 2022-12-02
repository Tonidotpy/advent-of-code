#!/bin/bash
res=()
cur=0
while read line
do
    if [ -z $line ]
    then
        res+=($cur)
        cur=0
    else
        cur=$(($line + $cur))
    fi
done
res+=($cur)
res=($(echo ${res[@]} | tr " " "\n" | sort -nr | tr "\n" " "))

echo $((${res[0]} + ${res[1]} + ${res[2]}))