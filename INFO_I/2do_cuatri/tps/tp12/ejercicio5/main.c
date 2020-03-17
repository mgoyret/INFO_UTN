/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
    int hijos_pedidos = 0;

    printf("Ingrese cantidad de hijos a crear: ");
    scanf("%d", &hijos_pedidos);

    /* 2. Invoco a la función "son_creator", pasándole "hijos_pedidos" como argumento */
    son_creator(hijos_pedidos);

    return 0;
}