#!/bin/bash

# Para ejecutar: 
# Opcion 1) bash compile.sh
# Opcion 2) chmod +x compile.sh
#           ./compile.sh

gcc -c main.c -o main.o -Wall
gcc main.o -o program -Wall
./program
