#include "punto.h"


Punto::Punto(double a, double b)
{
    mx = enRango(a);
    my = enRango(b);
}

Punto::Punto(double a)
{
    mx = enRango(a);
    my = 0;
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
