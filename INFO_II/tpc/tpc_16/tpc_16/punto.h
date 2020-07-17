#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

#define LIMINF -1000
#define LIMSUP 1000

class Punto
{
    private:

    double mx, my;
    static float limSup, limInf;
    static int creados, vivos;

    public:

    Punto();
    Punto(double, double);
    Punto(double);
    Punto(Punto&);
    ~Punto();

    inline static int getCantCreada(){return creados;}
    inline static int getCantExistente(){return vivos;}
    static void setLimites (float,float);
    inline static float getLimiteInf(){return limInf;}
    inline static float getLimiteSup(){return limSup;}

    double enRango(double);
    void setPunto(double, double);
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

    Punto& operator++(); //pre
    Punto operator++(int); //pos

};


#endif // PUNTO_H
