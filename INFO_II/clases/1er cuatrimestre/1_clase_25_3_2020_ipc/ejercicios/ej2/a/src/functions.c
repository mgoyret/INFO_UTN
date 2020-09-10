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
    
    token = strtok(line, ",");
    strcpy(msg->legajo, token);
    token = strtok(NULL, ",");
    msg->area = atoi(token);
    
    token = strtok(NULL, ",");
    strcpy(msg->nombre, token);

    token = strtok(NULL, "\n");
    strcpy(msg->apellido, token);

    /* Al sumarle '1' me aseguro que ningun msg.type sera 1 ya que ningun area vale 0. Asi, el msg.type 1
        queda reservado para el fin de cola */
    msg->type = (long)msg->area + 1;
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
    /* El type nunca debe ser negativo, pero esto es solo para limpiar la estructura
        Al llegar cualquier mensaje, el type se modificara a un numero mayor o igual que 0 */
    msg->type = -1; 
    memset(msg->legajo, '\0', MAX);
    msg->area = 0;
    memset(msg->nombre, '\0', MAX);
    memset(msg->apellido, '\0', MAX);
}