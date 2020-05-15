#include <iostream>
#include "functions.h"

punto operator+ (const punto& i, const punto& p)
{
    punto aux;

    aux.mx = i.mx + p.mx;
    aux.my = i.my + p.my;
    aux.valcheck(aux.mx, aux.my);
    return aux;
}

punto operator- (const punto& i, const punto& p)
{
    punto aux;

    aux.mx = i.mx - p.mx;
    aux.my = i.my - p.my;
    aux.valcheck(aux.mx, aux.my);
    return aux;
}
