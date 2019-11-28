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
 * \fn      int sign_up (user* client, int user_cnt);
 * \brief   Agrega un usuario a un array de estructuras de usuarios pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \param   'user_cnt' cantidad de usuarios registrados.
 * \return  '1' Si pudo registrarce. '-1' en caso contrario.
 */

int sign_up (user* client, int* user_cnt)
{
    char name[MAX], key[MAX];
    int status = ERROR; 

    if (*user_cnt < CNT)
    {   
        HIGHLIGHT SPACE
        printf("A continuacion comenzara el proceso de registro");
        DEFAULT SPACE

        while (status == ERROR)
        {
            printf("Nombre de usuario:\t");
            scanf("%s", name);

            if (NLETTER)
            {
                /* indiferente si el usuario es escrito en mayusculas o minusculas */
                stolower(name);

                /* chequeo si el nombre de usuario esta usado */ 
                if (user_check(client, name) == ERROR) //user_check devuelve ERROR si no encuentra coincidencia
                {
                    printf("Clave:\t\t\t");
                    HIDE
                    scanf("%s", key);
                    DEFAULT

                    SPACE HIGHLIGHT
                    printf("Registrando usuario...");
                    SPACE DEFAULT

                    /* El valor de la cantidad de usuarios coincide con el valor de la primera posicion vacia del array 'cliente' sobre la cual escribir el nuevo usuario */
                    strcpy(client[*user_cnt].name, name);
                    strcpy(client[*user_cnt].key, key);
                    client[*user_cnt].time = time(NULL);

                    HIGHLIGHT SET_GREEN
                    printf("Registrado con exito\n");
                    DEFAULT SPACE

                    *user_cnt += 1;
                    status = SUCCES;   
                }
                else
                {
                    SPACE SET_RED HIGHLIGHT
                    printf("Nombre de usuario utilizado\n");
                    SPACE DEFAULT
                } 
            }
            else
            {   
                SPACE HIGHLIGHT SET_RED
                printf("El nombre de usuario debe comenzar con una letra");
                SPACE DEFAULT
            }
        }
    }
    else
    {  
        SPACE SET_RED HIGHLIGHT
        printf("Base de datos llena");
        SPACE DEFAULT
    }
    return status;
}

/* 2. Definicion de la funcion "sign_in" */

/**
 * \fn      int sign_in(user* client);
 * \brief   Accede a un usuario de un array de estructuras de usuarios pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 * \return  '1' Si pudo ingresar. '2' Si se elimino un usuario. '-1' Si no se puedo acceder.
 */

int sign_in(user* client, int* user_cnt)
{
    int status = ERROR, psn = 0;
    char name[MAX], key[MAX], op;
    
    SPACE HIGHLIGHT
    printf("Por favor ingrese sus datos para acceder");
    SPACE DEFAULT

    printf("Nombre de usuario:\t");
    scanf("%s", name);

    stolower(name);
    psn = user_check(client, name);
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
                if(delete_user(client, psn))
                {
                    *user_cnt -= 1;
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
                printf("Ingrese cualquier tecla para salir\n");
                scanf(" %*c"); // %*c no asigna la opcion a ninguna variable
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

int end()
{
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

int show_data(user* client)
{
    int i = 0;

    SPACE
    HIGHLIGHT
    printf("Base de datos");
    DEFAULT
    SPACE
    for(i = 0; i < CNT; i++)
    {
        if (CLETTER)
        {
            printf("Usuario %d:\nNombre:\t%s\nClave:\t%s\nUltimo acceso:\t%u", (i+1), client[i].name, client[i].key, client[i].time);
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

int user_check(user* client, char* name)
{
    int i = 0, position = ERROR;

    for (i = 0; i < CNT; i++)
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

int delete_user(user* client, int psn)
{
    int i = 0, status = ERROR;
    
    for(i = psn; i < (CNT-1); i++)
    {
        strcpy(client[i].name, client[i+1].name);
        strcpy(client[i].key, client[i+1].key);
    }
    strcpy(client[CNT-1].name, " ");
    strcpy(client[CNT-1].key, " ");
    status = SUCCES;

    return status;
}

/* 8. Definicion de la funcion "clear_arr" */

/**
 * \fn      int clear_arr(user* client);
 * \brief   Inicializa los elementos de un array de estructuras de usuarios pasado como parametro.
 * \author  Marcos Goyret
 * \date    Sep 03, 2019
 * \param   'client' Array de estructuras de usuarios.
 */

void clearn_arr(user* client)
{
    int i = 0;

    for(i = 0; i < CNT; i++)
    {
        memset(client[i].name, '\0', MAX);
        memset(client[i].key, '\0', MAX);
        client[i].time = 0;
    }
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

void time_order(user* client)
{
    int i = 0, j = 0, flag = 0;
    user aux;


    for(i = 0; i < (CNT-1); i++)
    {
        flag = 1;

        for(j = 0; j < (CNT-1-i); j++)
        {
            if (client[j].time < client[j+1].time)
            {
                aux = client[j+1];
                client[j+1] = client[j];
                client[j] = aux;

                flag = 0; //solo lo hace si tuvo que swappear alguna vez
            }
        }
        if(flag)   //Si flag = 1 quiere decir que lo recorrio y estaba ordenado ya que nunca swappeo, por lo q no continua el for.        
            break;
    }
}