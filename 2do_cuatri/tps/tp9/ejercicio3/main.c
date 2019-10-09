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
    int (*functions[4])() = {sign_in, sign_up, show_data, end};
    int op = 0, status = ERROR, user_cnt = 0;
    user client[CNT];

    /* 2. Limpio el archivo ya que al inicio tenia basura */
    clearn_arr(client);
    printf("Bienvenido!\n");  

    do
    {
        /* 3. Funcin 'time_order' ordena los usuarios del array 'client' segun fecha de ultimo acceso */
        time_order(client);
        printf("Total de usuarios es %d\n", user_cnt);
        printf("Seleccione a continuación la operación que desea realizar:\n1 - Ingresar\n2 - Registrarse\n3 - Ver base de datos\n4 - Salir\n");
        scanf(" %d", &op);
        
        /* 4. Decremento 'op' en uno para que su valor concuerde con la posicion de la opcion deseada en el array de funciones */
        op--;

        if (VALID_OP)
        {
            /* 5. Al nombrar una determinada posicion del array de funciones, esa corresponde con el punto de entrada de
            una determinada funcion, y al nombrarla, esta se ejecuta */
            if (op == SIGNUP)
            {
                status = functions[SIGNUP](client, user_cnt);
                if (status == SUCCES)
                    /* 6. Si la funcion sign_up retorna SUCCES, se agrego un usuario */
                    user_cnt++;
            }
            else
            {
                status = functions[op](client);
                if(status == DELETION)
                    /* 7. La unica funcion del array que puede devolver DELETION es la funcion sign_in cuando se elimina un usuario */
                    user_cnt--;
            }
        }
        else
        {
            SPACE
            SET_RED
            printf("Opcion invalida\n");
            DEFAULT
            SPACE
        }
    /* 8. El bucle continuara hasta que se ingrese una opcion invalida, o la opcion de finalizacion */
    } while ((VALID_OP) && (op != END));

    return status;
}