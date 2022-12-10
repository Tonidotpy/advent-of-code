#!/bin/bash

x=1
cycles=0
strength=0
IFS='\n'
while read s; do
    if [ $(( ($cycles + 21) % 40 )) -eq 0 ]; then
        (( strength += (($cycles + 1) * $x) ))
    fi

    if [ "$s" = "noop" ]; then
        (( cycles++ ))
    else
        if [ $(( ($cycles + 22) % 40 )) -eq 0 ]; then
            (( strength += (($cycles + 2) * $x) ))
        fi
        (( cycles += 2 ))
        (( x += ${s:5} ))
    fi
done

echo $strength