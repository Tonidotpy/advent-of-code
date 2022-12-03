#!/bin/bash

function ord() { printf '%d' "'$1'"; }

AOrd=$(ord 'A')
ZOrd=$(ord 'Z')
aOrd=$(ord 'a')

function getIndex() {
    if [ $1 -le $ZOrd ]; then
        echo $(( $1 - $AOrd + 26 ))
    else
        echo $(( $1 - $aOrd ))
    fi
}

res=0

# Does not stop reading with direct input
while read line1; do
    read line2
    read line3
    a1=( $(for i in {1..52}; do echo 0; done;) )
    a2=( $(for i in {1..52}; do echo 0; done;) )
    a3=( $(for i in {1..52}; do echo 0; done;) )
    len1=$(( ${#line1} - 1 ))
    len2=$(( ${#line2} - 1 ))
    len3=$(( ${#line3} - 1 ))

    for i in $(seq 0 $len1); do
        a1[$(getIndex $(ord ${line1:$i:1}))]=1
    done
    for i in $(seq 0 $len2); do
        a2[$(getIndex $(ord ${line2:$i:1}))]=1
    done
    for i in $(seq 0 $len3); do
        a3[$(getIndex $(ord ${line3:$i:1}))]=1
    done

    for i in $(seq 0 51); do
        if [[ ${a1[$i]} -eq 1 && ${a2[$i]} -eq 1 && ${a3[$i]} -eq 1 ]]; then
            res=$(( $res + $i + 1 ))
        fi
    done
done

echo $res