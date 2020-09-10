/**
 *  \file           main.c
 *  \brief          Ejercicio de clase 1
 *  \author         Marcos Goyret
 *  \date           August, 2020
 *  \details        Para compilar:  gcc -c main.c -o main.o -Wall 
 *  \details        Para linkear:   gcc  main.o  -o prog
 *  \details        Para ejecutar:  ./prog
*/

/*  ENUNCIADO
    Realizar un programa en C que me permita mostrar los bytes que componen a una variable entera.
    a. Mediante uniones
    b. Mediante operadores a nivel de bits
    c. ¿Cómo están ordenados los bytes en memoria?
*/

#include <stdio.h>

typedef struct bytes
{
    unsigned char primero;
    unsigned char segundo;
    unsigned char tercero;
    unsigned char cuarto;
}bytes;

typedef union un
{
    unsigned int num;
    bytes st;
}un;

int main ()
{
    unsigned int num = 0x3FF009BC;
    unsigned char aux;
    un a;
    a.num = 0x3FF009BC;

    aux = num&0xFF;
    printf("Byte 1(lsb):\t[%X]\n", aux);

    aux = (num>>8)&0xFF;
    printf("Byte 2:\t\t[%X]\n", aux);

    aux = (num>>16)&0xFF;
    printf("Byte 3:\t\t[%X]\n", aux);

    aux = num>>24;
    printf("Byte 4(lsb):\t[%X]\n", aux);
/////////////////////////////////////////
    printf("\nUNION\n");
    printf("Byte 1(lsb):\t[%X]\n", a.st.primero);
    printf("Byte 2:\t\t[%X]\n", a.st.segundo);
    printf("Byte 3:\t\t[%X]\n", a.st.tercero);
    printf("Byte 4(msb):\t[%X]\n", a.st.cuarto);

    return 0;
}

