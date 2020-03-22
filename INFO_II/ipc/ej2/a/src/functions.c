/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#include "../inc/functions.h"

/**
 * \fn      void build_msg(qmsg* msg, char *line)
 * \brief   Carga el contenido de line, en cada campo de la estructura qmsg
 * \author  Marcos Goyret.
 * \date    Mar 22, 2020
 * \param	msg: Estructura donde se volcara la informacion.
 * \param	line: Linea con informacion separada por comas.
 */

void build_msg(qmsg* msg, char *line)
{
    char *token;

    clean_struct(msg);

    msg->type = MSG;
    
    token = strtok(line, ",");
    strcpy(msg->legajo, token);
    token = strtok(NULL, ",");
    strcpy(msg->area, token);
    
    token = strtok(NULL, ",");
    strcpy(msg->nombre, token);

    token = strtok(NULL, "\n");
    strcpy(msg->apellido, token);

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
    memset(msg->area, '\0', MAX);
    memset(msg->nombre, '\0', MAX);
    memset(msg->apellido, '\0', MAX);
}