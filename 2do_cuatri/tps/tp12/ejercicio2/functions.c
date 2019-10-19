/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

/* 1. Definicion de la funcion "handler" */

/**
 * \fn      void handler(int a)
 * \brief   Cuenta cantidad de veces que se presiono 'Ctrl+C' y mata el proceso luego de la quinta vez.
 * \author  Marcos Goyret
 * \date    May 17, 2019
 * \param   a Variable para almacenar status.
 */
    
void handler(int a)
{
    static int i = 1;

    if (i < 5)
    {
        signal(SIGINT, SIG_IGN);
        printf("Presionaste %d veces!\n", i);
        i++;
        signal(SIGINT, handler);        
    }
    else
    {
        printf("Presionaste por 5 y ultima vez!\n");
        signal(SIGINT, SIG_DFL);   
        kill(getpid(), SIGINT);
    }    
}