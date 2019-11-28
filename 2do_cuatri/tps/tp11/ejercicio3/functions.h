#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef functions_H_
#define functions_H_

/* 1. Defino un enum con los posibles returns de las funciones. Comienza en 10 para que no interfiere en funcion find() */
typedef enum EXIT
{
    SUCCES = 10,
    ERROR,
    ADDITION,
    DELETION
}EXIT;

typedef enum OPTIONS
{
    ENCOLAR = 1,
    DESENCOLAR,
    ESPIAR,
    MOSTRAR,
    END
}OPTIONS;

typedef struct NODE
{
    char user[30];
    int key;
}NODE;

/* 2. Modos para imprimir en pantalla */
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");
#define HIDE        printf("\033[08m");

#define VALID_OP    ((op >= INSERT) && (op <= END))

int encolar(NODE** cola, int* len, NODE node);

int desencolar(NODE** cola, int* len, NODE* temp_node);

int espiar(NODE* cola, int len, NODE* temp_node);

int mostrar(NODE* cola, int len);

int set_temp(NODE *temp_node);


#endif  // functions_H_
