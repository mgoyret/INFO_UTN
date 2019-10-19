#include "functions.h"

int i = 0;

/* 1. Definicion de la funcion "mi_alarma" */

/**
 * \fn      void mi_alarma(int a)
 * \brief   Imprime una alarma por pantallas, y la cantidad de veces que se presiono ctrl+c.
 * \author  Marcos Goyret
 * \date    Oct 17, 2019
 * \param   a Variable para almacenar status.
 */
    
void mi_alarma(int a)
{
    printf("ALARMA\n");
    printf("Presionaste 'Ctrl + C' %d veces\n", i);
    signal(SIGINT, SIG_DFL);
    kill(getpid(), SIGINT);
}

/* 2. Definicion de la funcion "handler" */

/**
 * \fn      void handler(int a)
 * \brief   Cuenta cantidad de veces que se presiono 'Ctrl+C'.
 * \author  Marcos Goyret
 * \date    May 17, 2019
 * \param   a Variable para almacenar status.
 */
    
void handler(int a)
{
    signal(SIGINT, SIG_IGN);
    i++;
    printf(" Esa tecla no me mata!\n");
    signal(SIGINT, handler);         
}