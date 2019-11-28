/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include "functions.h"
#include <stdio.h>
#include <math.h>

/* 1. Definicion de la funcion "complejo_suma" */

/**
 * \fn      complejo complejo_suma(const complejo x, const complejo y)
 * \brief   Calcula la suma de dos numeros complejos pasados como parametros.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Primer numero complejo.
 * \param   'y' Segundo numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

complejo complejo_suma(const complejo x, const complejo y)
{
    complejo res;

    res.real = a + c;
    res.imag = b + d;

    return res;
}

/* 2. Definicion de la funcion "complejo_resta" */

/**
 * \fn      complejo complejo_resta(const complejo x, const complejo y)
 * \brief   Calcula la resta de dos numeros complejos pasados como parametros.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Primer numero complejo.
 * \param   'y' Segundo numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

complejo complejo_resta(const complejo x, const complejo y)
{
    complejo res;

    res.real = a - c;
    res.imag = b - d;

    return res;
}

/* 3. Definicion de la funcion "complejo_multiplicacion" */

/**
 * \fn      complejo complejo_multiplicacion(const complejo x, const complejo y)
 * \brief   Calcula el producto entre dos numeros complejos pasados como parametros.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Primer numero complejo.
 * \param   'y' Segundo numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

complejo complejo_multiplicacion(const complejo x, const complejo y)
{
    complejo res;

    res.real = (a*c) - (b*d);
    res.imag = (a*d) + (b*c);

    return res;
}

/* 4. Definicion de la funcion "complejo_division" */

/**
 * \fn      complejo complejo_division(const complejo x, const complejo y)
 * \brief   Calcula el cociente entre dos numeros complejos pasados como parametros.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Primer numero complejo.
 * \param   'y' Segundo numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

complejo complejo_division(const complejo x, const complejo y)
{
    complejo res;

    res.real = ((a*c)+(b*d)) / (pow(c, 2)+pow(d, 2));
    res.imag = ((b*c)-(a*d)) / (pow(c, 2)+pow(d, 2));
    
    return res;
}

/* 5. Definicion de la funcion "complejo_conjugado" */

/**
 * \fn      complejo complejo_conjugado(const complejo x)
 * \brief   Calcula el conjugado de un numero complejo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

complejo complejo_conjugado(const complejo x)
{
    complejo res;

    res.real = a;
    res.imag = -b;

    return res;
}

/* 6. Definicion de la funcion "complejo_modulo" */

/**
 * \fn      double complejo_modulo(const complejo x)
 * \brief   Calcula el modulo o magnitud de un numero complejo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

double complejo_modulo(const complejo x)
{
    double res;
    
    res = pow((pow(a, 2)+pow(b, 2)), 0.5); //raiz cuadrada

    return res;
}

/* 7. Definicion de la funcion "complejo_fase_grados" */

/**
 * \fn      double complejo_fase_grados(const complejo x)
 * \brief   Calcula la fase o argumento en grados, de un numero complejo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

double complejo_fase_grados(const complejo x)
{
    double res;
    
    res = atan(b/a);

    if((b>=0) && (a<0))
    {
        res += 180;
    }
    else if( (b<0) && (a<0))
    {
        res -= 180;
    }
    else if ((b>0) && (a==0))
    {
        res = 90;
    }
    else if((b<0) && (a==0))
    {
        res = -90;
    }

    return res;
}

/* 8. Definicion de la funcion "complejo_fase_radianes" */

/**
 * \fn      double complejo_fase_radianes(const complejo x)
 * \brief   Calcula la fase o argumento en radianes, de un numero complejo pasado como parametro.
 * \author  Marcos Goyret
 * \date    Aug 31, 2019
 * \param   'x' Numero complejo.
 * \return  Resultado de la operacion almacenado en variable res.
 */

double complejo_fase_radianes(const complejo x)
{
    double res;
    
    res = (atan(b/a)/180)*M_PI;

        if((b>=0) && (a<0))
    {
        res += M_PI;
    }
    else if( (b<0) && (a<0))
    {
        res -= M_PI;
    }
    else if ((b>0) && (a==0))
    {
        res = M_PI/2;
    }
    else if((b<0) && (a==0))
    {
        res = -(M_PI/2);
    }

    return res;
}