/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 30, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int op = 0, status = ERROR, position = 0, user_cnt = 0;
    NODE temp_node, *client = NULL;

    printf("Bienvenido!\n");

    do
    {   /* 1. Solicito opcion a realizar por consola */
        printf("Seleccione a continuación la operación que desea realizar:\n1 - Insertar\n2 - Eliminar\n3 - Obtener datos\n4 - Encontrar\n5 - Mostrar\n6 - Fin");
        SPACE
        scanf(" %d", &op);
        
        /* . 2. Decremento 'op' en uno para que su valor concuerde con la posicion de la opcion deseada en el array de funciones */
        op--;

        switch (op)
        {
            case INSERT:    printf("Posicion en la cual insertar el nodo:\t");
                            scanf("%d", &position);
                            SPACE
                            set_temp(&temp_node);
                            /* 3. Invoco a la función "insert", pasándole "client", "user_cnt", "temp_node" y "position" como argumentos.
                                Almaceno el valor que retorna la función en la variable "status" */
                            status = insert(&client, &user_cnt, temp_node, position);
                break;

            case DELETE:    printf("Posicion a borrar:\t");
                            scanf("%d", &position);
                            /* 4. Invoco a la función "delete", pasándole "client", "user_cnt", "temp_node" y "position" como argumentos.
                                Almaceno el valor que retorna la función en la variable "status" */
                            status = delete(&client, &user_cnt, &temp_node, position);

                break;
                
            case OBTAIN:    printf("Obtener datos de posicion:\t");
                            scanf("%d", &position);
                            /* 5. Invoco a la función "obtain", pasándole "client", "user_cnt", "temp_node" y "position" como argumentos.
                                Almaceno el valor que retorna la función en la variable "status" */
                            status = obtain(client, user_cnt, &temp_node, position);
                break;
                
            case FIND:      /* 6. Invoco a la función "set_temp", pasándole "temp_node" como argumento. */
                            set_temp(&temp_node);
                            /* 7. Invoco a la función "find", pasándole "client", "user_cnt", "temp_node" y "position" como argumentos.
                                Almaceno el valor que retorna la función en la variable "status" */
                            status = find(client, user_cnt, temp_node, &position);
                break;
                
            case SHOW:      /* 8. Invoco a la función "show", pasándole "client" y "user_cnt" como argumentos.
                                Almaceno el valor que retorna la función en la variable "status" */
                            status = show(client, user_cnt);
                break;

            case END:       SPACE
                            HIGHLIGHT 
                            printf("Fin del programa\n"); 
                            DEFAULT
                            SPACE
                break;
            
            default:        SPACE
                            HIGHLIGHT
                            SET_RED
                            printf("Opcion invalida\n");
                            DEFAULT
                            SPACE
                break;
        }

    /* 9. El bucle continuara hasta que se ingrese la opcion de finalizacion */
    } while (op != END);

    return status;
}