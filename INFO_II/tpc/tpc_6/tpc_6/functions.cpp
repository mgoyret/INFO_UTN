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
