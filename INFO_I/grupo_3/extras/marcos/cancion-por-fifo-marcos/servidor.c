/**
 * \file            servidor.c
 * \brief           Servidor - Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 23, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main(int argc, char** argv)
{
	FILE *fp1, *fp_song;
    unsigned long writen = 0, size = 0, pst = 0;
    char auxbuf[BUF_S];

    if(argc == 2)
    {
        /* 1. Crea el FIFO si no existe */
        mknod(FIFO_FILE1, S_IFIFO|0666, 0);
        fp1 = fopen(FIFO_FILE1, "w");
        if(fp1 != NULL)
        {
            size = file_size(argv[1]);

            fp_song = fopen(argv[1], "r");
            if (fp_song != NULL)
            {
                while((!feof(fp_song)) && (!ferror(fp_song)))
                {
                    writen += fread(auxbuf, 1, BUF_S, fp_song);
                    fwrite(auxbuf, 1, BUF_S, fp1);
                    clr_screen
                    /* 2. Calculo porcentaje del archivo que fue enviado enviado */
                    pst = (writen*100)/size;
                    printf("\033[1;1HTRANSFER: %ld%c\n", pst, '%');
                }
                if (ferror(fp_song))
                {
                    printf("ERROR:  ferror(fp_song)\n");
                }
                   
                fclose(fp_song);
                printf("Transferencia finalizada\n");
                printf("Se enviaron %ld bytes del archivo '%s', que pesa %ld bytes\n", writen, argv[1], size);
            }
            else
            {
                printf("Error leyendo cancion\n");
            }
            /* 3. Tiempo antes de cerrar el FIFO para que el cliente llegue a copiar al temp_file */
            sleep(1);
            fclose(fp1);   
        }
        else
        {
            printf("Error en funcion fopen 1\n");
        }
    }
    else
    {
        printf("Cantidad de argumentos incorrecta\n");
    }
    
	return 0;
}