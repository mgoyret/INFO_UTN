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
    printf("Trata de matarme!!\n");
    
    signal(SIGINT, handler);
    signal(SIGALRM, mi_alarma);

    alarm(TIEMPO_ALARMA);

    while(1);
    printf("CHAU!\n");
    return 0;
}