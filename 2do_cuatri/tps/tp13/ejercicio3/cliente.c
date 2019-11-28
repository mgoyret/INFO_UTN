/**
 * \file            cliente.c
 * \brief           Cliente - Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

/*  Consigna
    Realizar dos programas que se comunicarán a través de un named pipe (FIFO). El primer programa
    debe enviarle al segundo programa un comando (“/refran”, “/cancion” o “/pelicula”) a lo que el
    segundo programa debe responder con un refrán, el nombre de una canción o el nombre de una
    pelı́cula. Luego ambos programas deben terminar. Colocar los printf() que considere necesario para
    demostrar el correcto funcionamiento de la comunicación. Opcional: Hacer que lo devuelto varı́e
    aleatoriamente dentro de una lista de posibles valores.
*/

#include "functions.h"

int main()
{
	FILE *fp1, *fp2;
    char buf_client_send[MAX], buf_client_recive[MAX];

	/* 1. Crea el FIFO si no existe */
	mknod(FIFO_FILE1, S_IFIFO|0666, 0);
	mknod(FIFO_FILE2, S_IFIFO|0666, 0);

    while(1)
    {
        fp1 = fopen(FIFO_FILE1, "w");
        if(fp1 != NULL)
        {
            printf("Ingrese mensaje: ");
            fgets(buf_client_send, MAX, stdin);
            /* 2. Reemplazo el '\n' por '\0' */
            buf_client_send[strcspn(buf_client_send, "\n")] = '\0';
            fputs(buf_client_send, fp1);

            fclose(fp1);
        }
        else
        {
            printf("Error en funcion fopen 1\n");
        }
        /* 3. msj_check() devuelve '-1' si no hubo coincidencia con las palabras clave, y '1' si hubo */
        if(msj_check(buf_client_send) == 1)
        {
            fp2 = fopen(FIFO_FILE2, "r");
            if(fp2 != NULL)
            {
                fgets(buf_client_recive, MAX, fp2);
                set_highlit
                set_blue
                set_space
                printf("Server me envio: %s\n\n", buf_client_recive);
                set_default
                set_space

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