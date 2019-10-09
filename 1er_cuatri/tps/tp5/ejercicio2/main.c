/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 3, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
int main()
{
    unsigned int B1, B2, B3, B4, num = 0X12345678;
    unsigned char *p;

    p = (unsigned char*)&num;  //el contenido de p sera la direccion del primer byte de la variable num
    B1 = *p;
    B2 = *(p+1); //la variable se almacena en bytes seguidos, por lo que recorro los bytes incrementando en uno (char = 1 byte) la direccion
    B3 = *(p+2);
    B4 = *(p+3);
    //imprimo en pantalla cada byte con sudireccion
    printf("CONTENIDO   DIRECCION\n");
    printf("%#X        %p\n", B1, p);
    printf("%#X        %p\n", B2, (p+1));
    printf("%#X        %p\n", B3, (p+2));
    printf("%#X        %p\n", B4, (p+3));

    return 0;
}
//ejecutar bash compile.sh para compilar/linkear/ejecutar

/*
RESPUESTAS:

La direccion del byte menos significativo (LSB) del unsigned int se encuentra a tres bytes de distancia de la direccion del MSB

Endianness hace referencia al tipo de orden que se utiliza para almacenar datos de mas de un byte.
Cuando el dato es almacenado ubicando sus bytes de "mayor a menor" ubicando en la direccion mas chica el MSB, y en 
la mas grande el LSB, se dice que es un sistema "big endian". 
Si el dato es almacenado ubicando el LSB en la direccion mas chica, y el MSB en la mas grande, el sistema es "little endian"
*/