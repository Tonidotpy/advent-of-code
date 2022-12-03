#!/bin/bash

function ord() { printf '%d' "'$1'"; }

res=0
AOrd=$(ord 'A')
ZOrd=$(ord 'Z')
aOrd=$(ord 'a')

# Does not stop reading with direct input
while read line; do
    a=( $(for i in {1..52}; do echo 0; done;) )
    len=${#line}
    m=$(( $len / 2 ))

    for i in $(seq 0 $(( $m - 1 )) ); do
        index=$(ord ${line:$i:1})
        if [ $index -le $ZOrd ]; then
            a[$(( $index - $AOrd + 26 ))]=1
        elif [ $index -ge $aOrd ]; then
            a[$(( $index - $aOrd ))]=1
        fi
    done
    for i in $(seq $m $(( $len - 1 )) ); do
        index=$(ord ${line:$i:1})
        if [ $index -le $ZOrd ]; then
            index=$(( $index - $AOrd + 26 ))
        elif [ $index -ge $aOrd ]; then
            index=$(( $index - $aOrd ))
        fi
 
        if [ ${a[$index]} -eq 1 ]; then
            a[$index]=0
            res=$(( $res + $index + 1 ))
        fi
    done
done

echo $res