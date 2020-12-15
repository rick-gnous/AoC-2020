#!/bin/bash

CFLAGS="-W -Wall -pedantic -g"

jour=${1:-0}
while [ $jour -le 0 ] || [ $jour -ge 25 ]
do
    read -p "Indiquez le jour à compiler : " jour
    if ! [[ $jour =~ ^[0-9]+$ ]]
    then
        jour=0
    fi
done

rm -f *.o turbo_main
echo "Compilation de la lib utils.c."
gcc $CFLAGS lib/utils.c -o utils.o -c
echo "Compilation de turbo_main.c."
gcc $CFLAGS turbo_main.c -o turbo_main.o -c
echo "Compilation du jour $jour."
gcc $CFLAGS jour$jour/main.c -o tmp.o -c -Ilib
gcc -o turbo_main tmp.o turbo_main.o utils.o
rm -f *.o 
cp jour$jour/input input
