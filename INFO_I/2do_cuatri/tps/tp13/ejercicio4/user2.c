/**
 * \file            user2.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

/*  Consigna
    Realizar un chat simple entre dos programas. Dichos programas se comunicarán a través de un named
    pipe (FIFO). Tener en cuenta que la comunicación será por turnos (un mensaje de cada programa por
    vez), y la misma terminará cuando uno de los dos programas envı́e el comando “/exit”.
*/

#include "functions.h"

int main()
{
	FILE *fp1, *fp2;
    char buf_user2_send[MAX], buf_user2_recive[MAX];
    int fin_status = 0;

	/* 1. Crea el FIFO si no existe */
	mknod(FIFO_FILE1, S_IFIFO|0666, 0);
	mknod(FIFO_FILE2, S_IFIFO|0666, 0);

    do
    {
        fp1 = fopen(FIFO_FILE1, "w");
        if(fp1 != NULL)
        {
            printf("Ingrese mensaje: ");
            fgets(buf_user2_send, MAX, stdin);
            /* 2. Reemplazo el '\n' por '\0' */
            buf_user2_send[strcspn(buf_user2_send, "\n")] = '\0';
            fputs(buf_user2_send, fp1);
            fin_status = fin(buf_user2_send);
            if(fin_status == 1) //fin
            {
                printf("Has finalizado la conexion, adios!\n");
            }  
            fclose(fp1);
        }
        else
        {
            printf("Error en funcion fopen 1\n");
        }

        if(fin_status == 0)
        {
            fp2 = fopen(FIFO_FILE2, "r");
            if(fp2 != NULL)
            {
                fgets(buf_user2_recive, MAX, fp2);
                fin_status = fin(buf_user2_recive);
                if (fin_status == 0)
                {
                    printf("Mensaje recibido: '%s'\n", buf_user2_recive);   
                }
                else
                {
                    printf("User1 ah finalizado la conexion, adios!\n");
                }

                fclose(fp2);
            }
            else
            {
                printf("Error en funcion fopen 2\n");
            }  
        }    
	}while(fin_status == 0);

	return 0;
}