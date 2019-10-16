/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 16, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
    int op;
    void (*funciones[3])() = {ok_process, zombie, orphan};

    printf("Crear:\n1 - Proceso correcto\n2 - Proceso zombie\n3 - Proceso huerfano\n4 - Salir\n");
    scanf("%d", &op);

    /* 1. Segun la opcion seleccionada, se inicializa una determinada funcion del vector de funciones */
    if ((op == 1) || (op == 2) || (op == 3))
    {
        funciones[op-1]();
    }
    else if (op == 4)
    {
        printf("CHAU!\n");
    }
    else
    {
        printf("Opcion invalida\n");
    }
    
    return 0;
}