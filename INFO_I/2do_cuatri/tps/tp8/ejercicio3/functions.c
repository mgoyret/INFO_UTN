/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Ago 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"
#include <stdio.h>
#include <time.h>

/* 1. Definicion de la funcion "log_msg" */

/**
 * \fn      void log_msg(nivel_log nivel, const char* archivo, int linea, const char* mensaje);
 * \brief   Crea un archivo log donde se guarda un historial de los procesos de un programa pasados como parametros
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'nivel' Clasificacion del mensaje segun importancia
 * \param   'archivo' Archivo desde el cual se emitio el mensaje log 
 * \param   'linea' Linea del archivo desde la cual se emitio el mensaje log
 * \param   'mensaje' Mensaje emitido sobre lo sucedido
 */
    
void log_msg(nivel_log nivel, const char* archivo, int linea, const char* mensaje)
{
    FILE *fp;
    time_t seg = time(NULL);
    char str[10];

    fp = fopen("logfile", "a+");
    if(fp != NULL)
    {
        switch (nivel)
        {
        case INFO: strcpy(str, "INFO");
            break;
        case DEBUG: strcpy(str, "DEBUG");
            break;
        case WARN: strcpy(str, "WARN");
            break;
        case ERROR: strcpy(str, "ERROR");
            break;
        case FATAL: strcpy(str, "FATAL");
            break;
        default:
            break;
        }
        
        fprintf(fp, "%ld\t%s\t%s:%d:\t%s\n", seg, str, archivo, linea, mensaje);
        fclose(fp);
    }
    else
    {
        printf("Error al abrir archivo logfile");
    }
}