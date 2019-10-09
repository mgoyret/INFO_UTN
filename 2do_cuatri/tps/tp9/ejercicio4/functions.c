/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret.
 * \date            Sep 04, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>


/* 1. Definicion de la funcion "sign_up" */

/**
 * \fn      int sign_up (user** client, int user_cnt);
 * \brief   Agrega un usuario a un array de estructuras de usuarios pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Direccion de la direccion del primer elemento del array de estructuras de usuarios.
 * \param   'user_cnt' cantidad de usuarios registrados.
 * \return  '3' Si pudo registrarse. '-1' en caso contrario.
 */

int sign_up (user** client, int user_cnt)
{
    char name[MAX], key[MAX];
    int status = ERROR;
    user* aux = NULL;

    if (user_cnt == 0)
    {
        aux = (user*)malloc(sizeof(user)*1);
    }
    else
    {
        aux = (user*)realloc((*client), sizeof(user)*(user_cnt+1));
    }
    if (aux != NULL)
    {
        (*client) = aux;
        SPACE
        HIGHLIGHT
        printf("A continuacion comenzara el proceso de registro");
        DEFAULT
        SPACE

        while (status == ERROR)
        {
            printf("Nombre de usuario:\t");
            scanf("%s", name);

            if (NLETTER)
            {
                /* 1.1 Indiferente si el usuario es escrito en mayusculas o minusculas */
                stolower(name);

                /* 1.2 Chequeo si el nombre de usuario esta usado */ 
                if (user_check((*client), name, user_cnt) == ERROR) //user_check devuelve ERROR si no encuentra coincidencia
                {
                    printf("Clave:\t\t\t");
                    HIDE
                    scanf("%s", key);
                    DEFAULT

                    SPACE
                    HIGHLIGHT
                    printf("Registrando usuario...");
                    DEFAULT
                    SPACE

                    /* 1.3 El valor de la cantidad de usuarios coincide con el valor de la primera posicion vacia del array 'cliente' sobre la cual escribir el nuevo usuario */
                    strcpy((*client)[user_cnt].name, name);
                    strcpy((*client)[user_cnt].key, key);
                    (*client)[user_cnt].time = time(NULL);
                    SET_GREEN
                    HIGHLIGHT
                    printf("Registrado con exito\n");
                    DEFAULT
                    SPACE

                    status = ADDITION;   
                }
                else
                {
                    SPACE
                    SET_RED
                    HIGHLIGHT
                    printf("Nombre de usuario utilizado\n");
                    DEFAULT
                    SPACE
                } 
            }
            else
            {   
                SPACE
                SET_RED
                HIGHLIGHT
                printf("El nombre de usuario debe comenzar con una letra");
                DEFAULT
                SPACE
            }
        }
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
    printf("Posicion 1: '%s'\n", (*client)[user_cnt].name);
    return status;
}

/* 2. Definicion de la funcion "sign_in" */

/**
 * \fn      int sign_in(user* client);
 * \brief   Accede a un usuario de un array de estructuras de usuarios pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Direccion de la direccion del primer elemento del array de estructuras de usuarios.
 * \return  '1' Si pudo ingresar. '2' Si se elimino un usuario. '-1' Si no se puedo acceder.
 */

int sign_in(user* client, int user_cnt)
{
    int status = ERROR, psn = 0;
    char name[MAX], key[MAX], op;
    
    SPACE
    HIGHLIGHT
    printf("Por favor ingrese sus datos para acceder");
    DEFAULT
    SPACE

    printf("Nombre de usuario:\t");
    scanf("%s", name);
    
    stolower(name);
    psn = user_check(client, name, (user_cnt));
    if(psn != ERROR)
    {
        printf("Clave:\t\t\t");
        HIDE 
        scanf("%s", key);
        DEFAULT 
        if (strcmp(client[psn].key, key) == 0)
        {
            SPACE
            SET_GREEN
            HIGHLIGHT
            printf("Bienvenido %s!!\n", client[psn].name);
            DEFAULT
            SPACE

            client[psn].time = time(NULL);
            printf("Si desea eliminar esta cuenta ingrese 'Y'\nSi no desea eliminarla, ingrese otra tecla\t\n");
            scanf(" %c", &op);
            if ((op == 'y') || (op == 'Y'))
            {
                if(delete_user(client, psn, user_cnt))
                {
                    SPACE
                    HIGHLIGHT
                    printf("Usuario eliminado exitosamente\n");
                    DEFAULT
                    SPACE
                    status = DELETION;
                }
                else
                {
                    SPACE
                    SET_RED
                    printf("Error al eliminar usuario");
                    DEFAULT
                    SPACE
                    status = ERROR;
                }
            }
            else
            {
                SPACE
                HIGHLIGHT
                printf("Adios %s!!\n", client[psn].name);
                DEFAULT
                SPACE
                status = SUCCES;
            } 
        }
        else
        {
            SPACE
            SET_RED
            HIGHLIGHT
            printf("Clave incorrecta\n");
            DEFAULT
            SPACE
        }
    }else
    {
        SPACE
        SET_RED
        HIGHLIGHT
        printf("Usuario inexistente\n");
        DEFAULT
        SPACE
    }
    
    return status;
}

/* 3. Definicion de la funcion "end" */

/**
 * \fn      int end(user* client);
 * \brief   Imprime mensaje de despedida.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \return  '1'.
 */

int end(user** client, int dummy)
{
    if ((*client) != NULL)
        free(*client);
    SPACE
    HIGHLIGHT
    printf("Fin del programa\n");
    DEFAULT
    SPACE

    return SUCCES;
}

/* 4. Definicion de la funcion "show_data" */

/**
 * \fn      int show_data(user* client);
 * \brief   Imprime datos de usuarios registrados en un array de estructuras de usuarios pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \return  '1'.
 */

int show_data(user* client, int user_cnt)
{
    int i = 0;

    SPACE
    HIGHLIGHT
    printf("Base de datos");
    DEFAULT
    SPACE
    for(i = 0; i < user_cnt; i++)
    {
        if (CLETTER)
        {
            printf("Usuario %d:\nNombre:\t%s\nClave:\t%s\nUltimo acceso:\t%lu", (i+1), client[i].name, client[i].key, client[i].time);
            SPACE
        }
    }
    return SUCCES;
}

/* 5. Definicion de la funcion "stolower" */

/**
 * \fn      int stolower(char* name);
 * \brief   Pasa los caracteres en minuscula de un string pasado como parametro a mayuscula.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'name' String a convertir.
 * \return  '1'.
 */

void stolower(char* name)
{
    int i = 0, slen = strlen(name);
    
    for (i = 0; i < slen; i++)
    {
        name[i] = tolower(name[i]);
    }
}

/* 6. Definicion de la funcion "user_check" */

/**
 * \fn      int user_check(user* client, char* name);
 * \brief   Chequea si existe un determinado usuario en una determinado array de estructuras.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \return  '1'.
 */

int user_check(user* client, char* name, int user_cnt)
{
    int i = 0, position = ERROR;

    for (i = 0; i < user_cnt; i++)
    {
        if (strcmp(client[i].name, name) == 0)
            position = i;
    }
    return position;    //devuelve el numero del elemento del vector en el q coincidio
}

/* 7. Definicion de la funcion "delete_user" */

/**
 * \fn      int delete_user(user* client, int psn);
 * \brief   Elimina un usuario de un array de estructuras pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \param   'psn' Elemento del array que debe eliminarse.
 * \return  '1' si pudo eliminarse. '-1' Si fallo.
 */

int delete_user(user* client, int psn, int user_cnt)
{
    int i = 0, status = ERROR;
    
    for(i = psn; i < (user_cnt-1); i++)
    {
        strcpy(client[i].name, client[i+1].name);
        strcpy(client[i].key, client[i+1].key);
    }
    strcpy(client[user_cnt-1].name, " ");
    strcpy(client[user_cnt-1].key, " ");
    status = SUCCES;

    return status;
}

/* 9. Definicion de la funcion "time_order" */

/**
 * \fn      void time_order(user* client);
 * \brief   Reordena la lista de usuarios, segun fecha de ultimo acceso.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \return  '1'.
 */

void time_order(user* client, int user_cnt)
{
    int i = 0, j = 0, flag = 0;
    char aux_name[MAX], aux_key[MAX];
    unsigned int aux_time = 0;


    for(i = 0; i < (user_cnt-1); i++)
    {
        flag = 1;

        for(j = 0; j < (user_cnt-1-i); j++)
        {
            if (client[j].time < client[j+1].time)
            {
                strcpy(aux_name, client[j+1].name);
                strcpy(aux_key, client[j+1].key);
                aux_time = client[j+1].time;

                strcpy(client[j+1].name, client[j].name);
                strcpy(client[j+1].key, client[j].key);
                client[j+1].time = client[j].time;

                strcpy(client[j].name, aux_name);
                strcpy(client[j].key, aux_key);
                client[j].time = aux_time;

                flag = 0; //solo lo hace si tuvo que swappear alguna vez
            }
        }
        if(flag)   //Si flag = 1 quiere decir que lo recorrio y estaba ordenado ya que nunca swappeo, por lo q no continua el for.        
            break;
    }
}