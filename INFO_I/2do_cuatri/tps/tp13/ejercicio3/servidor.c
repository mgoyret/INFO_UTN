/**
 * \file            servidor.c
 * \brief           Servidor - Funciones - Archivos Header - Función definida por el usuario
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
	char buf_server_recive[MAX], buf_server_send[MAX]; 

	/* 1. Crea el FIFO si no existe */
	mknod(FIFO_FILE1, S_IFIFO|0666, 0);
	mknod(FIFO_FILE2, S_IFIFO|0666, 0);

	while(1)
	{
        fp1 = fopen(FIFO_FILE1, "r");
        if(fp1 != NULL)
        {
            fgets(buf_server_recive, MAX, fp1);
            printf("Cadena recibida: %s\n", buf_server_recive);

            fclose(fp1);

            /* 2. msj_check() devuelve '-1' si no hubo coincidencia con las palabras clave, y '1' si hubo */
            if(msj_check(buf_server_recive) != -1)
            {
                fp2 = fopen(FIFO_FILE2, "w");
                if(fp2 != NULL)
                {
                    /* 3. Invoco funcion choose_messege(), pasandole el string recivido, y un string en el cual se guardara el mensaje a enviar al cliente */
                    choose_messege(buf_server_recive, buf_server_send);
                    fputs(buf_server_send, fp2);
                    
                    fclose(fp2);   
                }
                else
                {
                    printf("Error en funcion fopen 2\n");
                }    
            }
        }
        else
        {
            printf("Error en funcion fopen 1\n");
        }
	}
	return 0;
}