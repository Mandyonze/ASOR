#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Invalid arguments."
    exit 1
else
    for FILA in $(ls $1);
    do
        if [ -f $FILA ]; then
            PALABRAS=$(wc -w $FILA | tr -d $FILA)
            echo "$FILA tiene: $PALABRAS palabras."
        fi;
    done
fi;

exit 0
