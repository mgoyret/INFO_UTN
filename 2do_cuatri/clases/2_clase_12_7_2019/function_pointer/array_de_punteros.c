



//        ARRAY DE PUNTEROS A FUNCIONES



/*
    brief:      prueba de punteros a funciones, y array de punteros a funciones.
    author:     Marcos Goyret
 */


#include <stdio.h>

/* 1 - Funcion que recibe dos enteros y retorna la suma */
int suma(int a, int b)
{
  printf("Inicio de la funcion suma. Vamos a sumar %d + %d\n", a, b);

  return a + b;
}

int resta(int a, int b)
{
  printf("Inicio de la funcion resta. Vamos a resta %d - %d\n", a, b);

  return a - b;
}

/* 2 - Funcion que recibe un string y no retorna nada */
void saludo(char* nombre)
{
    printf("Inicio de funcion saludo");
    printf("\nHola %s!\n", nombre);
}

int main ()
{
    int a = 0, b = 0, op = 0, res = 0;
    char nombre[15];
    void (*r)(char*); /* 3 - inicializo puntero a funcion que recibe un string y no devuelve nada */
    int (*array[2])(int, int) = {suma, resta}; /* 4 - inicializo array de punteros a funciones que reciben dos int y devuelven un int */

    printf("Como te llamas?:    ");
    scanf("%s", nombre);
    printf("Nombre asignado al string\n");

  /* 5 - al puntero le asigno el valor de la direccion de la funcion, asi el string que le doy al puntero, se los estoy dando a la funcion saludo */
    r = &saludo;
  /* 6 - apunto a la funcion "nombrando" al puntero que la apunta y esta se inicializa. Le envio el string "nombre" */
    (*r)(nombre);

    printf("Inicio del main\n");

    printf("Ingrese opcion:\n0 - sumar\n1 - restar\n");
    scanf("%d", &op);
    printf("Valore asignado a 'op'\n");

    printf("ingrese valor 1\n");
    scanf("%d", &a);
    printf("Valore asignado a 'a'\n");

    printf("ingrese valor 2\n");
    scanf("%d", &b);
    printf("Valore asignado a 'b'\n");

  /* 7 - 'res' es igual a lo que devuelve el puntero que esta en la posicion 'op' del array, apuntando a una funcion, al entregarle 'a' y 'b' */
    res = array[op](a, b);

    printf("Vuelta al main, el resultado es %d\n", res);

    return 0;
}


/*
    Para compilar y linkear:
    gcc array_de_punteros.c -o prog -Wall
 */