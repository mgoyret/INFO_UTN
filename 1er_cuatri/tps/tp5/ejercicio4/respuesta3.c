/*
Dado el vector "int v[5] = {32, 12, 15, 89, 6};" se nos pide acceder al valor 89, (v[3]).
Al indicar "v[3]", nos referimos a la cuarta posicion del vector, que en este caso es 89.
A continuacion accederemos al elemento 3 y modificaremos el valor 89 dentro del vector.
*/

#include <stdio.h>
void main ()
{
    int v[5] = {32, 12, 15, 89, 6};
    
    printf("\nValor inicial de v[3] es %d\n\n", v[3]);
    printf("ingrese nuevo valor\n\n");
    scanf("%d", &v[3]);
    
    printf("\nValor finar de v[3] es %d\n\n", v[3]);
}
/*
para comipalr/linkear/ejecutar:

gcc -c respuesta3.c -o respuesta3.o -Wall
gcc respuesta3.o -o respuesta3 -Wall
./respuesta3 
 */
