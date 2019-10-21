/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
    int pid1 = 0, pid2 = 0, cnt = 0, fd[2];

    /* 1. Si pipe() devuelve '-1' es porque hubo error */
    if (pipe(fd) != -1)
    {
        pid1 = fork();
        if (pid1 > 0) //PADRE (primera instancia)
        {
            pid2 = fork();
            if (pid2 > 0) // PADRE (definitivo)
            {
                printf("PADRE: PID %d\n", getpid());
                /* 2. Cree 2 hijos, por lo que espero a que mueran 2 hijos. */
                while (cnt < 2)
                {
                    if(waitpid(-1, NULL, WNOHANG) > 0)
                        cnt++;
                }
                set_space
                printf("PADRE: Chau...\n");
                set_space
            }
            else if(pid2 == 0) // HIJO 2
            {
                /* 3. Cierro extremo del pipe que no utilizare. El hijo 2 lee del pipe, no escribe. */
                close(fd[ESCRITURA]);

                /* 4. Doy tiempo al hijo1 y al padre para que los printf salgan ordenados */
                sleep(2);
                set_space
                printf("HIJO2: PID %d (padre es %d)\n", getpid(), getppid());

                /* 5. Redirigo la entrada del proceso desde stdin al extremo de lectura del pipe (cuando se esperaria un comando, se toma lo que hay en el pipe) */
                dup2(STDIN_FILENO, fd[LECTURA]);
                /* 6. Ejecuto con execlp() el archivo "run2.sh", que contiene la linea de codigo “head”.
                        Al comando "head" le llegaran como parametros lo que haya en el pipe. */
                execlp("bash", "bash", "run2.sh", (char*)NULL);

                printf("HIJO2: Chau...\n");
                close(fd[LECTURA]);
                exit(0);
            }
            else
            {
                printf("Error en segundo fork()\n");
            }
        }
        else if (pid1 == 0) // HIJO 1
        {
            /* 7. Cierro extremo del pipe que no utilizare. El hijo 1 escribe en el pipe, no lee. */
            close(fd[LECTURA]);

            /* 8. Doy tiempo al padre para que los printf salgan ordenados */
            sleep(1);
            set_space
            printf("HIJO1: PID %d (padre es %d)\n", getpid(), getppid());
        
            /* 9. Redirigo stdout al extremo de escritura del pipe (lo que saldria en pantalla, ahora es enviado por el pipe) */
            dup2(STDOUT_FILENO, fd[ESCRITURA]);
            /* 10. Ejecuto con execlp() el archivo "run1.sh", que contiene la linea de codigo “ps -e -o user,pid, %mem,command –sort - %mem” */
            execlp("bash", "bash", "run1.sh", (char*)NULL);

            printf("HIJO1: Chau...\n");
            close(fd[ESCRITURA]);
        }
        else
        {
            printf("Error en primera funcion fork()\n");
        }        
    }
    else
    {
        printf("Error en funcion pipe()\n");
    }
    
    return 0;
}