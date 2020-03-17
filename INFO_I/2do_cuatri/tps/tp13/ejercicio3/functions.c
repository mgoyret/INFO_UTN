/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

/* 1. Definicion de la funcion "msj_check" */

/**
 * \fn      int msj_check(char* str)
 * \brief   Compara un string recibido como parametro, con una serie de palabras establecidas.
 * \author  Marcos Goyret
 * \date    Oct 21, 2019
 * \param   str: String recibido para comparar.
 * \return  status.
 */
    
int msj_check(char* str)
{
    int status = -1;

    if((strcmp(str, "/refran") == 0) || (strcmp(str, "/cancion") == 0) || (strcmp(str, "/pelicula") == 0))
    {
        status = 1;
    }

    return status;
}

/* 2. Definicion de la funcion "choose_messege" */

/**
 * \fn      void send_item(char* buf_recive, char* buf_send)
 * \brief   En base a un string recibido, se elije un string a enviar.
 * \author  Marcos Goyret
 * \date    Oct 21, 2019
 * \param   buf_recive: String recibido.
 * \param   buf_send: String a enviar.
 */
    
void choose_messege(char* buf_recive, char* buf_send)
{

    if (strcmp(buf_recive, "/refran") == 0)
    {
        choose_saying(buf_send);
    }
    else if (strcmp(buf_recive, "/cancion") == 0)
    {
        choose_song(buf_send);
    }
    else if (strcmp(buf_recive, "/pelicula") == 0)
    {
        choose_movie(buf_send);
    }
}

/* 3. Definicion de la funcion "choose_saying" */

/**
 * \fn      void choose_saying(char* buf_send)
 * \brief   Se introduce una frase aleatoria en un string pasado como parametro.
 * \author  Marcos Goyret
 * \date    Oct 21, 2019
 * \param   buf_send: String donde se almacenara la frase.
 */
    
void choose_saying(char* buf_send)
{
    switch (rand_num())
    {
    case 1: strcpy(buf_send, "Cocodrilo que duerme es cartera");
        break;
    case 2: strcpy(buf_send, "La tercera es la vencida");
        break;
    case 3: strcpy(buf_send, "No hay chance que desapruebe INFO 1");
        break;
    default: strcpy(buf_send, "Error en funcion rand_num");
        break;
    }
}

/* 4. Definicion de la funcion "choose_song" */

/**
 * \fn      void choose_song(char* buf_send)
 * \brief   Se introduce una frase aleatoria en un string pasado como parametro.
 * \author  Marcos Goyret
 * \date    Oct 21, 2019
 * \param   buf_send: String donde se almacenara la frase.
 */
    
void choose_song(char* buf_send)
{
    switch (rand_num())
    {
    case 1: strcpy(buf_send, "Stairway to Heaven");
        break;
    case 2: strcpy(buf_send, "Comfortably Numb");
        break;
    case 3: strcpy(buf_send, "We Will Rock You");
        break;
    default: strcpy(buf_send, "Error en funcion rand_num");
        break;
    }
}

/* 5. Definicion de la funcion "choose_movie" */

/**
 * \fn      void choose_movie(char* buf_send)
 * \brief   Se introduce una frase aleatoria en un string pasado como parametro.
 * \author  Marcos Goyret
 * \date    Oct 21, 2019
 * \param   buf_send: String donde se almacenara la frase.
 */
    
void choose_movie(char* buf_send)
{
    switch (rand_num())
    {
    case 1: strcpy(buf_send, "Batman: El Caballero de la Noche");
        break;
    case 2: strcpy(buf_send, "Star Wars: Episodio III");
        break;
    case 3: strcpy(buf_send, "La Lista de Schindler");
        break;
    default: strcpy(buf_send, "Error en funcion rand_num");
        break;
    } 
}

/* 6. Definicion de la funcion "rand_num" */

/**
 * \fn      int rand_num()
 * \brief   Genera un numero aleatorio entre dos valores preestablesidos (1-3).
 * \author  Marcos Goyret
 * \date    Oct 21, 2019
 * \return  random
 */
    
int rand_num()
{
    int random = -1;
    srand(time(NULL));
    
    /* Genera numero aleatorio entre 1 y 3 */                                                  
    random = (rand() % 3) + 1;  

    return random;
}