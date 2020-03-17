
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
    #ifndef ALGO
	    char DBGMSG[100];
    #endif
    
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