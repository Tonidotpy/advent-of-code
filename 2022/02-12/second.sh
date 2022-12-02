#!/bin/bash

function ord() { printf '%d' "'$1'"; }
function pts() { echo $(( $(ord $1) - $(ord 'X') )); }
function off() {
    if [ $1 = 'A' ]; then
        echo 2
    elif [ $1 = 'B' ]; then
        echo 0
    else
        echo 1
    fi
}
res=0
while read a b
do
    p=$(pts $b)
    res=$(( $res + $p * 3 + ($p + $(off $a)) % 3 + 1 ))
done

echo $res