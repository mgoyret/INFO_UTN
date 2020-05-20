#include "punto.h"

int Punto::creados = 0;
int Punto::vivos = 0;
int Punto::LimiteInf = -1000;
int Punto::LimiteSup = 1000;

Punto::Punto()
{
    if (0 >= LimiteInf) {
        mx = my = 0;
    }
    else {
        mx = my = LimiteInf;
    }
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
    //es imposible darle un valor que no respete los limites a los campos de la clase Punto, por lo que
    //al copiar de una clase a otra se da por sentado que los valores estan entre ese rango
    double x = p.getX(), y = p.getY();
    valcheck(x, y);
    mx = x;
    my = y;
}

void Punto::valcheck(double& x, double& y)
{
    if(x > LimiteSup)
        x = LimiteSup;
    if(x < LimiteInf)
        x = LimiteInf;
    if(y > LimiteSup)
        y = LimiteSup;
    if(y < LimiteInf)
        y = LimiteInf;
}


Punto& Punto::operator=(const Punto& p)
{
    mx = p.mx;
    my = p.my;
    return (*this);
}

void Punto::setLimites (float inf,float sup)
{
    if(inf < sup){
        LimiteInf = inf;
        LimiteSup = sup;
    }
}
//pos
Punto Punto::operator++(int)
{
    Punto p(mx, my);
    mx++;
    my++;
    return p;
}


//pre
Punto& Punto::operator++()
{
    mx++;
    my++;
    return *this;
}
