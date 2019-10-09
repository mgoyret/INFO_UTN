/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 2, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
int main()
{
    float num;
    char op;
    int i, validez;
    float vector[LARGO];

    for(i=0; i<LARGO; i++)  //pido el vector por pantalla
    {
        printf("Ingresa el elemento numero %d del vector: ", (i+1) );
        scanf("%f", &vector[i]);
    }

    printf("Vector ingresado:   ");
    printar(vector, LARGO); //solicito funcion printar que imprime vector pasado como parametro
    printf("indique operacion\n");
    __fpurge(stdin); //para limpiar buffer del teclado
    scanf("%c %f", &op, &num);

    validez = calculo_vector(vector, LARGO, num, op);    //Invoco a la función "calculo_vector", pasándole "vector", "largo", "num" y "op"
                                                         //como argumentos. Almaceno el valor que retorna la función en la variable "validez" */
    if(validez==EXITO)
    {
        printf("El resultado es:    "); //si pudo realizarce la operacion, imprimo el vector resultante en pantalla
        printar(vector, LARGO);
    }
        else
        {
            printf("Dividendo no puede ser 0\n");
        }
        
    return 0;
}