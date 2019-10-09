/*
El vector int v[5] es un vector con 5 elementos, Estos son v[0], v[1],.......v[4]. (Del 0 al 4 hay 5 unidades)
El contenido de v+10 seria el contenido del decimo elemento de v despues del inicial.
Osea que seria el elemento v[10], pero el vector v tiene 5 elementos (del 0 al 4), no 11 elementos (del 0 al 10).
Estariamos tratando de acceder a un elemento no perteneciente a nuestro vector, nos "caeriamos" del vector.
Al compilar y linkear no tendremos mensajes de error, pero el contenido del elemento v+10 sera un valor de una direccion que no 
nos pertenece y que no inicializamos nosotros, distinto cada vez que ejecutamos el programa.
Podemos verlo en el siguiente programa:
*/


#include <stdio.h>
void main ()
{
    int v[5] = {32, 12, 15, 89, 6};
    int a;
    a = *(v+10);

    printf("\nValor de v[10] es %d\n\n", a);
}

/*
para comipalr/linkear/ejecutar:

gcc -c respuesta5.c -o respuesta5.o -Wall
gcc respuesta5.o -o respuesta5 -Wall
./respuesta3 
 */