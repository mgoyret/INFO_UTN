/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 21, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    A partir de un archivo separado por comas que contiene los siguientes campos: legajo,area,nombre,apellido	
    Leer el archivo ingresado por línea de comando y cargar la información proveniente del archivo en una cola de mensajes.
    Luego finalizar, indicando error en caso de ocurrir.
*/

#include "functions.h"

int main (char argc, char** argv)
{
    key_t qkey;
    int qid;
    qmsg msg;

    qkey = ftok("/bin/ls", 10);
    if (qkey != -1)
    {
        qid = msgget(qkey, 0600 | IPC_CREAT);
        if (qid != -1)
        {
            
        }
        else
        printf("ERROR [2]")
    }
    else
        printf("ERROR [1]\n");

    return 0;
}