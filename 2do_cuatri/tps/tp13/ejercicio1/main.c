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
	int pid, fd1[2], fd2[2];
	char buffer[MAX_MSJ];

    /* 1. Si pipe() devuelve '-1' es porque hubo error */
    if ((pipe(fd1) != -1) && (pipe(fd2) != -1))
    {
        pid = fork();
        if (pid > 0) //PADRE
        {
            printf("PADRE: PID %d\n", getpid());
            /* 2. Cada proceso usa solo un extremo de cada pipe. El padre escribe en el pipe 1 y lee del 2, por lo que cierra el extremo de lectura del
                    pipe 1, y el extremo de escritura del pipe 2. */
            close(fd1[LECTURA]);
            close(fd2[ESCRITURA]);

            printf("PADRE: Escribiendo en el pipe 1\n");
            write(fd1[ESCRITURA], "Luke, soy tu padre!!", MAX_MSJ);

            /* 3. Doy tiempo para que los mensajes se impriman ordenados */
            sleep(2);
            printf("PADRE: Leyendo desde el pipe 2\n");
            read(fd2[LECTURA], buffer, MAX_MSJ);
            printf("PADRE: Lei \"%s\"\n", buffer);
            
            wait(NULL);
            printf("PADRE: Chau...\n");

            /* 4. Cierro los extremos del pipe restantes */
            close(fd1[ESCRITURA]);
            close(fd2[LECTURA]);
        }
        else if(pid == 0) //HIJO
        {
            printf(" HIJO: PID %d\n", getpid());
            /* 5. El hijo utilizara los extremos opuestos al padre de ambos pipes */
            close(fd1[ESCRITURA]);
            close(fd2[LECTURA]);

            sleep(1);
            printf(" HIJO: Leyendo desde el pipe 1\n");
            read(fd1[LECTURA], buffer, MAX_MSJ);
            printf(" HIJO: Lei \"%s\"\n", buffer);

            printf(" HIJO: Escribiendo en el pipe 2\n");
            write(fd2[ESCRITURA], "Noooooo!!", MAX_MSJ);


            printf(" HIJO: Chau...\n");
            close(fd1[LECTURA]);
            close(fd2[ESCRITURA]);
            exit(0);
        }
        else
        {
            printf("Error en funcion fork\n");
        }
    }
    else
    {
        printf("Error al crear pipes\n");
    }

    return 0;
}