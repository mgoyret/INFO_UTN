/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 10, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

int main ()
{
    int op = 0;
    char string1[MAX], string2[MAX];
    int  cant1 = 0, diferencia = 0;

    /* 1. Solicito string por consola */
    printf("Cargar palabra 1, o numero (en caso de desear transformarlo a float):  \n");
    scanf("%s", string1);

    printf("1. Largo del string\n2. Comparar strings\n3. Copiar string sobrescribiendo\n4. Copiar a continuacion\n5. A mayusculas\n6. A minusculas\n7. Numero string a float\n\n");
    scanf("%d", &op);
    switch (op)
    {
        case 1:
        {
            /* 2. Invoco a la función "string_largo", pasándole "string1" como argumento.
        Almaceno el valor que retorna la función en la variable "cant1" */
            cant1 = string_largo(string1);
            printf("El largo del string 1 es %d\n", cant1); //imprimo largo del string
        }
            break;
        case 2:
        {
            /* 3. Solicito string por consola */
            printf("Cargar palabra 2:  \n");
            scanf("%s", string2);
            /* 4. Invoco a la función "string_comparar", pasándole "string1" y "string2" como argumentos.
        Almaceno el valor que retorna la función en la variable "diferencia" y la imprimo en pantalla*/
            diferencia = string_comparar(string1, string2);
            printf("diferencia de primer letra distinta es %d\n", diferencia);
        }
            break;
        case 3:
        {
            /* 5. Invoco a la función "string_copiar", pasándole "string1" y "string2" como argumentos. */
            string_copiar(string2, string1);
            printf("String 1 (origen) es %s, y se copio en string2 (destino), que ahora es %s\n", string1, string2); //imprimo strings obtenidos
        }
            break;
        case 4:
        {
            /* 6. Solicito string por consola */
            printf("Cargar palabra 2:  \n");
            scanf("%s", string2);
            /* 7. Invoco a la función "string_conectar", pasándole "string1" y "string2" como argumentos. */
            string_concatenar(string1, string2);
            printf("Ambas palabras juntas quedan:   %s\n", string1);    //imprimo string obtenido
        }
            break;
        case 5:
        {
            /* 8. Invoco a la función "string_mayus", pasándole "string1" como argumento. */
            string_mayus(string1);
            printf("El string en mayusculas es %s\n", string1); //imprimo string obtenido
        }
            break;
        case 6:
        {
            /* 9. Invoco a la función "string_minus", pasándole "string1" como argumento. */
            string_minus(string1);
            printf("El string en minusculas es %s\n", string1); //imprimo string obtenido
        }
            break;
        case 7:
        {
            /* 4. Invoco a la función "string_a_float", pasándole "string1" como argumento.
        Almaceno el valor que retorna la función en la variable "num" */
            float num = string_a_float(string1);
            printf("El numero es %f\n", num);   //imprimo numero float obtenido
        }
            break;
        default:    printf("Opcion invalida\n");
            break;
    }

    return 0;
}