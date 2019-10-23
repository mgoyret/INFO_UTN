/**
 * \file            user1.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
	FILE *fp1, *fp2;
	char buf_user1_recive[MAX], buf_user1_send[MAX]; 
    int fin_status = 1;

	/* 1. Crea el FIFO si no existe */
	mknod(FIFO_FILE1, S_IFIFO|0666, 0);
	mknod(FIFO_FILE2, S_IFIFO|0666, 0);

	while(fin_status)
	{
        fp1 = fopen(FIFO_FILE1, "r");
        if(fp1 != NULL)
        {
            fgets(buf_user1_recive, MAX, fp1);
            fin_status = fin(buf_user1_recive);
            if(fin_status)
            {
                printf("Mensaje recibido: %s\n", buf_user1_recive);
            }
            else
            {
                printf("Adios!\n");
            }  
            fclose(fp1);
        }
        else
        {
            printf("Error en funcion fopen 1\n");
        }
        /* Si recibio mensaje de fin, no envia mensaje, solo termina */
        if(fin_status)
        {
            fp2 = fopen(FIFO_FILE2, "w");
            if(fp2 != NULL)
            {
                printf("Ingrese mensaje: ");
                fgets(buf_user1_send, MAX, stdin);
                /* 2. Reemplazo el '\n' por '\0' */
                buf_user1_send[strcspn(buf_user1_send, "\n")] = '\0';
                fin_status = fin(buf_user1_send);
                if(fin_status)
                {
                    fputs(buf_user1_send, fp2);
                }
                else //fin
                {
                    printf("Adios!\n");
                }            
                fclose(fp2);   
            }
            else
            {
                printf("Error en funcion fopen 2\n");
            }   
        } 
	}
	return 0;
}