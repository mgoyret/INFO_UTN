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
#include <stdlib.h>

#ifndef functions_H_
#define functions_H_

typedef enum EXIT
{
    SUCCES = 10,
    ERROR
}EXIT;

/* 2. Defino un enum con las opciones a realizar, para mejorar la indentacion del switch-case */
typedef enum OPTIONS
{
    YES = 1,
    NO
}OPTIONS;

#define CLIENT_MAX    10
#define NAME_MAX      30
#define INT_MAX       21

typedef struct CLIENT
{
    char user[NAME_MAX];
    int key;
}CLIENT;

/* 3. Modos para imprimir en pantalla */
#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");
#define HIDE        printf("\033[08m");

#define VALID_OP    ((op == YES) || (op == NO))

/* 4. Definicion de la funcion "add". Agrega un cliente a un array de clientes */
int add(CLIENT* clients, int* user_cnt);

/* 5. Definicion de la funcion "user_check". Chequea si el nombre de usuario deseado ya fue utilizado */
int user_check(CLIENT* clients, int user_cnt, char *aux_user);

/* 6. Definicion de la funcion "user_cnt_max". Chequea si ya se alcanzo la cantidad maxima de clientes permitida */
int user_cnt_max(int user_cnt);

/* 7. Definicion de la funcion "bin_write". Copia los datos de una estructura de clientes, en un archivo binario */
int bin_write(CLIENT *clients, int user_cnt, char *file_name);

/* 8. Definicion de la funcion "bin_reat". Copia los datos de un archivo binario a una estructura de clientes */
int bin_read(CLIENT *clients, int user_cnt, char *file_name);

/* 9. Definicion de la funcion "clean_struct". Borra todos los valores de todas las posiciones de un array de estructuras de clientes */
int clean_struct(CLIENT* clients, int* user_cnt);

/* 10. Definicion de la funcion "show_clients". Imprime en pantalla los valores de todas las posiciones de un array de estructuras de clientes */
int show_clients(CLIENT* clients, int user_cnt);

#endif  // functions_H_