/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* 1. Definicion de la funcion "letra" */

/**
 * \fn      int letra(char* aux)
 * \brief   Analiza si un string pasado como parametro contiene al menos un caracter que no sea una letra.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'aux' String a analizar.
 * \return  '1' Si es un string compuesto unicamente por letras, '0' en caso contrario.
 */

int letra(char* aux)
{
    int i = 0, slen = 0, status = 1;
    
    slen = strlen(aux);
    for (i=0; i<slen; i++)
        if (!LETRA)
            status = 0;
    
    return status;
}

/* 2. Definicion de la funcion "fin" */

/**
 * \fn      int fin(const char* pal)
 * \brief   Analiza si un string pasado como parametro coincide con una palabra determinada palabra.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'pal' Array de estructuras string.
 * \return  '1' si coinciden las palabras; '0' si no coinciden.
 */

int fin(const char* pal)
{
    int slen = 0, status = 0, i = 0;
    char aux[TAM];

    slen = strlen(pal);
    strcpy(aux, pal);

    for (i=0; i<slen; i++)
        aux[i] = tolower(aux[i]);

    if (strcmp(aux, "fin") == 0)
    {
        status = 1;
    }
    
    return status;
}


/* 3. Definicion de la funcion "stolower" */

/**
 * \fn      void stolower(char* aux)
 * \brief   Convierte todas las letras mayusculas de un string en minusculas.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'aux' String a convertir.
 */

void stolower(char* aux)
{
    int i = 0, slen = 0;

    slen = strlen(aux);
    for (i=0; i<slen; i++)
    {
        aux[i] = tolower(aux[i]);
    }
}


/* 4. Definicion de la funcion "ordenar" */

/**
 * \fn      void ordenar(string* pal, int q)
 * \brief   Ordena lexicograficamente strings contenidos en una cadena de estructuras string pasada como parametro.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'pal' Estructura string a ordenar.
 * \param   'q' Cantidad de strings a ordenar.
 */

void ordenar(string* pal, int q)
{
    int i = 0, j = 0;
    char aux[TAM];

    for (i=0; i<(q-1); i++)
    {
        for(j=0; j<(q-i-1); j++)
        {
            if (strcmp(pal[j].spal, pal[j+1].spal) > 0)
            {
                strcpy(aux, pal[j].spal);
                strcpy(pal[j].spal, pal[j+1].spal);
                strcpy(pal[j+1].spal, aux);
            }
        }
    }
}
/*
    ESTE ESTA CORREGIDO
void ordenar(string* pal, int q)
{
    int i = 0, j = 0;
    string aux;

    for (i=0; i<(q-1); i++)
    {
        for(j=0; j<(q-i-1); j++)
        {
            if (strcmp(pal[j].spal, pal[j+1].spal) > 0)
            {
                aux = pal[j];
                pal[j] = pal[j+1];
                pal[j+1] = pal[j];
            }
        }
    }
}
*/