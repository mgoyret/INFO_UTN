/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define TAM 100
typedef enum nivel_log
{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
}nivel_log;

void log_msg(nivel_log nivel, const char* archivo, int linea, const char* mensaje);