#!/bin/bash

IFS=''
read s
n=$(( (${#s} + 1) / 4 ))
v=()

cnt=0
# Parse crates drawing (from top to bottom)
while [ ${#s} -ne 0 ]; do
    
    for (( i=0; i < $n; i++ )); do
        j=$(( $i * 4 ))
        if [ ${s:$j:1} = '[' ]; then
            v[$i]+=${s:$(($j+1)):1}
        fi    
    done

    (( cnt++ ))
    read s
done
# Reverse crates
for (( i=0; i < $n; i++ )); do
    v[$i]=$(echo ${v[$i]} | rev)
done

IFS=' '
# Move crates
while read _ qt _ from _ to; do
    (( from-- ))
    (( to-- ))

    for (( i=0; i < $qt; i++ )); do
        last=$(( ${#v[$from]} - 1 ))
        aux=${v[$from]:$last:1}
        v[$from]=${v[$from]:0:$last}
        v[$to]+=$aux
    done
done

# Print result
for x in ${v[@]}; do
    echo -n ${x:$(( ${#x} - 1 )):1}
done