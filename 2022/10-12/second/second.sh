#!/bin/bash

function getPixel() {
    if [[ $1 -eq $2 || $1 -eq $(( $2 - 1 )) || $1 -eq $(( $2 + 1 )) ]]; then
        echo '#'
    else
        echo '.' 
    fi
}

crt=($(for i in {1..6}; do echo ""; done))
x=1
cycles=0
IFS='\n'
while read s; do
    aux=0
    row=$(( $cycles / 40 ))
    col=$(( $cycles % 40 ))

    if [ "$s" = "noop" ]; then
        (( cycles++ ))
    else
        (( cycles += 2 ))
        aux=${s:5}

        crt[$row]+=$(getPixel $col $x)
        (( col++ ))
        if [ $col -eq 40 ]; then
            col=0
            (( row++ ))
        fi
    fi
    crt[$row]+=$(getPixel $col $x)
    (( x += $aux ))
done

printf '%s\n' "${crt[@]}"