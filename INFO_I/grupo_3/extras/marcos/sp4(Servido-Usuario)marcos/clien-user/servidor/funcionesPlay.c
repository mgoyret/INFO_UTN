#include "funciones.h"


/*  Definicion de la funcion "mostrar_directorios" */

/**
 * \fn      int mostrar_directorios(char* nombre_dir)
 * \brief   Muestra una lista de las carpetas que contiene mas carpetas con los artistas
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Oct 03, 2019
 * \param	nombre_dir: direccion donde se encuentra la carpeta con los artistas
 * \param	
			
 */

int mostrar_directorios(char* nombre_dir, int clientSocketFd)
{
    DIR* dp;
    int i = 0, salida = EXITO, messageSize = 0;
    struct dirent *dir_entry, *elejida = NULL;
    char artista[30], dir_artista[60];
        #ifndef ALGO
            char DBGMSG[100]
        #endif
        #ifndef ALGO
            sprintf(DBGMSG,"Abriendo directorio\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
    dp = opendir(nombre_dir);
    if (dp != NULL)
    {
            #ifndef ALGO
                sprintf(DBGMSG,"Directorio abierto exitosamente\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif
        while ((dir_entry = readdir(dp)) != NULL)
        {
            /* Muestro solo los directorios (evito los directorios ocultos "." y "..") */
            if ( (dir_entry->d_type == DT_DIR) && (strcmp(dir_entry->d_name,".")!=0) && (strcmp(dir_entry->d_name,"..")!=0) )
            {
                i++;
                send(clientSocketFd, dir_entry->d_name, strlen(dir_entry->d_name)+1, 0); /* 1 */
                usleep(1000);
            }
            send(clientSocketFd, "FIN", 4, 0); /* 1 */
        }
        if(i > 0)
        {
            rewinddir(dp);
            
            messageSize = recv(clientSocketFd, artista, NAME_LEN, 0);  /* 2 */
            if (messageSize>0)
            {
                while ((dir_entry = readdir(dp)) != NULL)
                {   
                    if (dir_entry->d_type == DT_DIR)
                    {   
                        if((strcmp(artista, dir_entry->d_name)) == 0) //si encontro coincidencia con algun nombre, check vale 1, sino, no se encontro ese artista
                        {
                            elejida = dir_entry;
                        }
                    }
                }
                if (elejida != NULL)
                {
                    send(clientSocketFd, "OK", 3, 0);  /* 3 */
                    //printf("Artista elejido: %s",elejida->d_name);
                    sprintf(dir_artista, "%s/%s", nombre_dir, artista); // guardo en 'dir_artista' el path para encontrar al artista
                    mostrar_archivos(dir_artista, clientSocketFd);
                }
                else
                {
                    send(clientSocketFd, "FIN", 4, 0); /* 3 */
                }
            }
            else
            {
                printf("Error en funcion recv /* 2 */\n");
            }
        }
        else
        {
            printf("No se encontraron directorios\n");
            #ifndef ALGO
                sprintf(DBGMSG,"No se encontraron directorios\n");
                log_msg(error,__FILE__,__LINE__,DBGMSG);
            #endif
            salida = ERROR;
        }
    }
    else
    {
        ESPACIO
        ROJO RESALTAR
        printf("Error al abrir directorio %s\n",nombre_dir);
        #ifndef ALGO
            sprintf(DBGMSG,"Error al abrir directorio\n");
            log_msg(error,__FILE__,__LINE__,DBGMSG);
        #endif
        DEFAULT
        ESPACIO
    }
    return salida;
}


/*  Definicion de la funcion "mostrar_archivos" */

/**
 * \fn      int mostrar_archivos(char* dir_artista)
 * \brief   Muestra donde se encuentra el archivo de la cancion y la reproduce
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Oct 03, 2019
 * \param	dir_artista: Direccion donde esta la carpeta del artista elegido
 * \param	
			
 */

int mostrar_archivos(char* dir_artista, int clientSocketFd) //muestra canciones
{
    char cancion[30];
    int i = 0, salida = EXITO, messageSize = 0;
    DIR* dp;
    char camino_cancion[60];
    #ifndef ALGO
        char DBGMSG[100];
    #endif
    struct dirent *dir_entry, *elejida = NULL;
    #ifndef ALGO
        sprintf(DBGMSG,"Abriendo directorio \n");
        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
    #endif                               
    dp = opendir(dir_artista);
    if (dp != NULL)
    {
        #ifndef ALGO
            sprintf(DBGMSG,"Directorio abierto exitosamente \n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif 
        while ((dir_entry = readdir(dp)) != NULL)
        {
            if (dir_entry->d_type != DT_DIR)  // si el punto de entrada no es un directorio
            {
                i++;
                send(clientSocketFd, dir_entry->d_name, 25, 0); /* 4 */ // envio cada nombre de carpeta de artistas
            }
            send(clientSocketFd, "FIN", 4, 0); /* 4 */ //aviso que termino la lista de carpetas
        }
        if(i > 0)
        {
            rewinddir(dp);
            
            messageSize = recv(clientSocketFd, cancion, NAME_LEN, 0); /* 5 */
            if (messageSize > 0)
            {
                while ((dir_entry = readdir(dp)) != NULL)
                {
                    if (dir_entry->d_type != DT_DIR)
                    {
                        if((strcmp(cancion, dir_entry->d_name)) == 0) //si encontro coincidencia con algun nombre, check vale 1, sino, no se encontro esa cancion
                        {
                            elejida = dir_entry;
                        }
                    }
                }
                if (elejida != NULL)
                {
                    send(clientSocketFd, "OK", 3, 0); /* 6 */
                    VERDE
                    printf("\n\nSe reproducira la cancion '%s'\n\n", elejida->d_name);
                    DEFAULT
                    /* No hice sprintf(camino_cancion, "%s/%s", dir_artista, elejida->d_name) porque salia un warning
                        camino_cancion seria el path para llegar a la ubicacion de la cancion */
                    strcpy(camino_cancion, dir_artista);
                    strcat(camino_cancion, "/");
                    strcat(camino_cancion, elejida->d_name);
                                                                
                    /* Aca tengo que en vez de poner este play, enviarde la cancion ubicada en "camino_cancion" al usuario, y que el la reproduzca */
                    
                    //play(camino_cancion, elejida->d_name); 
                }
                else
                {
                    send(clientSocketFd, "FIN", 4, 0); /* 6 */
                    ROJO
                    printf("Cancion no encontrada\n");
                    DEFAULT
                }
            }
            else
            {
                printf("Error en funcion recv /* 5 */\n");
            }
        }
        else
        {
            ROJO
            printf("No se encontraron canciones\n");
            DEFAULT
            salida = ERROR;
        }
        
        closedir(dp);
    }
    else
    {
        ESPACIO
        ROJO RESALTAR
        printf("Error al abrir directorio %s\n",dir_artista);
        DEFAULT
        ESPACIO
    }
    return salida;
}