#include <iostream>
#include "functions.h"

Punto operator+(const Punto& p, const Punto& q)
{
    Punto res;
    res.setX(res.enRango(p.mx + q.mx));
    res.setY(res.enRango(p.my + q.my));

    return res;
}

Punto operator-(const Punto& p, const Punto& q)
{
    Punto res;
    res.setX(res.enRango(p.mx - q.mx));
    res.setY(res.enRango(p.my - q.my));

    return res;
}

/* Para las sobrecargas de >/< no hace falta calcular la raiz, pero queria probar <cmath> */
int operator<(const Punto& p, const Punto& q)
{
    int exit = 0;
    if( sqrt(((p.mx)*(p.mx)) + ((p.my)*(p.my))) < sqrt(((q.mx)*(q.mx)) + ((q.my)*(q.my))) )
        exit = 1;
    return exit;
}
int operator>(const Punto& p, const Punto& q)
{
    int exit = 0;
    if( sqrt(((p.mx)*(p.mx)) + ((p.my)*(p.my))) > sqrt(((q.mx)*(q.mx)) + ((q.my)*(q.my))) )
        exit = 1;
    return exit;
}
int operator!=(const Punto& p, const Punto& q)
{
    int exit = 0;
    if( (p.mx != q.mx) || (p.my != q.my))
        exit = 1;
    return exit;
}

int operator==(const Punto& p, const Punto& q)
{
    int exit = 0;
    if( (p.mx == q.mx) && (p.my == q.my))
        exit = 1;
    return exit;
}

ostream& operator<<(ostream& os, const Punto& p)
{
    os << "[" << p.mx << "; " << p.my << "]";
    return os;
}

istream& operator>>(istream& is, Punto& p)
{
    double x, y;
    /* Pongo estos cout pero me recomendaron que las clases no hagan cout... */
    cout << "ingrese x: ";
    is >> x;
    cout << "ingrese y: ";
    is >> y;
    p.setPunto(x, y);
    return is;
}
