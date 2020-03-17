



//            PUNTEROS A FUNCIONES


/*
    brief:      prueba de punteros a funciones
    author:     Marcos Goyret
 */


#include <stdio.h>

/* 1 - Funcion que recibe dos enteros y retorna la suma */
int suma(int a, int b)
{
    printf("Inicio de la funcion suma. Vamos a sumar %d + %d\n", a, b);

    return a + b;
}

/* 2 - Funcion que recibe un string y no retorna nada */
void saludo(char* nombre)
{
    printf("Inicio de funcion saludo");
    printf("\nHola %s!\n", nombre);
}


int main ()
{
    int a = 0, b = 0, res = 0;
    int (*p)(int, int); /* 3 - inicializo un puntero a una funcion, que recibe dos enteros y retorna un entero. */
    char nombre[15];
    void (*q)(char*); /* 4 - inicializo puntero a funcion que recibe un string y no devuelve nada */

    printf("Como te llamas?:    ");
    scanf("%s", nombre);
    printf("Nombre asignado al string\n");

  /* 5 - al puntero le asigno el valor de la direccion de la funcion, asi el string que le doy al puntero, se los estoy dando a la funcion saludo */
    q = &saludo;
  /* 6 - apunto a la funcion "nombrando" al puntero que la apunta y esta se inicializa. Le envio el string "nombre" */
    (*q)(nombre);

  /* 7 - al puntero le asigno el valor de la direccion de la funcion, asi los dos enteros que le doy al puntero, se los estoy dando a la funcion suma */
    p = &suma; 
  /* 8 - (p = &sum) = (p = sum). no hace falta el '&' con el nombre de la funcion */

    printf("Inicio del main\n");
    
    printf("ingrese valor 1\n");
    scanf("%d", &a);

    printf("ingrese valor 2\n");
    scanf("%d", &b);

  /* 9 - 'res' es igual a lo que devuelve el puntero a funcion, al entregarle 'a' y 'b' */
    res = (*p)(a, b);
  /* 10 = (*p) = p.  Es quivalente */

    printf("Vuelta al main, el resultado es %d\n", res);

    return 0;
}


/*
    Para compilar y linkear:

    gcc  puntero_simple.o -o prog -Wall
 */