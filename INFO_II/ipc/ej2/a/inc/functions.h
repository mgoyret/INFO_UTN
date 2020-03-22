/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

/* 1. Defines para comodidad de indentacion */
#define MAX     30
#define TOTAL   (30*3)+8+1

/* 2. Estrructura a enviar a la cola de mensajes */
typedef struct qmsg
{
    long type;
    char legajo[8];
    char area[MAX];
    char nombre[MAX];
    char apellido[MAX];
}qmsg;

/* 3. Creo enum con los distintos tipos de mensajes para facilitar indentacion */
typedef enum msg_types
{
    MSG = 1,
    END
}msg_types;

/* 3. Declaracion de la funcion "build_msg". Carga vuelca los datos de "line" en "msg" */
void build_msg(qmsg* msg, char *line);

/* 4. Declaracion de la funcion "clean_struct". Limpia el contenido de todos los campos de la estructura */
void clean_struct(qmsg* msg);

#endif /* FUNCTIONS_H_ */