/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
    /* 1. Al recibir senal SIGINT se ejecutara funcion handler  */
    signal(SIGINT, handler);
    while(1);
    return 0;
}