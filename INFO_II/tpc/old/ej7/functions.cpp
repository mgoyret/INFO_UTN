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

int operator==(const punto& a, const punto& b)
{
    int exit = ERROR;
    if((a.mx == b.mx) && (a.my == b.my))
    {
        exit = EXITO;
    }

    return exit;
}

int operator!=(const punto& a, const punto& b)
{
    int exit = ERROR;

    if((a.mx != b.mx) || (a.my != b.my))
    {
        exit = EXITO;
    }

    return exit;
}

int operator<(const punto& a, const punto& b)
{
    int exit = ERROR;

    if( (((a.mx)*(a.mx)) + ((a.my)*(a.my))) < (((b.mx)*(b.mx)) + ((b.my)*(b.my))) )
    {
        exit = EXITO;
    }

    return exit;
}

int operator>(const punto& a, const punto& b)
{
    int exit = ERROR;

    if( (((a.mx)*(a.mx)) + ((a.my)*(a.my))) > (((b.mx)*(b.mx)) + ((b.my)*(b.my))) )
    {
        exit = EXITO;
    }

    return exit;
}

ostream& operator<<(ostream& os, const punto& a)
{
    os << "( " << a.mx << ", " << a.my << " )" << endl;

    return os;
}

istream& operator>>(istream& is, punto& a)
{
    double x, y;
    cout << "x: ";
    is >> x;
    cout << "y: ";
    is >> y;
    a.setpunto(x, y);

    return is;
}
