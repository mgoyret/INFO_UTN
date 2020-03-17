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
    int op = 1, user_cnt = 0;
    CLIENT clients[CLIENT_MAX];

    SPACE
    HIGHLIGHT
    printf("Bienvenido!\n");
    DEFAULT
    SPACE

    /* 1. El bucle continuara indefinidamente hasta que el usuario indique especificamente que no desea cargar mas datos */
    while(op != 2)
    {   /* 2. Solicito opcion a realizar por consola */
        printf("Desea agregar a otro usuario?\n");
        printf("1 - Si\n2 - No\n");
        SPACE
        scanf("%d", &op);

        switch (op)
        {               /* 3. Invoco a la funcion "add". Pasandole "clients" y "user_cnt" como parametros */
            case 1:     add(clients, &user_cnt);
                break;
            case 2:     /* 4. Invoco a la funcion "show_clients". Pasandole "clients" y "user_cnt" como parametros */
                        show_clients(clients, user_cnt);
                        /* 5. Invoco a la funcion "". Pasandole "clients", "user_cnt" y ""data_base"" como parametros */
                        bin_write(clients, user_cnt, "data_base");
                        /* 6. Invoco a la funcion "clean_struct". Pasandole "clients" y "user_cnt" como parametros */
                        clean_struct(clients, &user_cnt);
                        show_clients(clients, user_cnt);
                        /* .7 Invoco a la funcion "bin_read". Pasandole "clients", "user_cnt" y ""data_base"" como parametros */
                        bin_read(clients, user_cnt, "data_base");
                        show_clients(clients, user_cnt);
                break;
            default:    SPACE
                        HIGHLIGHT
                        SET_RED
                        printf("Opcion invalida\n");
                        DEFAULT
                        SPACE
                break;
        }
    }


    SPACE
    HIGHLIGHT
    printf("Adios!!!\n");
    DEFAULT
    SPACE

    return 0;
}