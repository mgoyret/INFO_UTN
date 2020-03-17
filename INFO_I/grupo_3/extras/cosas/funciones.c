/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret, Felipe Galli, Matias.
 * \date            Ago 02, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "libs/info.h"
#include "libs/funciones.h"

/* 1. Definicion de la funcion "ingresar" */

/**
 * \fn      int ingresar()
 * \brief   Pide usuario y contrasena y chequea que exista el usuario en la base de datos y coincida la contrasena.
 * \author  Marcos Goyret, Felipe Galli, Matias.
 * \date    Ago 02, 2019
 * \return  EXITO/ERROR.
 */

int ingresar ()
{
    char datos_cliente[65], usuario[30], contra[30];
    char *token;
    int status = 0;

    printf("Nombre de usuario:  ");
    scanf("%s", usuario);
    printf("Contrasena:\033[08m  ");
    scanf("%s", contra);
    printf("\033[00m");


    /* 2. Abro archivo */
    status = abrir_archivo("clientes.csv");
    if (status == ERROR)
    {
        printf("\nError al abrir el archivo\n");
        return ERROR;
    }

    /* 3. Busco si existe el usuario, y si la contrasena coincide */
    ir_inicio_archivo();
    do
    {
        status = leer_linea(datos_cliente);
        if (status != ERROR)
        {

            /* 4. En cada linea, guadro la primera palabra hasta la coma (el usuario) en 'token' */
            token = strtok(datos_cliente, ",");
            if((strcmp(usuario, token)) == 0) // '0' = iguales
            {
	            /* 5. Si el usuario coincidio, almaceno la segunda palabra de la linea (contrasena) en token */
                token = strtok(NULL, ",");
                if((strcmp(contra, token)) == 0)
                {
                    printf("\n\033[32m Bienvenido %s!\n\n", usuario);
		    printf("\033[00m");
                    break;
                }
                else
                {
                    printf("\n\033[31m Contrasena incorrecta\n");
                    printf ("\033[00m \n\n");
                    return ERROR;
                }
            }
        }
    } while (status != ERROR);
    if((status == ERROR) && ((strcmp(usuario, token)) != 0))
    {
        printf("\n\033[31m Usuario inexistente\n\n");
        printf ("\033[00m \n\n");
        return ERROR;
    }
    cerrar_archivo();

    return EXITO;
}

/* 6. Definicion de la funcion "registrarse" */

/**
 * \fn      int registrarse()
 * \brief   Pide usuario y contrasena, chequea que no exista previamente el usuario en la base de datos, y lo agrega.
 * \author  Marcos Goyret, Felipe Galli, Matias.
 * \date    Ago 02, 2019
 * \return  EXITO/ERROR.
 */


int registrarse ()
{
    char datos_cliente[65], usuario[30], contra[30];
    char *token,respaldo_usuario[30],resp_datos[65];
    int status = 0,largo=0,i=0;

    printf("Nombre de usuario:  ");
    scanf("%s", usuario);

    // indiferente si el usuario es escrito en mayusculas o minusculas
    largo=strlen(usuario);
    for (i = 0; i < largo; i++)
    {
        respaldo_usuario[i] = tolower(usuario[i]);
    }
    

    status = abrir_archivo("clientes.csv");
    if(status == ERROR)
    {
       printf("\n\\n033[31m Error al abrir el archivo");
       printf ("\033[00m");
        return ERROR;
    }

    /* 7. Busco si usuario existe, mismo metodo que en funcion "ingresar" */
    do
    {
        status = leer_linea(datos_cliente);
        if (status != ERROR)
        {
            token = strtok(datos_cliente, ",");
            largo=strlen(token);
            
            for(i=0;i<largo;i++)
            {
                resp_datos[i] = tolower(token[i]);
            }

            if((strcmp(respaldo_usuario, resp_datos)) == 0) // '0' = iguales
            {
                printf("\n\033[31mNombre de usuario existente.");
		printf ("\033[00m \n\n");
                return ERROR;
            }
        }
    } while (status != ERROR);
    printf("Contrasena:\033[08m  ");
    scanf("%s", contra);
    printf("\033[00m");


    printf("\n\nRegistrando usuario...\n\n");
    /* 8. Inserto el usuario en la linea de texto, luego una coma, y luego la contrasena, respetando el formato '.csv' que se requiere */
    strcpy(datos_cliente, usuario);
    strcat(datos_cliente, ",");
    strcat(datos_cliente, contra);

    status = escribir_linea(datos_cliente);
    if(status == EXITO)
    {
        printf("\033[32mHa sido registrado con exito!\n");
	printf("\033[00m");
    }
    else
    {
        printf("\033[31m Error al registrarce\n");
	printf ("\033[00m \n\n");        
	return ERROR;
    }

    cerrar_archivo();
    return EXITO;
}

/* 9. Definicion de la funcion "salir" */

/**
 * \fn      int salir()
 * \brief   Finaliza el programa.
 * \author  Marcos Goyret, Felipe Galli, Matias.
 * \date    Ago 02, 2019
 * \return  EXITO.
 */


int salir()
{
    printf("\nAdios!\n\n");
    return EXITO;
}

/* 10. Definicion de la funcion "ingresar" */

/**
 * \fn      int ver()
 * \brief   Imprime en pantalla la base de datos que contiene usuarios y claves. (usuario,clave\n)
 * \author  Felipe Galli, Marcos Goyret, Matias.
 * \date    Ago 02, 2019
 * \return  EXITO/ERROR.
 */

int ver()
{
    char datos_cliente[65];
    int status = 0;

    status = abrir_archivo("clientes.csv");
    if(status != ERROR)
    {
        do
        {
            /* 11. Guardo la linea actual en 'datos_cliente', y la imprimo */
            status = leer_linea(datos_cliente);
            if(status != ERROR)
            {
                printf("Linea leida:    %s\n", datos_cliente);
            }
        } while (status != ERROR);
    }
    else
    {
        printf("\n\033[31mError al abrir el archivo\n");
        return ERROR;
    }
    cerrar_archivo();
    return EXITO;
}
