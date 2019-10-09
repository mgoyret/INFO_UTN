/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 25, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef functions_H_
#define functions_H_

/* 1. Defino un enum con los posibles returns de las funciones. Comienza en 10 para que no interfiere en funcion find() */
typedef enum EXIT
{
    SUCCES = 10,
    ERROR
}EXIT;

/* 2. Defino un enum con las opciones a realizar, para mejorar la indentacion del switch-case */
typedef enum OPTIONS
{
    INSERT,
    DELETE,
    OBTAIN,
    FIND,
    SHOW, 
    END
}OPTIONS;

typedef struct NODE
{
    char user[30];
    int key;
}NODE;

/* 3. Modos para imprimir en pantalla */
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");
#define HIDE        printf("\033[08m");

#define VALID_OP    ((op >= INSERT) && (op <= END))

/* 4. Declaracion de la funcion "insert". Inserta un nodo en la posicion indicada */
int insert(NODE** client, int* user_cnt, NODE temp_node, int position);

/* 5. Declaracion de la funcion "delete". Elimina el nodo presente en la posicion indicada */
int delete(NODE** client, int* user_cnt, NODE* temp_node, int position);

/* 6. Declaracion de la funcion "obtain". Devuelve el valor del nodo presente en la posicion indicada */
int obtain(NODE* client, int user_cnt, NODE* temp_node, int position);

/* 7. Declaracion de la funcion "find". Devuelve la posicion del nodo con un valor coincidiente al indicado */
int find(NODE* client, int user_cnt, NODE temp_node, int* position);

/* 8. Declaracion de la funcion "show". Imprime el contenido del vector */
int show(NODE* client, int user_cnt);

/* 9. Declaracion de la funcion "set_temo". Carga los valores de una estructura pasada como parametro */
int set_temp(NODE* temp_node);

/* 10. Declaracion de la funcion "insert_order". Desplaza en una posicion las estructuras de un array, desde una posicion indicada, dejando una posicion vacia */
void insert_order(NODE* client, int user_cnt, int position);

/* 11. Declaracion de la funcion "delete_order". Desplaza en una posicion las estructuras de un array, desde una posicion indicada, eliminando una posicion */
void delete_order(NODE* client, int user_cnt, int position);

int user_taken(NODE* client, int user_cnt, NODE temp_node);

#endif  // functions_H_