#include "functions.h"

int add(user **q, char *name, int key, int tam)
{
    user *aux;
    aux = *q;   //para no tener que escribir '*q' cada vez

    aux = (user*)malloc(sizeof(user)*cant);
    if(aux != NULL)
    {
        printf("Ingrese nombre: ");
        scanf("%s", aux[i].name);
        printf("Ingrese clave:  ");
        scanf("%d", &(aux[i].key));

        free(aux);
    }
    else
        printf("Error al pedir memoria\n");
}

/*
    desde el main mando:    add(&p, "marcos", 123, 1);
*/

void show(user **q, int tam)
{
    
}