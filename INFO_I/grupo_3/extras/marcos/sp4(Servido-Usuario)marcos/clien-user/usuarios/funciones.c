#include "funciones.h"

/*  Definicion de la funcion "set_audio_prop" */

/**
 * \fn      void set_audio_prop (int sound_card_fd, HeaderIfw *audio_prop)
 * \brief   Setea el Sample Rate, los Bits Per Sample y el Numero de Canales con que trabajara la placa. Utiliza la system call ioctl();
 * 			Es para "prender" o habilitar la placa de sonido con los parametros que queremos, antes de mandarle algo a reproducir
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Oct 03, 2019
 * \param	sound_card_fd: File Descriptor asociado al dispositivo de audio (/dev/dsp)
 * \param	audio_prop: Estructura con los parámetros para configurar el dispositivo de audio.
			Recibido por referencia para que la función que la llamó sepa en cuanto se configuró.
 */
    
void set_audio_prop (int sound_card_fd, HeaderIfw *audio_prop)
{
	int param, status = 0;
	char DBGMSG[100];

	param = audio_prop->bits_per_sample;

	/* SOUND_PCM_WRITE_BITS es la macro que escribe en la placa de sonido */
	status = ioctl(sound_card_fd, SOUND_PCM_WRITE_BITS, &param);
	if (status != -1)
	{
		if (param != audio_prop->bits_per_sample)
		{
			fprintf (stderr,"Tamaño de muestras no soportado. Se programó %d\n", param);
			audio_prop->bits_per_sample = param;
		}

		param = atoi(&(audio_prop->num_channels));
		status = ioctl(sound_card_fd, SOUND_PCM_WRITE_CHANNELS, &param);
		if (status != -1)
		{
			if (param == atoi(&(audio_prop->num_channels)))
			{
				/* Velocidad de Muestreo */
				param = audio_prop->sample_rate;
				status = ioctl(sound_card_fd, SOUND_PCM_WRITE_RATE, &param);
				if (status != -1)
				{
					if (param != audio_prop->sample_rate)
					{
						printf("Velocidad de muestreo no soportada. Se programó %d\n", param);
						audio_prop->sample_rate = param;
					}
				}
				else
					perror("Error en comando SOUND_PCM_WRITE_RATE");
						#ifndef ALGO
                            sprintf(DBGMSG,"Error en comando SOUND_PCM_WRITE_RATE\n");
                            log_msg(error,__FILE__,__LINE__,DBGMSG);
                        #endif					
			}
			else
				printf("Cantidad de canales no soportado. Se programó %d\n", param);
						#ifndef ALGO
                            sprintf(DBGMSG,"Cantidad de canales no soportado\n");
                            log_msg(error,__FILE__,__LINE__,DBGMSG);
                        #endif
		}
		else
			perror("Error en comando SOUND_PCM_WRITE_CHANNELS");	
						#ifndef ALGO
                            sprintf(DBGMSG,"Error en comando SOUND_PCM_WRITE_CHANNELS\n");
                            log_msg(error,__FILE__,__LINE__,DBGMSG);
                        #endif
	}
	else
		perror("Error con comando SOUND_PCM_WRITE_BITS");
						#ifndef ALGO
                            sprintf(DBGMSG,"Error con comando SOUND_PCM_WRITE_BITS\n");
                            log_msg(error,__FILE__,__LINE__,DBGMSG);
                        #endif
}


/*  Definicion de la funcion "get_header" */

/**
 * \fn      int get_header(FILE** audio_file_fd, HeaderIfw* audio_prop)
 * \brief   Carga las propiedades del audio, presentes al comienzo del archivo, en una estructura.
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Oct 03, 2019
 * \param	sound_card_fd: File Descriptor asociado al dispositivo de audio (/dev/dsp)
 * \param	audio_prop: Estructura con los parámetros para configurar el dispositivo de audio.
			Recibido por referencia para que la función que la llamó sepa en cuanto se configuró.
 */
    
int get_header(FILE** audio_file_fd, HeaderIfw* audio_prop)
{
	int status = 1;

	fread(audio_prop->format, 9, sizeof(char), *audio_file_fd);
	fread(&(audio_prop->sample_rate), 1, sizeof(int), *audio_file_fd);
	fread(&(audio_prop->bits_per_sample), 1, sizeof(int), *audio_file_fd);
	fread(&(audio_prop->num_channels), 1, sizeof(char), *audio_file_fd);
	status = 0;

	return status;
}


/*  Definicion de la funcion "calculate_size" */

/**
 * \fn      int calculate_size(FILE* audio_file_fd, HeaderIfw audio_prop)
 * \brief	Calcula la duracion del audio de un archivo "infowave", a partir de la informacion presente en el encabezado del mismo.
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Oct 03, 2019
 * \param	audio_file_fd: File Descriptor asociado al archivo de audio a reproducir.
 * \param	audio_prop: Estructura en la que se almacenara la informacion del audio presente en el archivo.
 */
    
int calculate_size(FILE* audio_file_fd, HeaderIfw audio_prop)
{
	int time = -1;
	int byte_cnt = 0;
	int channel_cnt = atoi(&(audio_prop.num_channels));

	/* 3.1. Me aseguro de posicionar el puntero del archivo justo despues del encabezado, y antes del audio */
	fseek(audio_file_fd, sizeof(HeaderIfw), SEEK_SET);

	/* 3.2. Cuento cuantos bytes hay en el archivo para saber el peso total (sin contar los bytes del encabezado). */
	while(fgetc(audio_file_fd) != EOF)
		byte_cnt++;

	/* 3.3. Ecuacion que calcula duracion en segundos a partir del peso de las muestras de audio, cuantas de ellas hay por segundo, y cuantas hay en total */
	time = ((((byte_cnt/channel_cnt)*BITS) / audio_prop.bits_per_sample) /audio_prop.sample_rate);
	/* 3.4. Al grabar el audio, la funcion se corta un instante antes del ultimo segundo indicado, y al estar la informacion en un "int", se redondea para abajo,
			por lo que se debe incrementar en uno el segundero para compenzar ese segundo no contado */
	time++;

	/* 3.5. Me aseguro de dejar el puntero del archivo nuevamente justo antes del audio, para poder reproducirlo a continuacion */
	fseek(audio_file_fd, sizeof(HeaderIfw), SEEK_SET);

	return time;
}


/*  Definicion de la funcion "play" */

/**
 * \fn      int play(char* camino_cancion, char* nombre_cancion)
 * \brief   Reproduce la cancion deseada
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Oct 03, 2019
 * \param	camino_cancion: variable por referencia de la direccion donde se encuentra la cancion
 * \param	nombre_cancion: variable por referencia del nombre de la cancion
			Recibido por referencia para que la función que la llamó sepa en cuanto se configuró.
 */

int play(char* camino_cancion, char* nombre_cancion)
{
    int exit = 0, buff_size, sound_card_fd, i_time, f_time, status, rec_time, read_info;
    //int op = 0;
    FILE* audio_file_fd;
 	unsigned char* buf = NULL;
    HeaderIfw audio_prop;
    char DBGMSG[100];
                                    #ifndef ALGO
                                        sprintf(DBGMSG,"Abriendo archivo camino_cancion\n");
                                        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
    audio_file_fd = fopen(camino_cancion, "r");
    if(audio_file_fd != NULL)
    {
                                    #ifndef ALGO
                                        sprintf(DBGMSG,"Archivo abierto exitosamente\n");
                                        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
        /* 1. Invoco a la funcion "get_header", que carga el encabezado del archivo apuntado por "audio_file_fd" en la estructura "audio_prop" */
        get_header(&audio_file_fd, &audio_prop);
        /* 2. Invoco a la funcion "calculate_size", que calcula la duracion del audio en base a la informacion del encabezado del archivo */
        rec_time = calculate_size(audio_file_fd, audio_prop);

        /* 3. Calculamos dinámicamente el tamaño del buffer de audio */
        buff_size = rec_time*audio_prop.sample_rate*audio_prop.bits_per_sample*atoi(&(audio_prop.num_channels))/BITS/MILI;
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Obteniendo memoria\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
        buf = (unsigned char *) malloc(buff_size);
                                
        if(buf != NULL)
        {
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Memoria obtenida de forma exitosa\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
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
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Leyendo archivo\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
                            read_info = fread(buf, 1, buff_size, audio_file_fd);
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Archivo leido\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
                            if(read_info >= 0)
                            {
                                f_time = time(NULL);
                                printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", nombre_cancion, (f_time-i_time)/60, (f_time-i_time)%60);
                                printf("Frec: %d\t Tam: %d\tCan: %d\n", audio_prop.sample_rate, audio_prop.bits_per_sample, atoi(&(audio_prop.num_channels)));

                                /* 7. Cantidad "buff_size" (si hay esa cantidad disponible, sino, la cantidad que quede de informacion) del contenido de "buf"
                                        es "escrito" en "sound_card_fd". Osea es reproducido */
                                status = write(sound_card_fd, buf, buff_size);
                                if (status < 0)
                                {
                                    printf("Error en funcion write, buf_size es %d y status es %d, código de error: %s\n", buff_size, status, strerror (status));
                                    #ifndef ALGO
           			 	                sprintf(DBGMSG,"Error en funcion write\n");
            			                log_msg(error,__FILE__,__LINE__,DBGMSG);
        			                #endif
                                    exit = 6;
                                }
                            }
                            else
                            {
                                printf("Error en funcion freed, código de error: %s\n", strerror (status));
                                    #ifndef ALGO
                                        sprintf(DBGMSG,"Error en funcion freed\n");
                                        log_msg(error,__FILE__,__LINE__,DBGMSG);
        			                #endif
                                exit = 5;
                            } 
                        }
				        status = ioctl(sound_card_fd, SOUND_PCM_SYNC, 0);
                        f_time = time(NULL);
                        printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", nombre_cancion, (f_time-i_time)/60, (f_time-i_time)%60);
                    }
                    else
                    {
                        printf("Error en funcion open\n");
                                    #ifndef ALGO
           			 	                sprintf(DBGMSG,"Error en funcion open\n");
            			                log_msg(error,__FILE__,__LINE__,DBGMSG);
        			                #endif
                        exit = 4;
                    }
                }
                else
                {
                    printf("Error en funcion malloc\n");
                                    #ifndef ALGO
           			 	                sprintf(DBGMSG,"Error en funcion malloc\n");
            			                log_msg(error,__FILE__,__LINE__,DBGMSG);
        			                #endif 
                    exit = 3;
                } 
            }
            else
            {
                printf("Error en funcion fopen\n");
                                    #ifndef ALGO
           			 	                sprintf(DBGMSG,"Error en funcion fopen\n");
            			                log_msg(error,__FILE__,__LINE__,DBGMSG);
        			                #endif 
                exit = 2;
            }

    printf("\033[2J");
    /*
    while (!VALID_OP)
    {
        printf("1 - Escuchar nuevamente\n2 - Escuchar otra cancion\n3 - Salir");
        ESPACIO
        scanf("%d", &op);
        switch (op)
        {
        case 1: play(camino_cancion, nombre_cancion);
            break;
        case 2: mostrar_directorios("media");
            break;
        case 3: printf("Adios!\n");
            break;
        default: printf("Opcion invalida\n");
            break;
        }   
    }
    */
    
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Cerrando archivo\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif  
    if(exit > 2)    fclose(audio_file_fd);
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Archivo cerrado\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif 
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Liberando memoria\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
    if(exit > 3)    free(buf);
                                    #ifndef ALGO
                                            sprintf(DBGMSG,"Memoria liberada\n");
                                            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                                    #endif
    if(exit > 4)    close(sound_card_fd);    
    
	return exit;
}

/*Esta funcion sirve como seguimiento de un programa almacenando datos en un archivo separado para que no molesten*/
void log_msg(Nivel_Log nivel, const char* archivo, int linea, const char* mensaje)
{
    FILE *fp;
    time_t tiempo;
    char log_n[20] = {"Valor no valido"};
    
    tiempo = time(NULL);
    /* a+ indica que quiero leer, escribir, crear o usar el ya creado */
    fp = fopen("Datos_Log","a+");
    if(fp != NULL)
    {
        /* Depende el nivel que tome hay que completar el vector teniendo en cuenta 
            que DEBUG=! al char "DEBUG" y si se intenta imprimir imprime 1 */
        switch (nivel)
        {
            case DEBUG: 
                strcpy(log_n,"DEBUG");
                break;
            case INFO:
                strcpy(log_n,"INFO");
                break;
            case WARN:
                strcpy(log_n,"WARN");
                break;
            case error:
                strcpy(log_n,"ERROR");
                break;
            case FATAL:
                strcpy(log_n,"FATAL");
                break;
            default:
                /*Si no eligen ningun valor valido log_n quedara en "valor no valido"*/
                break;
        }
    }
    /*Imprimimos en el archivo fp y no en pantalla todos los datos en orden.*/
    fprintf(fp, "%ld || %s || %s || %d || %s\n\t", tiempo,log_n, archivo,linea,mensaje);

    fclose(fp);
}
