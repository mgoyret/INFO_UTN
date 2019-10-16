#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void recive_hijo(int a);
void recive_padre(int a);

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

void recive_hijo(int a)
{
    printf("SIGUSR1 recibido por PID: %d, le enviare SIGUSR2 a mi padre PID: %d y luego morire\n", getpid(), getppid());
    kill(getppid(), SIGUSR2);
    exit(0);
}

void recive_padre(int a)
{
    printf("SIGUSR2 recivido por PID: %d, lo debe haber mandado mi hijo antes de morir. Muero yo tambien\n", getpid());
    wait(NULL);
    exit(0);
}