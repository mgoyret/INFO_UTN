/**
 * \file            cliente.c
 * \brief           Cliente - Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 23, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

/*  Consigna
    Realizar un programa, llamado “servidor”, el cual recibirá el nombre de un archivo de audio como
    argumento. Luego, enviará dicho archivo de audio a un programa “cliente” a través de un named
    pipe (FIFO). El programa cliente deberá recibir dicho archivo y reproducirlo. Al finalizar el envı́o,
    el programa servidor terminará su ejecución y lo mismo ocurrirá en el programa cliente al terminar
    la reproducción. Nota: Se debe utilizar como programa cliente el mismo programa “play”
    desarrollado en el ejercicio 10.2.
*/

#include "functions.h"


/**
 * \file            cliente.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 23, 2019
 * \details         Usar MakeFile para compilar y linkear
 */


int main()
{
    int exit = 0, buff_size = 0, sound_card_fd = 0, i_time = 0, f_time = 0, status = 0, rec_time = 0, read_info = 0;
 	unsigned char* buf = NULL, auxbuf[BUF_S];
    HeaderIfw audio_prop;
    FILE *fp1 = NULL, *audio_file_fp = NULL;

    // 1. Crea el FIFO si no existe
	mknod(FIFO_FILE1, S_IFIFO|0666, 0);


    /* 2. Creo temp_file, archivo donde se almacenara temporalmente la cancion recibida */
    fp1 = fopen(FIFO_FILE1, "r");
    if(fp1 != NULL)
    {
        audio_file_fp = fopen(TEMP_FILE, "w");
        if (audio_file_fp != NULL)
        {
            while (!feof(fp1) && (!ferror(fp1)))
            {
                fread(auxbuf, 1, BUF_S, fp1);
                fwrite(auxbuf, 1, BUF_S, audio_file_fp);
                /* 3. Tiempo para q el servidor me pase la cancion y no se encuentre el EOF solo porque lei mas rapido de lo que me enviaron */
                usleep(100 K);
            }
            if(ferror(fp1))
            {
                printf("ERROR:  ferror(fp1)\n");
            }
            fclose(audio_file_fp);
        }
        else
        {
            printf("Error creando temp file\n");
        }
    
        fclose(fp1);
    }
    else
    {
        printf("Error en funcion fopen 1\n");
    }   

    /* 4. Ya poseemos el archivo de audio copiado completamente en el archivo temporal, se procedera a reproducirlo y luego borrarlo */
    printf("Transferencia finalizada, presione enter para continuar:");
    getchar();

    audio_file_fp = fopen(TEMP_FILE, "r");
    if(audio_file_fp != NULL)
    {
        /* 5. Invoco a la funcion "get_header", que carga el encabezado del archivo apuntado por "audio_file_fp" en la estructura "audio_prop" */
        get_header(&audio_file_fp, &audio_prop);
        /* 6. Invoco a la funcion "calculate_size", que calcula la duracion del audio en base a la informacion del encabezado del archivo */
        rec_time = calculate_size(audio_file_fp, audio_prop);

        /* 7. Calculamos dinámicamente el tamaño del buffer de audio */
        buff_size = rec_time*audio_prop.sample_rate*audio_prop.bits_per_sample*atoi(&(audio_prop.num_channels))/BITS/MILI;
        buf = (unsigned char *) malloc(buff_size);
        if(buf != NULL)
        {
            sound_card_fd = open("/dev/dsp", O_RDWR);
            if(sound_card_fd != -1)
            {
                /* 8. Seteamos parámetros de audio */
                set_audio_prop(sound_card_fd, &audio_prop);

                /* 9. Inicializamos la variable de tiempo y limpiamos la pantalla */
                i_time = time(NULL);
                printf("\033[2J\n");

                while ((exit == 0) && (!feof(audio_file_fp)))
                {
                    /* 10. Cantidad "buff_size*1" bytes del archivo audio_file_fp es leida y almacenada en "buf" */
                    read_info = fread(buf, 1, buff_size, audio_file_fp);
                    if(read_info >= 0)
                    {
                        f_time = time(NULL);

                        printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", TEMP_FILE, (f_time-i_time)/60, (f_time-i_time)%60);
                        printf("Frec: %d\t Tam: %d\tCan: %d\n", audio_prop.sample_rate, audio_prop.bits_per_sample, atoi(&(audio_prop.num_channels)));

                        /* 11. Cantidad "buff_size" (si hay esa cantidad disponible, sino, la cantidad que quede de informacion) del contenido de "buf"
                                es "escrito" en "sound_card_fd". Osea es reproducido */
                        status = write(sound_card_fd, buf, buff_size);
                        if (status < 0)
                        {
                            printf("Error en funcion write, buf_size es %d y status es %d, código de error: %s\n", buff_size, status, strerror (status));
                            exit = 6;
                        }   
                    }
                    else
                    {
                        printf("Error en funcion freed, código de error: %s\n", strerror (status));
                        exit = 5;
                    }       
                }
				status = ioctl(sound_card_fd, SOUND_PCM_SYNC, 0);
                f_time = time(NULL);
                printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", TEMP_FILE, (f_time-i_time)/60, (f_time-i_time)%60);
            }
            else
            {
                printf("Error en funcion open\n");
                exit = 4;
            }
        }
        else
        {
        printf("Error en funcion malloc\n");
            exit = 3;
        } 
    }
    else
    {
        printf("Error en funcion fopen\n");
        exit = 2;
    }
    
    if(exit > 2)    fclose(audio_file_fp);
    if(exit > 3)    free(buf);
    if(exit > 4)    close(sound_card_fd);    

    /* 12. Elimino el archivo temporal sobre el cual fue copiada la cancion */
    remove(TEMP_FILE);
    remove(FIFO_FILE1);

	return exit;
}