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


void punto::setPunto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
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
