#!/bin/bash

cnt=0
while read line; do
    lb=$(echo $line | cut -d, -f1 | cut -d'-' -f1)
    le=$(echo $line | cut -d, -f1 | cut -d'-' -f2)
    rb=$(echo $line | cut -d, -f2 | cut -d'-' -f1)
    re=$(echo $line | cut -d, -f2 | cut -d'-' -f2)

    if [[ $lb -le $rb && $le -ge $re || $lb -ge $rb && $le -le $re ]]; then
        cnt=$(( $cnt + 1 ))
    fi
done

echo $cnt