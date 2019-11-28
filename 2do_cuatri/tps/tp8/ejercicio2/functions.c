/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

/* 1. Definicion de la funcion "total_cnt" */

/**
 * \fn      int total_cnt(FILE* fp);
 * \brief   Calcula cantidad total de palabras de un archivo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'fp' Puntero a archivo.
 * \return  Cantidad total de palabras.
 */

int total_cnt(FILE *fp)
{
/* 2. Recibo 'fp' como parametro de la función y retorno el contenido de 'tcnt' */
	int tcnt = 0, vueltas = 0, i = 0;
    char c, *buff = NULL;

    rewind(fp);

	while(!feof(fp))
	{
        c = fgetc(fp);
        if (c != EOF)
        {
            if(vueltas == 0)
            {
                buff = (char*)malloc(++vueltas);
            }
            else if(vueltas > 0)
            {
                buff = (char*)realloc(buff, ++vueltas);
            }
            if((c > 64) && (c < 91))
            {
                c += 32;
            }

            buff[vueltas-1] = c;
        }
	}
    for (i = 0; i < strlen(buff); i++)
    {
        if((buff[i] != ' ') && (buff[i] != '.') && (buff[i] != '-') && (buff[i] != ';') && (buff[i] != ':') && (buff[i] != '\n') && (buff[i] != ',') && (buff[i] != EOF))
            if((buff[i+1] == ' ') || (buff[i+1] == '.') || (buff[i+1] == '-') || (buff[i+1] == ';') || (buff[i+1] == ':') || (buff[i+1] == '\n') || (buff[i+1] == ',') || (buff[i+1] == EOF))
            {
                printf("i:\t'%c'\ni+1:\t'%c'\n", buff[i], buff[i+1]);
                tcnt++;
            }
    }
	return tcnt;
}

/* 3. Definicion de la funcion "word_cnt" */

/**
 * \fn      int word_cnt(FILE* fp);
 * \brief   Calcula cantidad de veces que aparece una palabra pasada como parametro, en un archivo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'fp' Puntero a archivo.
 * \param   'argv[2]' Palabra a buscar
 * \return  Cantidad de veces que aparecio la palabra.
 */

int word_cnt(FILE *fp, char* argv)
{
/* 4. Recibo 'fp' y 'argv[2]' como parámetros de la función y retorno el contenido de 'wcnt' */
    int wcnt = 0, i = 0, j = 0, slen = 0, bufflen = 0, auxcnt = 0, vueltas = 0;
    char c, *buff = NULL;

    while(!feof(fp))
    {
        c = fgetc(fp);
        if (c != EOF)
        {
            if(vueltas == 0)
            {
                buff = (char*)malloc(++vueltas);
            }
            else if(vueltas > 0)
            {
                buff = (char*)realloc(buff, ++vueltas);
            }
            if((c > 64) && (c < 91))
            {
                c += 32;
            }

            buff[vueltas-1] = c;
        }
    }
    slen = strlen(argv);
    bufflen = strlen(buff);
    printf("argv = %s\nbuff = %s\n", argv, buff);
    for (i=0; i<bufflen; i++)
    {
        for(j=0; j<slen; j++)
        {
            if(buff[i+j] == tolower(argv[j]))
            {
                auxcnt++;
            }
            if(auxcnt == slen)
            {
                wcnt++;
            }
        }
        auxcnt = 0;
    }


    return wcnt;
}
