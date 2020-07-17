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

Punto::Punto(Punto& p)
{
    mx = enRango(p.getX());
    my = enRango(p.getY());
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

Punto Punto::operator+(const Punto& p)
{
    Punto res;
    res.setX(enRango(mx + p.mx));
    res.setY(enRango(my + p.my));

    return res;
}

Punto Punto::operator-(const Punto& p)
{
    Punto res;
    res.setX(enRango(mx - p.mx));
    res.setY(enRango(my - p.my));

    return res;
}
/*
Punto& Punto::operator=(const Punto& p)
{
    mx = enRango(p.mx);
    my = enRango(p.my);

    return (*this);
}
*/
