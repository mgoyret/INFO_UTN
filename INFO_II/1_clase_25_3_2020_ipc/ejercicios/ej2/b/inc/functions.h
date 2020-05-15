/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

/* 1. Defines para comodidad de indentacion */
#define TOTAL   98
#define MAX     30

/* 2. Estrructura a enviar a la cola de mensajes */
typedef struct qmsg
{
    long type;
    char legajo[8];
    int  area;
    char nombre[MAX];
    char apellido[MAX];
}qmsg;

/* 3. Creo enum con los distintos tipos de mensajes para facilitar indentacion */
typedef enum msg_types
{
    MSG = 1,
    END
}msg_types;

/* 4. Prototipo de funcion area_check(). Chequea si la linea actual coincide con el area deseada */
int area_check(char *line, char *area);

/* 5. Prototipo de funcion set_line. Escribe una nueva linea en el nuevo arhcivo */
void set_line(char *line, FILE* fp2);

/* 6. Declaracion de la funcion "clean_struct". Limpia el contenido de todos los campos de la estructura */
void clean_struct(qmsg* msg);

#endif /* FUNCTIONS_H_ */