/**
 * Marcos Goyret
 * Practica 2do parcial Info1 UTN 29/11/2019
 * FIFO
*/

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TAM 30

int main()
{
    int conectado = 1;
    char msg_send[TAM], msg_recv[TAM];
    FILE *fp1 = NULL, *fp2 = NULL;

    mknod("FIFO1", S_IFIFO|0666, 0);
	mknod("FIFO2", S_IFIFO|0666, 0);

    printf("Cliente en linea\n");

    while (conectado)
    {
        fp1 = fopen("FIFO1", "w");
        if (fp1 != NULL)
        {

            printf("Ingrese mensaje a enviar: ");
            fgets(msg_send, TAM, stdin);
            msg_send[strlen(msg_send)-1] = '\0';
            if(strcmp(msg_send, "salir") != 0)
            {
                printf("Enviando mensaje '%s'\n", msg_send);
                fwrite(msg_send, sizeof(char), TAM, fp1);
                fclose(fp1);

                /* Para que el fp2 funcione, ambos deben estar con el archivo abierto. Hasta q el server no abre este fifo, el prog queda trabado */
                fp2 = fopen("FIFO2", "r");
                if (fp2 != NULL)
                {
                    printf("Esperando respuesta del servidor\n");
                    fread(msg_recv, sizeof(char), TAM, fp2);
                    printf("[SERVER]: '%s'\n", msg_recv);  
                    fclose(fp2);
                }
                else
                {
                    printf("ERROR: fopen\n");
                    conectado = 0;
                }  
            }
            else
            {
                printf("Enviando mensaje '%s'\n", msg_send);
                fwrite(msg_send, sizeof(char), TAM, fp1);
                printf("Chau. Se ingreso '%s'\n", msg_send);
                conectado = 0;
                fclose(fp1);
            }
        }
        else
        {
            printf("ERROR: fopen\n");
        }
    }
    return 0;
}