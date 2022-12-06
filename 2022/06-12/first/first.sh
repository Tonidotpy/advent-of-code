#!/bin/bash

function ord() { printf '%d' "'$1'"; }

aOrd=$(ord a)

read s
n=${#s}

a=($(for i in $(seq 1 26); do echo 0; done;))

cnt=0
for i in $(seq 0 2); do
    cur=$(( $(ord ${s:$i:1}) - $aOrd ))
    a[$cur]=$(( ${a[$cur]} + 1 ))
    if [ ${a[$cur]} -gt 1 ]; then
        cnt=$(( $cnt + 1 ))
    fi
done

for i in $(seq 3 $n); do
    cur=$(( $(ord ${s:$i:1}) - $aOrd ))
    prev=$(( $(ord ${s:$(( $i - 3 )):1}) - $aOrd ))

    a[$cur]=$(( ${a[$cur]} + 1 ))
    if [ ${a[$cur]} -gt 1 ]; then
        cnt=$(( $cnt + 1 ))
    fi

    if [ $cnt -eq 0 ]; then
        echo $(( $i + 1 ))
        exit 0;
    fi

    a[$prev]=$(( ${a[$prev]} - 1 ))
    if [ ${a[$prev]} -ge 1 ]; then
        cnt=$(( $cnt - 1 ))
    fi
done