/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 30, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 1. Definicion de la funcion "insert" */

/**
 * \fn      int insert(NODE** client, int* user_cnt, NODE temp_node, int position)
 * \brief   Inserta un nodo en un array de nodos pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \param   temp_node   Nodo a insertar.
 * \param   position    Posicion del array en la cual insertar el nodo.    
 * \return  SUCCES o ERROR.
 */
    
int insert(NODE** client, int* user_cnt, NODE temp_node, int position)
{
    int status = ERROR;
    NODE* aux;
    
    if (position > ((*user_cnt)+1))
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Posicion exede la cantidad de usuarios actual\n");
        DEFAULT
        SPACE
    }
    else if ((position) < 1)
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("La posicion no puede ser menor que '1'\n");
        DEFAULT
        SPACE
    }
    else if (user_taken(*client, *user_cnt, temp_node) == SUCCES)
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Nombre de usuario existente\n");
        DEFAULT
        SPACE
    }
    else
    {
        if (user_cnt == 0)
            aux = (NODE*)malloc(sizeof(NODE));
        else
            aux = (NODE*)realloc((*client), sizeof(NODE)*(*user_cnt+1));

        if (aux != NULL)
        {
            (*client) = aux;

            SPACE
            HIGHLIGHT
            printf("Insertando nodo...");
            DEFAULT
            SPACE

            /* 1.1. *user_cnt+1 porque el array ya tiene un lugar extra vacio */
            insert_order(*client, (*user_cnt+1), position);

            /* 1.2. El valor de la cantidad de usuarios coincide con el valor de la primera posicion vacia del array 'cliente' sobre la cual escribir el nuevo usuario */
            strcpy((*client)[position-1].user, temp_node.user);
            (*client)[position-1].key = temp_node.key;
            SET_GREEN
            HIGHLIGHT
            printf("Insertado con exito\n");
            DEFAULT
            SPACE
            (*user_cnt)++;
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
    }
    return status;
}

/* 2. Definicion de la funcion "delete" */

/**
 * \fn      int delete(NODE** client, int* user_cnt, NODE* temp_node, int position)
 * \brief   Elimina un nodo en un array de nodos pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \param   temp_node   Nodo eliminado.
 * \param   position    Posicion del array a eliminar.
 * \return  SUCCES o ERROR.
 */
    
int delete(NODE** client, int* user_cnt, NODE* temp_node, int position)
{
    int i = 0, status = ERROR;

    if ((position-1) > *user_cnt)
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Posicion exede la cantidad de usuarios actual\n");
        DEFAULT
        SPACE
    }
    else
    {
        /* 2.1. Cargo los valores del nodo a eliminar del array, en un nodo suelto */
        strcpy((*temp_node).user, (*client)[position-1].user);
        (*temp_node).key = (*client)[position-1].key;

        /* 2.2. Desplazo una posicion hacia atras a todos los nodos a partir del siguiente a eliminar */
        for(i = (position-1); i < *user_cnt; i++)
        {
            strcpy((*client)[i].user, (*client)[i+1].user);
            (*client)[i].key = (*client)[i+1].key;
        }
        /* 2.3 El ultimo nodo quedara repetido; Realoco el array restandole una posicion */
        (*client) = (NODE*)realloc((*client), sizeof(NODE)*(*user_cnt) - sizeof(NODE));
        (*user_cnt)--;
        status = SUCCES;
        SPACE
        HIGHLIGHT
        SET_GREEN
        printf("Usiario eliminado con exito!!\n");
        DEFAULT
        SPACE   
    }
    return status;
}

/* 3. Definicion de la funcion "" */

/**
 * \fn      int obtain(NODE* client, int user_cnt, NODE* temp_node, int position)
 * \brief   Carga en un nodo los valores de una determinada posicion de un Array de nodos.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \param   temp_node   Nodo en el cual escribir valores.
 * \param   position    Posicion a copiar.
 * \return  SUCCES o ERROR.
 */
    
int obtain(NODE* client, int user_cnt, NODE* temp_node, int position)
{
    int status = ERROR;

    if (position <= user_cnt)
    {
        strcpy((*temp_node).user, client[position-1].user);
        (*temp_node).key = client[position-1].key;
        printf("Posicion %d\n\nUsuario:\t%s\nClave:\t\t%d", position, (*temp_node).user, (*temp_node).key);
        SPACE
        status = SUCCES;
    }
    else
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Posicion exede cantidad de usuarios");
        DEFAULT
        SPACE
    }
    return status;
}

/* 4. Definicion de la funcion "find" */

/**
 * \fn      int fin(NODE* client, int user_cnt, NODE temp_node, int* position)
 * \brief   Encuentra en que posicion de un array de nodos se encuentra un determinado nodo.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \param   temp_node   Valores del nodo a buscar.
 * \param   position    Variable donde se almacenara la posicion del nodo encontrado.
 * \return  SUCCES o ERROR.
 */
    
int find(NODE* client, int user_cnt, NODE temp_node, int* position)
{
    int i = 0, status = ERROR;

    for(i = 0; i < user_cnt; i++)
    {
        if ((strcmp(client[i].user, temp_node.user) == 0) && (client[i].key == temp_node.key))
        {
            *position = i;
            status = SUCCES;
        }
    }
    if(status != ERROR)
    {
        SPACE
        HIGHLIGHT
        SET_GREEN
        printf("Usuario numero %d\n", *position+1);
        DEFAULT
        SPACE
    }
    else
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Usuario no encontrado, revise nombre y clave\n");
        DEFAULT
        SPACE
    
    }
    return status;
}

/* 5. Definicion de la funcion "show" */

/**
 * \fn      int show(NODE* client, int user_cnt)
 * \brief   Imprime en pantalla los valores de todos los nodos de un array pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \return  SUCCES o ERROR.
 */
    
int show(NODE* client, int user_cnt)
{
    int i = 0, status = ERROR;
    SPACE
    HIGHLIGHT
    printf("Cantidad de usuarios:   %d\n", user_cnt);
    DEFAULT
    SPACE
    for (i = 0; i < user_cnt; i++)
    {
        printf("name:\t%s\n", client[i].user);
        printf("key:\t%d", client[i].key);
        SPACE
        status = SUCCES;
    }
    
    return status;
}

/* 6. Definicion de la funcion "set_temp" */

/**
 * \fn      int set_temp(NODE* temp_node)
 * \brief   Carga valores en un nodo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   temp_npde   Nodo a cargar.
 * \return  SUCCES o ERROR.
 */
    
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

/* 7. Definicion de la funcion "insert_order" */

/**
 * \fn      int insert_order(NODE* client, int user_cnt, int position)
 * \brief   Desplaza los nodos de un array, incrementando en una su posicion, a partir de una determinada posicion.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \param   position    Posicion a partir de la cual desplazar.
 */
    
void insert_order(NODE* client, int user_cnt, int position)
{
    int i = 0;

    for(i = (user_cnt-2); i >= (position-1); i--)
    {
        strcpy(client[i+1].user, client[i].user);
        client[i+1].key = client[i].key;
    }
}


/* 8. Definicion de la funcion "user_taken" */

/**
 * \fn      int user_taken(NODE* client, int user_cnt, NODE temp_node)
 * \brief   Chequea si el nombre deseado ya esta utilizado en algun nodo del array de nodos.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   client      Array de nodos.
 * \param   user_cnt    Cantidad de nodos en el array.
 * \param   temp_node   Nodo a comparar.
 */
    
int user_taken(NODE* client, int user_cnt, NODE temp_node)
{
    int i = 0, status = ERROR;

    for(i = 0; i < user_cnt; i++)
    {
        if (strcmp(client[i].user, temp_node.user) == 0)
        {
            status = SUCCES;
        }
    }
    return status;
}