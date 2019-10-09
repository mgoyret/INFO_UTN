/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 10, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "string_largo" */
 
/**
 * \fn      int string_largo(const char* string)
 * \brief   Devuelve el largo de un string (sin contar el caracter '\0')
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string string ingresado
 * \return  Largo del string (restandole la posicion que contiene a '\0').
 */

int string_largo(const char* string)
/*  Recibo "string" como parámetro de la función y retorno el contenido de "cant" */
{
    int cant = 0;

    while(string[cant]!='\0')   //string[cant] = *(string + cant)
    {
        cant++;
    }
return cant;
}

/* 2. Definicion de la funcion "string_comparar" */

/**
 * \fn      int string_comparar(const char* string1, const char* string2)
 * \brief   Devuelve cero si ambos strings son iguales, y si son distintos, devuelve la diferencia ASCII entre los primeros caracteres distintos.
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string1 string ingresado.
 * \param   string2 string ingresado.
 * \return  diferencia entre caracteres distintos, o '0' si son iguales.
 */

int string_comparar(const char* string1, const char* string2)
/*  Recibo "string1" y "string2" como parámetros de la función y retorno el contenido de "diferencia" */
{
    //int cantp1 = 0, cantp2 = 0;
    int diferencia = 0;
    int i = 0, c = 0;
    int cantp1 = string_largo(string1);
    int cantp2 = string_largo(string2);

    if(cantp1 == cantp2)
    {
        for(i=0; i<cantp1; i++)
        {
            if(string1[i] != string2[i])
            {
                diferencia = string1[i] - string2[i];
            }
            else c++;
        }
        if(c == cantp1) diferencia = 0;
    }
        else
        {
            if(cantp1 < cantp2)
            {
                for(i=0; i<cantp2; i++)
                {
                    if(string1[i] == '\0')
                    {
                        printf("Palabra 1 es mas chica, pero las letras que coinciden son iguales\n");
                        break;
                    }
                    else
                    {
                        if(string1[i] != string2[i])
                        {
                            diferencia = string1[i] - string2[i];
                        }
                    }
                }
            }
            else
            {
                for(i=0; i<cantp1; i++)
                {
                    if(string2[i] == '\0')
                    {
                        printf("Palabra 2 es mas chica, pero las letras que coinciden son iguales\n");
                        break;
                    }
                    else
                    {
                        if(string1[i] != string2[i])
                        {
                            diferencia = string1[i] - string2[i];
                        }
                    }
                }
            }
        }
    return diferencia;
}

/* 3. Definicion de la funcion "string_copiar" */

/**
 * \fn      void string_copiar(char* string_destino, const char* string_origen)
 * \brief   Copia string origen en string destino.
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string_destino string a sobreescribir.
 * \param   string_origen string a copiar.
 */

void string_copiar(char* string_destino, const char* string_origen)
/*  Recibo "string_destino" y "string_origen" como parámetros de la función y no retorno nada */
{
    int i, cant = string_largo(string_origen);
    for ( i = 0; i < cant; i++)
    {
        string_destino[i] = string_origen[i];
    }
    string_destino[i] = '\0';
}

/* 4. Definicion de la funcion "string_concatenar" */

/**
 * \fn      void string_concatenar(char* string_destino, const char* string_origen)
 * \brief   Copia string origen a continuación de string destino.
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string_destino string a prolongar.
 * \param   string_orgen string a copiar.
 */

void string_concatenar(char* string_destino, const char* string_origen)
/*  Recibo "string_destino" y "string_origen" como parámetros de la función y no retorno nada */
{
    int i, cant_o = string_largo(string_origen), cant_d = string_largo(string_destino);
    for ( i = cant_d; i < (cant_d + cant_o); i++)
    {
        string_destino[i] = string_origen[i - cant_d];
    }
    string_destino[i] = '\0';
}


/* 5. Definicion de la funcion "string_mayus" */

/**
 * \fn      void string_mayus(char* string)
 * \brief   Convierte letras minusculas a letras a mayúsculas.
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string string ingresado.
 */

void string_mayus(char* string)
/*  Recibo "string" como parámetro de la función y no retorno nada */
{
    int i = 0, cant = string_largo(string);
    for(i=0;i<cant;i++)
    {
        if(('a' <= string[i]) && (string[i] <= 'z'))
        {
            string[i] -= 32;
        }
    }
}

/* 6. Definicion de la funcion "string_minus" */

/**
 * \fn      void string_minus(char* string)
 * \brief   Convierte letras mayusculas, a letras minusculas.
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string string ingresado.
 */

void string_minus(char* string)
/*  Recibo "string" como parámetro de la función y no retorno nada */
{
    int i = 0, cant = string_largo(string);
    for(i=0;i<cant;i++)
    {
        if(('A' <= string[i]) && (string[i] <= 'Z'))
        {
            string[i] += 32;
        }
    }
}

/* 7. Definicion de la funcion "string_a_float" */

/**
 * \fn      float string_a_float(const char* string)
 * \brief   Convierte un número recibido como string a float.
 * \author  Marcos Goyret
 * \date    Jun 10, 2019
 * \param   string numero ingresado como string.
 * \return  Numero transformado a float.
 */

float string_a_float(const char* string)
/*  Recibo "string" como parámetro de la función y retorno contenido de "suma" */
{
    int i = 0, q = 0, a = 0, pto = 1, cant = string_largo(string);
    float  suma = 0;   //suma llega a tomar valores muy altos, para que no sature la inicializo como double
    printf("el largo es %d\n", cant);
    for(i=(cant-1); i>=0; i--)
    {
        if(string[i] != '.')
        {
            suma += (string[i] - '0') * (pow(10,q));
            q++;
        }
        if(string[i] == '.')
        {
                pto = i;
                a++;  //a = 0, a menos que haya coma
        }   
    }
    suma = suma/(pow(10, (cant - pto -1)*a)); // si no hubo coma, suma = suma / 1 (queda igual)
    
    return suma;
}