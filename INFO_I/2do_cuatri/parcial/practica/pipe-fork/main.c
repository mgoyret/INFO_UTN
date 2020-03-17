/**
 * Marcos Goyret
 * Practica 2do parcial Info1 UTN 29/11/2019
 * Pipes y fork
*/

#include <stdio.h>
#include <string.h>

//fork
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAM 20
#define LECTURA 0
#define ESCRITURA   1

int main()
{
    int pid = 0, fd1[2], fd2[2];
    char msg[TAM];

    printf("Comienzo en main\n");

    pipe(fd1);
    pipe(fd2);

    pid = fork();
    if (pid > 0) // PADRE
    {
        close(fd1[LECTURA]);
        close(fd2[ESCRITURA]);

        printf("PADRE: pid [%d]. Mi hijo es [%d] y le dire 'hola'\n", getpid(), pid);
        strcpy(msg, "hola");
        write(fd1[ESCRITURA], msg, TAM);

        sleep(2);
        read(fd2[LECTURA], msg, TAM);
        printf("Soy padre de vuelta y mi hijo me dice '%s'\n", msg);

        printf("Padre esperando al hijo q muera\n");
        pid = wait(NULL);
        printf("Padre muere, enterre a [%d]\n", pid);
    }
    else if (pid == 0) // HIJO
    {
        sleep(1);

        close(fd1[ESCRITURA]);
        close(fd2[LECTURA]);

        read(fd1[LECTURA], msg, TAM);

        printf("HIJO: pid [%d]. Mi padre es [%d] y me dice '%s'. le dire 'chau'\n", getpid(), getppid(), msg);
        strcpy(msg, "chau");
        write(fd2[ESCRITURA], msg, TAM);
        sleep(3);

        printf("Hijo muere\n");
    }
    else // ERROR fork
    {
        printf("Error en fork\n");
    }
    
    return 0;
}