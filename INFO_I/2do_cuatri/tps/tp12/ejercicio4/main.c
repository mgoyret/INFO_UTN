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
    int pid = 0;

    signal(SIGUSR1, recive_hijo);
    signal(SIGUSR2, recive_padre);

    pid = fork();

    if (pid > 0)
    {
        printf("Soy el padre\tPID: %d\tmi hijo es\tPID: %d, le enviare SIGUSR1 dentro de 5 segundos\n", getpid(), pid);
        /* Le doy tiempo al hijo para presentarce */
        sleep(5);
        /* Envio senal SIGUSR1 al preoceso de pid 'pid', que en este caso es el hijo */
        kill(pid, SIGUSR1);
        /* El padre solo terminara si se ejecuta la funcion 'recive_padre' tras recivir la senal 'SIGUSR2', enviada por el hijo justo antes de morir */
        while(1);
    }
    if (pid == 0)
    {
        printf("Soy el hijo\tPID: %d\tmi padre es\tPID: %d\n", getpid(), getppid());
        /* El hijo solo terminara si se ejecuta la funcion 'recive_hijo' tras recivir la senal 'SIGUSR1' */
        while(1);
    }

    return 0;
}