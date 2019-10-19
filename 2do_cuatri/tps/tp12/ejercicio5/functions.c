/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int hijos_actuales = 0;

/* 1. Definicion de la funcion "son_creator" */

/**
 * \fn      int son_creator(int hijos_pedidos)
 * \brief   Funcion para crear una determinada cantidad de procesos hijos, pasada como parametro.
 * \author  Marcos Goyret
 * \date    Oct 17, 2019
 * \param   hijos_pedidos: Cantidad de hijos a crear.
 * \return  Exit status.
 */
    
int son_creator(int hijos_pedidos)
{
    int i = 0;
    __pid_t pid;

    /* 1.1. Al captar senal 'SIGCHLD' (enviada automaticamente al morir un hijo) se ejecuta la funcion sc_handler */
    signal(SIGCHLD, sc_handler);

    for(i = 0; i < hijos_pedidos; i++)
    {
        pid = fork();

        if (pid > 0)
        {
            hijos_actuales++;
        }
        /* 1.2. Cada hijo creado duerme un segundo, y muere */
        else if (pid == 0)
        {
            printf("Soy hijo numero %d PID: %d\n", hijos_actuales+1, getpid());
            sleep(20);
            printf("RIP hijo PID: %d\n", getpid());
            return EXITO;
        }
        else
        {
            printf("Error en fork\n");
            return ERROR;
        }  
    }

    /* 1.3. La variable hijos_actuales se va decrementando al morir los hijos, luego de que el padre los 'entierre'. El padre muere cuando no quedan hijos */
    while (hijos_actuales != 0);
    printf("RIP padre de PID: %d\n", getpid());
    return EXITO;
}

/* 2. Definicion de la funcion "sc_handler" */

/**
 * \fn      void sc_handler()
 * \brief   Se ejecuta al captarce una senal de muerte de un hijo. Hace que el padre espere muertes de una determinada cantidad de hijos.
 * \author  Marcos Goyret
 * \date    Oct 17, 2019
 */
    
void sc_handler()
{
    /* 2.1. Aunque la funcion se ejecuta cada vez que muere un hijo, para no pasar por alto ninguno (al morir tantos casi a la vez, puede pasar),
        al ejecutarce la funcion, esta loopea hasta que la cantidad de hijos vivos (hijos_actuales) llegue finalmente a 0.  */
    while((waitpid(-1, NULL, WNOHANG) != 0) && (hijos_actuales > 0))
    {
        hijos_actuales--;
    }
}