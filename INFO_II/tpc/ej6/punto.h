#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

class punto
{

    double mx, my;
public:
    punto();
    punto(double, double);
    punto(double);
    punto(punto&);

    void valcheck(double&, double&);
    void setPunto(double, double);
    void set_punto(punto);
    inline punto getPunto()
    {
        return (*this);
    }
    inline void setX(double x)
    {
        valcheck(x, x);
        mx = x;
    }
    inline void setY(double y)
    {
        valcheck(y, y);
        my = y;
    }
    inline double getX()
    {
        return mx;
    }
    inline double getY()
    {
        return my;
    }
    /*
        Al declararlas friend, y hacerlas funciones globales, el primer argumento no nesesariamente debe ser un objeto de la
        clase. Al recibir un numero como primer argumento, la funcion lo forzara a crear el ojbeto a partir del constructor
        ?parametrizado?
    */
    friend punto operator+ (const punto& i, const punto&);
    friend punto operator- (const punto& i, const punto&);
    punto& operator= (const punto&);
};

#endif // PUNTO_H
