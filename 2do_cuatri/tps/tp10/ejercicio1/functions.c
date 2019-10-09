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




/* 1. Definicion de la funcion "add" */

/**
 * \fn      int add(CLIENT** clients, int* user_cnt)
 * \brief   Agrega a un cliente a un array de clientes.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   clients      Array de clientes.
 * \param   user_cnt     Cantidad de clientes en el array.
 * \return  SUCCES o ERROR.
 */
    
int add(CLIENT* clients, int* user_cnt)
{
    int status = ERROR, aux_key;
    char aux_user[NAME_MAX];

    if (user_cnt_max(*user_cnt) == SUCCES)
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Cantidad maxima de clientes alcanzada\n");
        DEFAULT
        SPACE
    }
    else
    {
        while (status == ERROR)
        {
            SPACE
            HIGHLIGHT
            printf("Por favor complete los siguientes datos:");
            DEFAULT
            SPACE
                
            printf("Nombre de usuario:\t");
            scanf("%s", aux_user);

            if(user_check(clients, *user_cnt, aux_user) == SUCCES)
            {
                SPACE
                HIGHLIGHT
                SET_RED
                printf("Nombre de usuario utilizado\n");
                DEFAULT
            }
            else
            {
                strcpy(clients[*user_cnt].user, aux_user);
                printf("Clave numerica:\t\t");
                HIDE
                scanf("%d", &aux_key);
                DEFAULT
                clients[*user_cnt].key = aux_key;

                SPACE
                SET_GREEN
                HIGHLIGHT
                printf("Agregado con exito\n");
                DEFAULT
                SPACE
                (*user_cnt)++;
                status = SUCCES;
            }
        }
    }

    return status;
}

/* 2. Definicion de la funcion "user_check" */

/**
 * \fn      int user_check(CLIENT* clients, int user_cnt, char *aux_user)
 * \brief   Chequea si el nombre deseado ya esta utilizado por algun cliente del array de clientes.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   clients     Array de clientes.
 * \param   user_cnt    Cantidad de clientes en el array.
 * \param   aux_user    Nombre de usuario a comparar.
 */
    
int user_check(CLIENT* clients, int user_cnt, char *aux_user)
{
    int i = 0, status = ERROR;

    for(i = 0; i < user_cnt; i++)
    {
        if (strcmp(clients[i].user, aux_user) == 0)
        {
            status = SUCCES;
        }
    }
    return status;
}


/* 3. Definicion de la funcion "user_cnt_max" */

/**
 * \fn      int user_cnt_max(int user_cnt)
 * \brief   Chequea si ya se alcanzo la cantidad maxima de clientes.
 * \author  Marcos Goyret
 * \date    Sep 30, 2019
 * \param   user_cnt    Cantidad de clientes registrados en el array.
 */
    
int user_cnt_max(int user_cnt)
{
    int status = ERROR;

    if (user_cnt == CLIENT_MAX)
    {
        status = SUCCES;
    }
    return status;
}


/* 4. Definicion de la funcion "bin_write" */

/**
 * \fn      int bin_write(CLIENT *clients, int user_cnt, char *file_name)
 * \brief   Escribe los datos de un array de estructuras de clientes, en un archivo binario.
 * \author  Marcos Goyret
 * \date    Oct 2, 2019
 * \param   clients     Array de clientes.
 * \param   user_cnt    Cantidad de clientes en el array.
 * \param   file_name   Nombre del archivo sobre el cual escribir.
 * \return  SUCCES o ERROR.
 */
    
int bin_write(CLIENT *clients, int user_cnt, char *file_name)
{
    int status = ERROR, i = 0, check = 0;
    FILE* fp = NULL;
    char char_key[INT_MAX];
    
    fp = fopen(file_name, "wb");
    if (fp != NULL)
    {
        SPACE
        SEPARATOR
        SPACE
        printf("Escribiendo archivo '%s' en binario", file_name);
        SPACE
        SEPARATOR
        SPACE

        for (i = 0; i < user_cnt; i++)
        {
            snprintf(char_key, INT_MAX, "%d", clients[i].key);//int to array
            fprintf(fp, "%s,%s\n", clients[i].user, char_key);
            check++;
        }
        if (check == user_cnt)
            status = SUCCES;
        
        fclose(fp);
    }
    else
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Error al abrir/creaer archivo de base de datos");
        DEFAULT
        SPACE
    }
    
    return status;
}


/* 5. Definicion de la funcion "clean_struct" */

/**
 * \fn      int clean_struct(CLIENT* clients, int* user_cnt)
 * \brief   Borra los valores de las estructuras de clientes presentes en un array pasado como parametro.
 * \author  Marcos Goyret
 * \date    Oct 2, 2019
 * \param   clients      Array de clientes.
 * \param   user_cnt     Cantidad de clientes en el array.
 * \return  SUCCES o ERROR.
 */
    
int clean_struct(CLIENT* clients, int* user_cnt)
{
    int status = ERROR, i = 0, cnt_check = *user_cnt;

    SPACE
    SEPARATOR
    SPACE
    printf("Limpiando estructuras");
    SPACE
    SEPARATOR
    SPACE

    for (i = 0; i < *user_cnt; i++)
    {
        memset(clients[i].user, '\0', CLIENT_MAX*sizeof(char));
        clients[i].key = 0;
        cnt_check--;
    }
    if (cnt_check == 0)
        status = SUCCES;

    return status;
}


/* 6. Definicion de la funcion "bin_read" */

/**
 * \fn      int bin_read(CLIENT *clients, int user_cnt, char *file_name)
 * \brief   Llena los valores de estructuras de clientes presentes en un array, con datos obtenidos de un archivo binario.
 * \author  Marcos Goyret
 * \date    Oct 2, 2019
 * \param   clients     Array de clientes.
 * \param   user_cnt    Cantidad de clientes en el array.
 * \param   file_name   Nombre del archivo binario que contiene los datos.
 * \return  SUCCES o ERROR.
 */
    
int bin_read(CLIENT *clients, int user_cnt, char *file_name)
{
    int i = 0, status = ERROR;
    FILE* fp = NULL;
    char *token, line[NAME_MAX+INT_MAX];

    fp = fopen(file_name, "rb");
    if (fp != NULL)
    {
        SPACE
        SEPARATOR
        SPACE
        printf("Copiando archivo '%s' a estructuras nuevamente", file_name);
        SPACE
        SEPARATOR
        SPACE

        for(i = 0; i < user_cnt; i++)
        {
            fgets(line, NAME_MAX+INT_MAX, fp);
            token = strtok(line, ",");
            strcpy(clients[i].user, token);
            token = strtok(NULL, "\n");
            clients[i].key = atoi(token);
        }

        fclose(fp);
    }
    else
    {
        SPACE
        HIGHLIGHT
        SET_RED
        printf("Error al abrir/creaer archivo de base de datos");
        DEFAULT
        SPACE
    }
    

    return status;
}


/* 7. Definicion de la funcion "show_clients" */

/**
 * \fn      int show_clients(CLIENT* clients, int user_cnt)
 * \brief   Imprime en pantalla los valores de las estructuras de clientes presentes en un array.
 * \author  Marcos Goyret
 * \date    Oct 2, 2019
 * \param   clients      Array de clientes.
 * \param   user_cnt     Cantidad de clientes en el array.
 * \return  SUCCES o ERROR.
 */
    
int show_clients(CLIENT* clients, int user_cnt)
{
    int i = 0, status = ERROR;

    SPACE
    HIGHLIGHT
    printf("Lista de clientes:\n");
    DEFAULT
    SPACE
    
    for (i = 0; i < user_cnt; i++)
    {
        printf("Cliente %d\n", i+1);
        printf("Usuario:\t%s\nClave:\t\t%d\n\n", clients[i].user, clients[i].key);
    }
    SPACE
    status = SUCCES;
    
    return status;
}