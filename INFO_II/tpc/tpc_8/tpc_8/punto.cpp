//#include <iostream>
#include "punto.h"

Punto::Punto()
{
    mx = my = 0;
    limInf = LIMINF;
    limSup = LIMSUP;
    creados++;
    vivos++;
}

Punto::Punto(double a, double b)
{
    mx = enRango(a);
    my = enRango(b);
    limInf = LIMINF;
    limSup = LIMSUP;
    creados++;
    vivos++;
}

Punto::Punto(double a)
{
    mx = enRango(a);
    my = 0;
    limInf = LIMINF;
    limSup = LIMSUP;
    creados++;
    vivos++;
}

Punto::Punto(Punto& p)
{
    mx = enRango(p.getX());
    my = enRango(p.getY());
    limInf = LIMINF;
    limSup = LIMSUP;
    creados++;
    vivos++;
}

Punto::~Punto()
{
    vivos--;
}

double Punto::enRango(double num)
{
    double exit = 0;

    if( (num>=limInf) && (num<=limSup) )
        exit = num;
    else if( (num<limInf) )
        exit = limInf;
    else
        exit = limSup;

    return exit;
}
void Punto::setPunto(double a, double b)
{
    mx = enRango(a);
    my = enRango(b);
}

void Punto::setPunto(Punto pa)
{
    mx = enRango(pa.getX());
    my = enRango(pa.getY());
}

/*
Punto& Punto::operator=(const Punto& p)
{
    mx = enRango(p.mx);
    my = enRango(p.my);

    return (*this);
}
*/