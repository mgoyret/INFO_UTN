#include "functions.h"
#include <stdio.h>


int push(NODE** pile, int* len, NODE node)
{
    int status = ERROR;
    NODE* aux;
    
    if (len == 0)
        aux = (NODE*)malloc(sizeof(NODE));
    else
        aux = (NODE*)realloc((*pile), sizeof(NODE)*(*len+1));

    if (aux != NULL)
    {
        (*pile) = aux;

        SPACE
        HIGHLIGHT
        printf("Insertando nodo...");
        DEFAULT
        SPACE

        /* . El valor de la cantidad de usuarios coincide con el valor de la primera posicion vacia del array 'pile' sobre la cual escribir el nuevo usuario */
        strcpy((*pile)[*len].user, node.user);
        (*pile)[*len].key = node.key;
        SET_GREEN
        HIGHLIGHT
        printf("Insertado con exito\n");
        DEFAULT
        SPACE
        (*len)++;
        status = SUCCES;
    }
    else
    {
        SPACE
        SET_RED
        HIGHLIGHT
        printf("Error de memoria");
        DEFAULT
        SPACE
    }   
    return status;
}


int set_temp(NODE *temp_node)
{
    int status = ERROR, aux_key;

    printf("Nombre de usuario:\t");
    scanf("%s", (*temp_node).user);

    printf("Clave numerica:\t\t");
    HIDE
    scanf("%d", &aux_key);
    DEFAULT
    (*temp_node).key = aux_key;

    status = SUCCES;

    return status;
}


int show(NODE* pile, int len)
{
    int i = 0, status = ERROR;

    if (len > 0)
    {
        SPACE
        HIGHLIGHT
        printf("Cantidad de usuarios:   %d\n", len);
        DEFAULT
        SPACE
        for (i = 0; i < len; i++)
        {
            printf("name:\t%s\n", pile[i].user);
            printf("key:\t%d", pile[i].key);
            SPACE
            status = SUCCES;
        }
    }
    else
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Pila vacia\n");
        DEFAULT
        SPACE
    }   
    
    return status;
}


int obtain(NODE* pile, int len, NODE* temp_node)
{
    int status = ERROR;

    if(len > 0)
    {
        strcpy((*temp_node).user, pile[len-1].user);
        (*temp_node).key = pile[len-1].key;
        printf("Usuario:\t%s\nClave:\t\t%d", (*temp_node).user, (*temp_node).key);
        SPACE
        status = SUCCES;
    }
    else
    {
        SPACE
        HIGHLIGHT
        printf("Pila vacia\n");
        DEFAULT
        SPACE
    }

    return status;
}


int pop(NODE** pile, int* len, NODE* temp_node)
{
    int status = ERROR;
    if (*len > 0)
    {
        (*pile) = (NODE*)realloc((*pile), sizeof(NODE)*(*len) - sizeof(NODE));
        (*len)--;
        status = SUCCES;
        SPACE
        HIGHLIGHT
        SET_GREEN
        printf("Usiario eliminado con exito!!\n");
        DEFAULT
        SPACE   
    }
    else
    {
        SPACE
        HIGHLIGHT
        printf("Pila vacia\n");
        DEFAULT
        SPACE
    }

    return status;
}