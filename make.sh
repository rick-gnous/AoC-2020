#!/bin/bash

jour=0
while [ $jour -le 0 ] || [ $jour -ge 25 ]
do
    read -p "Indiquez le jour à compiler : " jour
    if ! [[ $jour =~ ^[0-9]+$ ]]
    then
        jour=0
    fi
done

rm -f *.o turbo_main
echo "Compilation de turbo_main.c."
gcc -Wall -g turbo_main.c -o turbo_main.o -c
echo "Compilation du jour $jour."
gcc -Wall -g jour$jour/main.c -o tmp.o -c
gcc -o turbo_main tmp.o turbo_main.o
rm -f *.o 
cp jour$jour/input input
