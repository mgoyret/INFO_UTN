/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 03, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef functions_H_
#define functions_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define MAX 20  //cantidad maxima de letras del nombre/clave
#define CNT 10  //cantidad maxima de usuarios

typedef struct user
{
    char name[MAX];
    char key[MAX];
    unsigned int time;
}user;

/* 1. Defino un enum con las opciones para facilitar el manejo del array de funciones */
typedef enum options
{
    SIGNIN = 1,
    SIGNUP,
    SHOW,
    END
}options;


#define SUCCES      1 
#define ERROR      -1
#define DELETION    2

#define NLETTER (((name[0] >= 'A') && (name[0] <= 'Z')) || ((name[0] >= 'a') && (name[0] <= 'z')))
#define CLETTER (((client[i].name[0] >= 'A') && (client[i].name[0] <= 'Z')) || ((client[i].name[0] >= 'a') && (client[i].name[0] <= 'z')))
#define VALID_OP ((op >= SIGNIN) && (op <= END))

/* 2. Modos para imprimir en pantalla */
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");
#define HIDE        printf("\033[08m");


/* 3. Declaración de la función "sign_up". */
int sign_up(user*, int*);

/* 4. Declaración de la función "sign_in". */
int sign_in(user*, int*);

/* 5. Declaración de la función "show_data". */
int show_data(user*);

/* 6. Declaración de la función "end". */
int end(void);

/* 7. Declaración de la función "user_check". */
int user_check(user*, char*);

/* 8. Declaración de la función "delete_user". */
int delete_user(user*, int);

/* 9. Declaración de la función "stolower". */
void stolower();

/* 10. Declaración de la función "clean_arr". */
void clearn_arr(user* client);

/* 11. Declaración de la función "time_order". */
void time_order(user* client);

#endif  // functions_H_