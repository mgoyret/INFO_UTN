/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 21, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 30

typedef struct qmsg
{
    long msg_type;
    unsigned long legajo;
    char area[MAX];
    char nombre[MAX];
    char apellido[MAX]:
}qmsg;

#endif /* FUNCTIONS_H_ */