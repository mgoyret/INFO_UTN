/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 19, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    Crear un programa que permita un diálogo entre dos proceso (padre e hijo).
    La comunicación finaliza cuando el proceso hijo indica "chau".
    Puede utilizar para la resolución: pipes, named pipes o señales según requiera. Justifique su elección.
    Procure que no queden procesos huerfanos ni zombies.
*/

#include "functions.h"

int main ()
{
    int pid, fd1[2], fd2[2], i = on;
    char msg[MSG_MAX];

    /* 1. Si pipe() devuelve '-1' es porque hubo error */
    if ((pipe(fd1) != -1) && (pipe(fd2) != -1))
    {
        pid = fork();
        
        
        
        //////////////////////////////////////////////////////////////
        if (pid > 0) //PADRE
        {
            printf("PADRE: inicio con PID [%d]\n", getpid());

            /* 2. Cada proceso usa solo un extremo de cada pipe. El padre escribe en el pipe 1 y lee del 2, por lo que cierra el extremo de lectura del
                    pipe 1, y el extremo de escritura del pipe 2. */
            close(fd1[lectura]);
            close(fd2[escritura]);

            /* 3. Tiempo para printf ordenados */
            usleep(1000);
            while(i)
            {
                memset(msg, '\0', MSG_MAX);
                printf("\nPADRE: escriba para mandar al hijo: ");
                fgets(msg, MSG_MAX, stdin);
                msg[strlen(msg)-1] = '\0';
                write(fd1[escritura], msg, MSG_MAX);

                memset(msg, '\0', MSG_MAX);
                read(fd2[lectura], msg, MSG_MAX);
                if(strcmp(msg, "fin") == 0)
                {
                    i = off;
                    write(fd1[escritura], "fin", 4);
                }
                else
                {
                    printf("\nPADRE: me llego del hijo: [%s]\n", msg);   
                }
            }

            /* 4. Espero muerte de proceso hijo (cualquier pid) */
            wait(NULL);
            /* 5. Cierro los extremos del pipe restantes */
            close(fd1[escritura]);
            close(fd2[lectura]);
            printf("PADRE: FIN\n");
        }
        //////////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////
        else if (pid == 0) //HIJO
        {
            printf("HIJO: inicio con PID [%d], hijo de [%d]\n", getpid(), getppid());

            /* 6. El hijo utilizara los extremos opuestos al padre de ambos pipes */
            close(fd1[escritura]);
            close(fd2[lectura]);

            while(i)
            {
                memset(msg, '\0', MSG_MAX);
                read(fd1[lectura], msg, MSG_MAX);
                if(strcmp(msg, "fin") == 0)
                {
                    i = off;
                    write(fd2[escritura], "fin", 4);
                }
                else
                {
                    printf("HIJO: me llego del padre: [%s]\n", msg);

                    memset(msg, '\0', MSG_MAX);
                    printf("\nHIJO: escriba para mandar al padre: ");
                    fgets(msg, MSG_MAX, stdin);
                    msg[strlen(msg)-1] = '\0';
                    write(fd2[escritura], msg, MSG_MAX);   
                }
            }


            close(fd1[lectura]);
            close(fd2[escritura]);
            printf("HIJO: FIN\n");
            exit(0);
        }
        //////////////////////////////////////////////////////////////



        else
        {
            printf("ERROR [2]\n");
        }
    }
    else
    {
        printf("ERROR [1]\n");
    }
    return 0;
}