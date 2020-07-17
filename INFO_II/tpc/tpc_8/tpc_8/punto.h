#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

#define LIMINF -1000
#define LIMSUP 1000

class Punto
{
    double mx, my;
    int limSup, limInf;
    static int creados;
    static int vivos;

    public:

    Punto();
    Punto(double, double);
    Punto(double);
    Punto(Punto&);
    ~Punto();

    inline static int getCantCreada(){return creados;}
    inline static int getCantExistente(){return vivos;}

    double enRango(double);
    void setPunto(double a, double b);
    void setPunto(Punto);
    inline Punto getPunto() {return *this;}

    void setX(double a){mx=enRango(a);}
    void setY(double b){my=enRango(b);}
    double getX(){return mx;}
    double getY(){return my;}

    friend Punto operator+(const Punto&, const Punto&);
    friend Punto operator-(const Punto&, const Punto&);
    friend int operator<(const Punto&, const Punto&);
    friend int operator>(const Punto&, const Punto&);
    friend int operator!=(const Punto&, const Punto&);
    friend int operator==(const Punto&, const Punto&);
    friend ostream& operator<<(ostream&, const Punto&);
    friend istream& operator>>(istream&, Punto&);
    //Punto& operator=(const Punto&);

};


#endif // PUNTO_H
