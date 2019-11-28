/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 03, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#ifndef functions_H_
#define functions_H_

#define MAX 20  //cantidad maxima de letras del nombre/clave

typedef struct user
{
    char name[MAX];
    char key[MAX];
    unsigned long time;
}user;

/* 1. Defino un enum con las opciones para facilitar el manejo del array de funciones */
typedef enum options
{
    SIGNIN = 1,
    SIGNUP,
    SHOW,
    END
}options;

typedef enum EXIT
{
    ERROR = -1,
    SUCCES,
    DELETION,
    ADDITION
}EXIT;


#define NLETTER (((name[0] >= 'A') && (name[0] <= 'Z')) || ((name[0] >= 'a') && (name[0] <= 'z')))
#define CLETTER (((client[i].name[0] >= 'A') && (client[i].name[0] <= 'Z')) || ((client[i].name[0] >= 'a') && (client[i].name[0] <= 'z')))
#define VALID_OP ((op >= SIGNIN) && (op <= END))

/* 2. Modos para imprimir en pantalla */
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED    printf("\033[31m");
#define SET_GREEN  printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");
#define HIDE        printf("\033[08m");


/* 3. Declaración de la función "sign_up". */
int sign_up(user**, int*);

/* 4. Declaración de la función "sign_in". */
int sign_in(user*, int*);

/* 5. Declaración de la función "show_data". */
int show_data(user*, int);

/* 6. Declaración de la función "end". */
int end(user**);

/* 7. Declaración de la función "user_check". */
int user_check(user*, char*, int);

/* 8. Declaración de la función "delete_user". */
int delete_user(user*, int, int);

/* 9. Declaración de la función "stolower". */
void stolower();

/* 11. Declaración de la función "time_order". */
void time_order(user*, int);

int add(user **q, char *name, char* key, int user_cnt);

#endif  // functions_H_