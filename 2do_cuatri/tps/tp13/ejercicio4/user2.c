/**
 * \file            user2.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
	FILE *fp1, *fp2;
    char buf_user2_send[MAX], buf_user2_recive[MAX];

	/* 1. Crea el FIFO si no existe */
	mknod(FIFO_FILE1, S_IFIFO|0666, 0);
	mknod(FIFO_FILE2, S_IFIFO|0666, 0);

    while(1)
    {
        fp1 = fopen(FIFO_FILE1, "w");
        if(fp1 != NULL)
        {
            printf("Ingrese mensaje: ");
            fgets(buf_user2_send, MAX, stdin);
            /* 2. Reemplazo el '\n' por '\0' */
            buf_user2_send[strcspn(buf_user2_send, "\n")] = '\0';
            fputs(buf_user2_send, fp1);

            fclose(fp1);
        }
        else
        {
            printf("Error en funcion fopen 1\n");
        }

        fp2 = fopen(FIFO_FILE2, "r");
        if(fp2 != NULL)
        {
            fgets(buf_user2_recive, MAX, fp1);
            printf("Mensaje recibido: %s\n", buf_user2_recive);

            fclose(fp2);
        }
        else
        {
            printf("Error en funcion fopen 2\n");
        }      
    }
    
	return 0;
}