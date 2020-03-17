/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h" 

/* 1. Definicion de la funcion "recive_hijo" */

/**
 * \fn      void recive_hijo(int a)
 * \brief   Se activa al recibir una senal del padre, y le envia otra. Luego mata al proceso hijo.
 * \author  Marcos Goyret
 * \date    Oct 17, 2019
 * \param   a Variable para almacenar status.
 */

void recive_hijo(int a)
{
    printf("SIGUSR1 recibido por PID: %d, le enviare SIGUSR2 a mi padre PID: %d y luego morire\n", getpid(), getppid());
    kill(getppid(), SIGUSR2);
    exit(0);
}

/* 2. Definicion de la funcion "recive_padre" */

/**
 * \fn      void recive_padre(int a)
 * \brief   Se activa al recibir una senal del hijo, espera a que este muera, y luego mata al proseso padre.
 * \author  Marcos Goyret
 * \date    Oct 17, 2019
 * \param   a Variable para almacenar status.
 */
    
void recive_padre(int a)
{
    printf("SIGUSR2 recivido por PID: %d, lo debe haber mandado mi hijo antes de morir. Muero yo tambien\n", getpid());
    wait(NULL);
    exit(0);
}