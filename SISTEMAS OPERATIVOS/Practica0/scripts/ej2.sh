#!/bin/bash


if [ $# -ne 1 ]; then
        echo "Uso ejercicio2.sh <ruta>"
        exit 1
elif [ -f $1 ]; then
        LINEAS=$(wc -l $1 | tr -d $1 )
        echo "El fichero $1 tiene $LINEAS líneas"
        exit 0
else
        echo "El fichero $1 no existe"
        exit 0
fi;

exit 0
