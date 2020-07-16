//#include <iostream>
#include "punto.h"

Punto::Punto()
{//static int creados = 0;
    setPunto(0, 0);
    creados++;
    vivos++;
}

Punto::Punto(double a, double b)
{
    setPunto(a, b);
    creados++;
    vivos++;
}

Punto::Punto(double a)
{
    setPunto(a, 0);
    creados++;
    vivos++;
}

Punto::Punto(Punto& p)
{
    setPunto(p.getX(), p.getY());
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


void Punto::setLimites(float inf, float sup)
{
    if(inf < sup)
    {
        limInf = inf;
        limSup = sup;
    }
    else
        cout << "Intervalo invalido" << endl;
}

Punto& Punto::operator++() //pre
{
    mx++;
    my++;
    return (*this);
}

Punto Punto::operator++(int) //pos
{
    Punto exit(*this);
    mx++;
    my++;
    return exit;
}

/*
Punto& Punto::operator=(const Punto& p)
{
    mx = enRango(p.mx);
    my = enRango(p.my);

    return (*this);
}
*/
