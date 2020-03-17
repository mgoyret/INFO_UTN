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
    int i, exit = 0, audio_name_start, rec_time, buff_size, sound_card_fd, i_time, f_time, status;
    HeaderIfw audio_prop;
 	unsigned char* buf = NULL;
    FILE* audio_file_fp;

    if (argc == 6)
    {
        /* 1. El campo "format" siempre valdra "INFOWAVE" que es el formato de archivo */
        strcpy(audio_prop.format, "INFOWAVE");
        /* 2. Cargo los parametros del audio ingresados por el usuario, en una estructura */
		for (i=1; i<argc; i++)
		{   /* 3. En el string "-n<File_Name>" el contenido de *(argv+i) sera el '-' del inicio. Luego, si es el nombre, la siguiente posicion,
                    que sera (*(argv+i)+1), tendra en su contenido un 'n', o el caracter correspondiente a el parametro a ingresar. Luego, suponiendo
                    que se ingreso la 'n', se que en el ontenido de la siguiente posicion, (*(argv+i)+2), comienza el nombre del archivo */
            if(  (*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'r')  )
                {
                    audio_prop.sample_rate = atoi((*(argv+i)+2));
                }
            else if(  (*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 's')  )
                {
                    audio_prop.bits_per_sample = atoi((*(argv+i)+2));
                }
            else if(  (*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'c')  )
                {
                    audio_prop.num_channels = (*(*(argv+i)+2));
                }
            else if(  (*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'n')  )
                {
                    audio_name_start = i;
                }
            else if( (*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 't') )  
                {
                    rec_time = atoi((*(argv+i)+2));
                }
            else exit = 1; 
		}

        if(exit == 0)
        {
            /* 4. Calculamos dinámicamente el tamaño del buffer de audio */
            buff_size = rec_time*audio_prop.sample_rate*audio_prop.bits_per_sample*(atoi(&(audio_prop.num_channels)))/BITS/MILI;
            buf = (unsigned char *) malloc(buff_size);
            if (buf != NULL)
            {
                /* 5. Creamos el archivo de audio */
                audio_file_fp = fopen(argv[audio_name_start]+2, "w");
                if (audio_file_fp != NULL)
                {
                    /* 6. Lo primero en escribir al archivo es el header */
                    load_header(audio_file_fp, audio_prop);

                    /* 7. Abro el "archivo" placa de sonido */
                    sound_card_fd = open("/dev/dsp", O_RDWR);
                    if (sound_card_fd != -1) //open devuelve -1 si hubo error
                    {
                        /* 8. Invoco a la funcion "set_audio_prop", que setea los parametros deseados a la placa */
                        set_audio_prop(sound_card_fd, &audio_prop);
                        i_time = time(NULL);
                        printf("\033[2J\n");

                        while (exit == 0)
                        {   
                            /* 9. "Leo" el "archivo" sound_card_fd y copio una cantidad "buff_size" de lo leido en "buf". Osea, copio la informacion del microfono
                                    en el archivo buf */
                            status = read(sound_card_fd, buf, buff_size);
                            if (status == buff_size)
                            {
                                if (exit == 0)
                                {
                                    f_time = time(NULL);
                                    printf("\033[1;1HGrabando: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", argv[audio_name_start]+2, (f_time-i_time)/60, (f_time-i_time)%60);
                                    printf("Frec: %d\t Tam: %d\tCan: %c\n", audio_prop.sample_rate, audio_prop.bits_per_sample, audio_prop.num_channels);

                                    if ((f_time - i_time) == rec_time)
                                    {
                                        exit = 7;
                                    }
                                    /* 10. Copiamos el contenido de "buf" en el archivo apuntado por audio_file_fp. El buffer va copiando de a pequenos periodos
                                            de tiempo, muchas veces, en vez de almacenar todo el audio y copiarlo de una. */
                                    status = fwrite(buf, 1, buff_size, audio_file_fp);
                                    if (status != buff_size)
                                    {
                                        fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (status)); 
                                        exit = 6;
                                    }
                                }
                            }
                            else
                            {
                                fprintf(stderr,"Error en función read, Código de error: %s\n",strerror (status));
                                exit = 5;
                            }
                        }
                    }
                    else
                    {
                        printf("Error al habilitar placa de sonido. Código de error: %s\n", strerror (sound_card_fd));
                        exit = 4;
                    }
                }
                else
                {
                    printf("Error al generar archivo de audio\n");
                    exit = 3;
                }   
            }
            else
            {
                printf("Error en funcion malloc\n");
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

	if (exit > 2) free (buf);
	if (exit > 3) fclose(audio_file_fp);
	if (exit > 4) close(sound_card_fd);
    
	return exit;
}