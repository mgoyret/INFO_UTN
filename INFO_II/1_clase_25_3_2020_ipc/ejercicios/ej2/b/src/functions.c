/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#include "../inc/functions.h"

/**
 * \fn      int area_check(char *line, char *area)
 * \brief   Verifica si la informacion en "line" pertenece al area "area"
 * \author  Marcos Goyret
 * \date    Mar 22, 2020
 * \param	line: Linea obtenida del archivo fuente
 * \param	area: Area que se desea verificar si coincide con el area de la linea actual
 */

int area_check(char *line, char *area)
{
    int exit = 0;
    char *token, auxline[TOTAL];

    memset(auxline, '\0', TOTAL);
    strcpy(auxline, line);
    token = strtok(auxline, ",");
    token = strtok(NULL, ",");

    if(!strcmp(area, token))
        exit = 1;

    return exit;
}

/**
 * \fn      void set_line(char *line, FILE* fp2)
 * \brief   Escribe nueva linea en el nuevo arhcivo
 * \author  Marcos Goyret
 * \date    Mar 22, 2020
 * \param	line: Linea obtenida del archivo fuente
 * \param	fp2:  Puntero al nuevo archivo donde se almacena la informacion deseada 
 */

void set_line(char *line, FILE* fp2)
{
    char apellido[MAX], nombre[MAX], legajo[9];

    /* 1. Limpio strings para aseegurar que no tengan basura */
    memset(nombre, '\0', MAX);
    memset(apellido, '\0', MAX);
    memset(legajo, '\0', 9);


    strcpy(legajo, strtok(line, ","));
    strtok(NULL, ",");
    strcpy(nombre, strtok(NULL, ","));
    strcpy(apellido, strtok(NULL, "\n"));

    apellido[0] = toupper(apellido[0]);
    nombre[0] = toupper(nombre[0]);

    fprintf(stdout, "Escribiendo linea [%s-%s-%s]\n", apellido, nombre, legajo);
    fprintf(fp2, "%s-%s-%s\n", apellido, nombre, legajo);
}

/**
 * \fn      void clean_struct(qmsg* msg)
 * \brief   Setea cada campo de la estructura "msg" en '0' (int), y '\0' (char)
 * \author  Marcos Goyret.
 * \date    Mar 22, 2020
 * \param	msg: Estructura a limpiar
 */

void clean_struct(qmsg* msg)
{
    msg->type = 0;
    memset(msg->legajo, '\0', MAX);
    msg->area = 0;
    memset(msg->nombre, '\0', MAX);
    memset(msg->apellido, '\0', MAX);
}