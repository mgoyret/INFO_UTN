/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 03, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main(int argc, char** argv)
{
    int exit = 0, buff_size, sound_card_fd, i_time, f_time, status, rec_time, read_info;
    FILE* audio_file_fd;
 	unsigned char* buf = NULL;
    HeaderIfw audio_prop;

    if (argc == 2)
    {
        if(  (*(*(argv+1)) == '-') && (*(*(argv+1)+1) == 'n')  )
        {
            audio_file_fd = fopen(argv[1]+2, "r");
            if(audio_file_fd != NULL)
            {
                /* 1. Invoco a la funcion "get_header", que carga el encabezado del archivo apuntado por "audio_file_fd" en la estructura "audio_prop" */
                get_header(&audio_file_fd, &audio_prop);
                /* 2. Invoco a la funcion "calculate_size", que calcula la duracion del audio en base a la informacion del encabezado del archivo */
                rec_time = calculate_size(audio_file_fd, audio_prop);

                /* 3. Calculamos dinámicamente el tamaño del buffer de audio */
                buff_size = rec_time*audio_prop.sample_rate*audio_prop.bits_per_sample*atoi(&(audio_prop.num_channels))/BITS/MILI;
                buf = (unsigned char *) malloc(buff_size);
                if(buf != NULL)
                {
                    sound_card_fd = open("/dev/dsp", O_RDWR);
                    if(sound_card_fd != -1)
                    {
                        /* 4. Seteamos parámetros de audio */
                        set_audio_prop(sound_card_fd, &audio_prop);

                        /* 5. Inicializamos la variable de tiempo y limpiamos la pantalla */
                        i_time = time(NULL);
                        printf("\033[2J\n");

                        while ((exit == 0) && (!feof(audio_file_fd)))
                        {
                            /* 6. Cantidad "buff_size*1" bytes del archivo audio_file_fd es leida y almacenada en "buf" */
                            read_info = fread(buf, 1, buff_size, audio_file_fd);
                            if(read_info >= 0)
                            {
                                f_time = time(NULL);
                                printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", argv[1]+2, (f_time-i_time)/60, (f_time-i_time)%60);
                                printf("Frec: %d\t Tam: %d\tCan: %d\n", audio_prop.sample_rate, audio_prop.bits_per_sample, atoi(&(audio_prop.num_channels)));

                                /* 7. Cantidad "buff_size" (si hay esa cantidad disponible, sino, la cantidad que quede de informacion) del contenido de "buf"
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
                        printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", argv[1]+2, (f_time-i_time)/60, (f_time-i_time)%60);
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
        }
        else
        {
            printf("Parametros ingresados incorrectamente\n");
            exit = 1;
        }
    }
    else
    {
        printf("Cantidad de parametros erronea\n");
        exit = 1;
    }
    
    if(exit > 2)    fclose(audio_file_fd);
    if(exit > 3)    free(buf);
    if(exit > 4)    close(sound_card_fd);    
    
	return exit;
}