/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 12, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
    
/* 1. Definicion de la funcion "parsear" */

/**
 * \fn      void parsear(unsigned int cant)
 * \brief   Pide registros, los distribuye en otros string segun tipo de informacion e imprime esos nuevos strings.
 * \author  Marcos Goyret
 * \date    Jun 12, 2019
 * \param   cant cantidad de registros.
  */

void parsear(unsigned int cant)
/* 2. Recibo "cant" como parámetro de la función y no retorno nada */
{
  char registro[100];
  char* token;
  int a = 0;
  char nombre[MAX], apellido[MAX], mail[MAX], pais[MAX], nac[MAX];
  int num;

  while(a<cant)
  {
    scanf("%s", &registro[0]);
    
    //nombre
    token = strtok(registro, ",");
    strcpy(&nombre[0], token);
    printf("\n\nNombre:   %s\n", nombre);

    //Apellido
    token = strtok(NULL, ",");
    strcpy(apellido, token);
    printf("Apellido:   %s\n", apellido);
          
    //nacimiento
    token = strtok(NULL, ",");
    strcpy(nac, token);
    num = atoi(nac);
    printf("Año de nacimiento:   %d\n", num);

    //email
    token = strtok(NULL, ",");
    strcpy(mail, token);
    printf("Email:   %s\n", mail);

    //pais
    token = strtok(NULL, ",");
    strcpy(pais, token);
    printf("Paı́s de origen:   %s\n\n", pais);

    a++;
  }
}