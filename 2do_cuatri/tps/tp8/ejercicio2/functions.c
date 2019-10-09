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
	int tcnt = 0;
    char pal[30];

    rewind(fp);

	while(feof(fp) == 0)
	{
        if (fscanf(fp, "%s", pal) == 1)
  		    tcnt++;
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

int word_cnt(FILE *fp, char argv[2])
{
/* 4. Recibo 'fp' y 'argv[2]' como parámetros de la función y retorno el contenido de 'wcnt' */
    int wcnt = 0, i = 0, j = 0, slen = 0, auxcnt = 0;
    char aux [TAM];

    slen = strlen(argv);
    while(feof(fp)==0)
    {
        fread(aux, sizeof(char), TAM, fp);

        for ( i = 0; i < TAM; i++)
        {
            for(j=0; j<slen; j++)
            {
                if((tolower(aux[i+j])) == (tolower(argv[j])))
                {
                    auxcnt++;
                }
                if(auxcnt == slen)
                    wcnt++; 
            }
            if(i != (TAM-1))    //si diodo termina de escribirce en otro renglon, osea si vencian coincidiendo las letras y se termina el string, no reseteo la variable auxcnt
                auxcnt = 0;
        }
    }
    return wcnt;
}
