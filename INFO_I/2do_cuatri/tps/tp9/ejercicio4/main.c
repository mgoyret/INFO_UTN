/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 03, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"
#include <stdio.h>

int main()
{
    /* 1. Inicializo array de funciones */
    int op = 0, status = ERROR, user_cnt = 0;
    user* client = NULL;

    printf("Bienvenido!\n");  

    do
    {
        /* 2. Funcin 'time_order' ordena los usuarios del array 'client' segun fecha de ultimo acceso */
        time_order(client, user_cnt);
        printf("Total de usuarios es %d\n", user_cnt);
        printf("Seleccione a continuación la operación que desea realizar:\n1 - Ingresar\n2 - Registrarse\n3 - Ver base de datos\n4 - Salir\n");
        scanf(" %d", &op);
    
        switch (op)
        {
        case SIGNIN:    status = sign_in(client, &user_cnt);
            break;
        case SIGNUP:    status = sign_up(&client, &user_cnt);
            break;
        case SHOW:      status = show_data(client, user_cnt);
            break;
        case END:       status = end(&client);
            break;
        default:        SET_RED HIGHLIGHT SPACE printf("OPCION INVALIDA"); SPACE DEFAULT
            break;
        }
        
    /* 7. El bucle continuara hasta que se ingrese una opcion invalida, o la opcion de finalizacion */
    } while (op != END);

    return status;
}