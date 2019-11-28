/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <string.h>
#include "functions.h"

/* 1. Definicion de la funcion "leer_linea" */

/**
 * \fn      int leer_linea(FILE* fp, char* linea);
 * \brief   Lee linea actual de un archivo pasado como parametro
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'fp' Puntero a archivo
 * \param   'linea' String donde se almacenara la linea leida
 * \return  EXITO(0) | ERROR(-1)
 */
    
int leer_linea(FILE* fp, char* line)
/* 2. Recibo 'fp' y 'linea' como parámetros de la función y retorno el contenido de 'status' */
{
    int status = ERROR;

    if (fgets(line, TAM, fp) != NULL)//fgets lee hasta '\n' y devuelve con '\0' */
    {
        line[strlen(line)-1] = '\0'; //borro el \n que esta en la ultima posicion
        status = EXITO;   
    }

    return status;
}

/* 3. Definicion de la funcion "escribir_linea" */

/**
 * \fn      int esribir_linea(FILE* fp, const char* linea);
 * \brief   
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'fp' Puntero a archivo
 * \param   'linea' String donde se almacenara 
 * \return  EXITO(0) | ERROR(-1)
 */

int escribir_linea(FILE* fp, const char* line)
{
    /* 4. Recibo 'fp' y 'linea' como parámetros de la función y retorno el contenido de 'status' */
    int  status = ERROR;

    if (fputs(line, fp) != EOF)
    {   /* fputs copia un string SIN el '\0' */
        fputc('\n', fp);
        fflush(fp);
        status = EXITO;
    }
    return status;
}