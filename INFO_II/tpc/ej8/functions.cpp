#include <iostream>
#include "functions.h"

Punto operator+ (const Punto& i, const Punto& p)
{
    Punto aux;

    aux.mx = i.mx + p.mx;
    aux.my = i.my + p.my;
    aux.valcheck(aux.mx, aux.my);
    return aux;
}

Punto operator- (const Punto& i, const Punto& p)
{
    Punto aux;

    aux.mx = i.mx - p.mx;
    aux.my = i.my - p.my;
    aux.valcheck(aux.mx, aux.my);
    return aux;
}

int operator==(const Punto& a, const Punto& b)
{
    int exit = ERROR;
    if((a.mx == b.mx) && (a.my == b.my))
    {
        exit = EXITO;
    }

    return exit;
}

int operator!=(const Punto& a, const Punto& b)
{
    int exit = ERROR;

    if((a.mx != b.mx) || (a.my != b.my))
    {
        exit = EXITO;
    }

    return exit;
}

int operator<(const Punto& a, const Punto& b)
{
    int exit = ERROR;

    if( (((a.mx)*(a.mx)) + ((a.my)*(a.my))) < (((b.mx)*(b.mx)) + ((b.my)*(b.my))) )
    {
        exit = EXITO;
    }

    return exit;
}

int operator>(const Punto& a, const Punto& b)
{
    int exit = ERROR;

    if( (((a.mx)*(a.mx)) + ((a.my)*(a.my))) > (((b.mx)*(b.mx)) + ((b.my)*(b.my))) )
    {
        exit = EXITO;
    }

    return exit;
}

ostream& operator<<(ostream& os, const Punto& a)
{
    os << "( " << a.mx << ", " << a.my << " )" << endl;

    return os;
}

istream& operator>>(istream& is, Punto& a)
{
    double x, y;
    cout << "x: ";
    is >> x;
    cout << "y: ";
    is >> y;
    a.setPunto(x, y);

    return is;
}


void ff (void)
{
    Punto p,q,w;
    Punto h(34);
    Punto r=h;
    cout <<"a. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< r.getCantExistente()<<endl;
}
