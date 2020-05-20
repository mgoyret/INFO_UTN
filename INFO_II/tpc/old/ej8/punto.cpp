#include "punto.h"

int Punto::creados = 0;
int Punto::vivos = 0;

Punto::Punto()
{
    mx = my = 0;
    addCreado();
    addVivo();
}

Punto::Punto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
    addCreado();
    addVivo();
}


Punto::Punto(double x)
{
    valcheck(x, x);
    mx = x;
    my = 0;
    addCreado();
    addVivo();
}

Punto::Punto(Punto& p)
{
    mx = p.getX();
    my = p.getY();
    addCreado();
    addVivo();
}

Punto::~Punto()
{
    rmVivo();
}

void Punto::setPunto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
}

void Punto::set_Punto(Punto p)
{
    //es imposible darle un valor -1000<valor<1000 a los campos de la clase Punto, por lo que
    //al copiar de una clase a otra se da por sentado que los valores estan entre ese rango

    mx = p.getX();
    my = p.getY();
}

void Punto::valcheck(double& x, double& y)
{
    if(x > 1000)
        x = 1000;
    if(x < -1000)
        x = -1000;
    if(y > 1000)
        y = 1000;
    if(y < -1000)
        y = -1000;
}


Punto& Punto::operator=(const Punto& p)
{
    mx = p.mx;
    my = p.my;
    return (*this);
}
