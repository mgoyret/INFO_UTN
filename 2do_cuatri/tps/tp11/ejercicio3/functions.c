#include "functions.h"
#include <stdio.h>


int encolar(NODE** cola, int* len, NODE node)
{
    int status = ERROR;
    NODE* aux;
    
    if (len == 0)
        aux = (NODE*)malloc(sizeof(NODE));
    else
        aux = (NODE*)realloc((*cola), sizeof(NODE)*(*len+1));

    if (aux != NULL)
    {
        (*cola) = aux;

        SPACE
        HIGHLIGHT
        printf("Insertando nodo...");
        DEFAULT
        SPACE

        /* . El valor de la cantidad de usuarios coincide con el valor de la primera posicion vacia del array 'cola' sobre la cual escribir el nuevo usuario */
        strcpy((*cola)[*len].user, node.user);
        (*cola)[*len].key = node.key;
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


int desencolar(NODE** cola, int* len, NODE* temp_node)
{
    int i = 0, status = ERROR;

    for(i = 0; i < (*len); i++)
    {
        strcpy((*cola)[i].user, (*cola)[i+1].user);
        (*cola)[i].key = (*cola)[i+1].key;
    }

    (*cola) = (NODE*)realloc((*cola), sizeof(NODE)*(*len) - sizeof(NODE));
    (*len)--;
    status = SUCCES;
    SPACE
    HIGHLIGHT
    SET_GREEN
    printf("Usiario eliminado con exito!!\n");
    DEFAULT
    SPACE   

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


int mostrar(NODE* cola, int len)
{
    int i = 0, status = ERROR;
    SPACE
    HIGHLIGHT
    printf("Cantidad de usuarios:   %d\n", len);
    DEFAULT
    SPACE
    for (i = 0; i < len; i++)
    {
        printf("name:\t%s\n", cola[i].user);
        printf("key:\t%d", cola[i].key);
        SPACE
        status = SUCCES;
    }
    
    return status;
}


int espiar(NODE* cola, int len, NODE* temp_node)
{
    int status = ERROR;

    if(len > 0)
    {
        strcpy((*temp_node).user, cola[len-1].user);
        (*temp_node).key = cola[len-1].key;
        printf("Usuario:\t%s\nClave:\t\t%d", (*temp_node).user, (*temp_node).key);
        SPACE
        status = SUCCES;
    }
    else
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Cola vacia\n");
        SPACE
        DEFAULT
    }

    return status;
}
