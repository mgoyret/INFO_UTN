#include "punto.h"
/*
Punto::Punto()
{
}
*/

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

