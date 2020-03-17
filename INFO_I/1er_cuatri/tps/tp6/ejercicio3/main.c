/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 14, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

int main ()
{
  unsigned int cant;

  /* 1. Solicito cantidad de registros a ingresar por consola */
  printf("Indique cantidad de registros\n");
  scanf("%d", &cant);
  printf("Ingrese los %d registros\n", cant);
  
  /* 2. Invoco a la función "parsear", pasándole "cant" como argumento. */
  parsear(cant);

  return 0;
}
