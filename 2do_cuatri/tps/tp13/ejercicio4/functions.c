/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int fin(char* msj)
{
    int exit = 0;

    if (strcmp(msj, "exit") == 0)
    {
        exit = 1;
    }
    return exit;
}