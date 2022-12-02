#!/bin/bash

function ord() { printf '%d' "'$1'"; }
function pts() { echo $(( $(ord $1) - $(ord 'X') + 1 )); }
function off() {
    if [ $1 = 'A' ]; then
        echo 3
    elif [ $1 = 'B' ]; then
        echo 0
    else
        echo 6
    fi
}
res=0
while read a b
do
    p=$(pts $b)
    res=$(( $res + $p + (($p-1) * 3 + $(off $a)) % 9 ))
done

echo $res