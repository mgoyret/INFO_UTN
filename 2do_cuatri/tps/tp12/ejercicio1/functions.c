/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 16, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

/* 1. Definicion de la funcion "ok_process" */

/**
 * \fn      void ok_process()
 * \brief   Crea un proceso hijo, lo finaliza, y el padre, luego de esperar al hijo, finaliza.
 * \author  Marcos Goyret
 * \date    Oct 16, 2019
 */
    
void ok_process()
{
    __pid_t pid;
    int wstatus;

    pid = fork();

    if (pid > 0)
    {
        printf("Soy el padre, PID: %d,   mi hijo es PID: %d\n", getpid(), pid);
        wait(&wstatus);
        printf("RIP padre de PID: %d\n", getpid());
    }
    else if (pid == 0)
    {
        printf("Soy el hijo, PID: %d,   mi padre es PID: %d\n", getpid(), getppid());
        sleep(10);
        printf("RIP hijo de PID: %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Error en funcion fork\n");
    }

}

/* 2. Definicion de la funcion "zombie" */

/**
 * \fn      void ok_process()
 * \brief   Crea un proceso zombie.
 * \author  Marcos Goyret
 * \date    Oct 16, 2019
 */
    
void zombie()
{
    __pid_t pid;

    pid = fork();

    if (pid > 0)
    {
        printf("Soy el padre, PID: %d,   mi hijo es PID: %d\n", getpid(), pid);
        sleep(20);
        printf("RIP padre de PID: %d\n", getpid());
    }
    else if (pid == 0)
    {
        printf("Soy el hijo, PID: %d,   mi padre es PID: %d\n", getpid(), getppid());
        printf("RIP hijo de PID: %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Error en funcion fork\n");
    }

}

/* 3. Definicion de la funcion "orphan" */

/**
 * \fn      void ok_process()
 * \brief   Crea un proceso huerfano.
 * \author  Marcos Goyret
 * \date    Oct 16, 2019
 */
    
void orphan()
{
    __pid_t pid;

    pid = fork();

    if (pid > 0)
    {
        printf("Soy el padre, PID: %d,   mi hijo es PID: %d\n", getpid(), pid);
        printf("RIP padre de PID: %d\n", getpid());
    }
    else if (pid == 0)
    {
        printf("Soy el hijo, PID: %d,   mi padre es PID: %d\n", getpid(), getppid());
        sleep(20);
        printf("RIP hijo de PID: %d\n", getpid());
    }
    else
    {
        printf("Error en funcion fork\n");
    }

}