/**
 * Marcos Goyret
 * Practica 2do parcial Info1 UTN 29/11/2019
 * FIFO
*/

#include <stdio.h>
#include <string.h>

//FIFO
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

    printf("Server prendido\n");
    while (conectado)
    {
        fp1 = fopen("FIFO1", "r");
        if (fp1 != NULL)
        {
            printf("Esperando mensaje\n");
            fread(msg_recv, sizeof(char), TAM, fp1);
            printf("Ya recibi\n");
            fclose(fp1);

            if (strcmp(msg_recv, "salir") != 0)
            {
                printf("[CLIENTE]: '%s'\n", msg_recv);
                
                fp2 = fopen("FIFO2", "w");
                if (fp2 != NULL)
                {
                    printf("Escriba mensaje a enviarle: ");
                    fgets(msg_send, TAM, stdin);
                    msg_send[strlen(msg_send)-1] = '\0';

                    printf("Enviando mensaje '%s'\n", msg_send);
                    fwrite(msg_send, sizeof(char), TAM, fp2);  
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
                printf("Cliente ingreso '%s'\n", msg_recv);
                conectado = 0;
                remove("FIFO1");
                remove("FIFO2");
            }
        }
        else
        {
            printf("ERROR: fopen\n");
        }
    }   

    return 0;
}