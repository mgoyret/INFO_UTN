#include "punto.h"

punto::punto()
{
    mx = my = 0;
}

punto::punto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
}


punto::punto(double x)
{
    valcheck(x, x);
    mx = x;
    my = 0;
}

punto::punto(punto& p)
{
    mx = p.getX();
    my = p.getY();
}

void punto::setPunto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
}

void punto::set_punto(punto p)
{
    //es imposible darle un valor -1000<valor<1000 a los campos de la clase punto, por lo que
    //al copiar de una clase a otra se da por sentado que los valores estan entre ese rango

    mx = p.getX();
    my = p.getY();
}

void punto::valcheck(double& x, double& y)
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


punto& punto::operator=(const punto& p)
{
    mx = p.mx;
    my = p.my;
    return (*this);
}
