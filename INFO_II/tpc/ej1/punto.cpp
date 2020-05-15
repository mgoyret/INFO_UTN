#include "punto.h"

punto::punto()
{
    mx = my = 0;
}

punto::punto(double x, double y)
{
    mx = x;
    my = y;
}


void punto::setPunto(double x, double y)
{
    mx = x;
    my = y;
}
