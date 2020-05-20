#ifndef Punto_H
#define Punto_H

#include <iostream>
using namespace std;

class Punto
{

    double mx, my;
    static int creados;
    static int vivos;
    static int LimiteSup;
    static int LimiteInf;
public:
    Punto();
    Punto(double, double);
    Punto(double);
    Punto(Punto&);
    ~Punto();

    void valcheck(double&, double&);
    void setPunto(double, double);
    void set_Punto(Punto);

    static void setLimites (float,float);
    inline static int getLimiteSup(){return LimiteSup;}
    inline static int getLimiteInf(){return LimiteInf;}

    static int getCantCreada() {return creados;}
    static int getCantExistente() {return vivos;}
    static void addCreado() {creados++;}
    static void addVivo() {vivos++;}
    static void rmVivo() {vivos--;}

    inline Punto getPunto(){return (*this);}
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
    inline double getX(){return mx;}
    inline double getY(){return my;}
    /*
        Al declararlas friend a "+" y a "-", y hacerlas funciones globales, el primer argumento no nesesariamente debe ser un objeto de la
        clase. Al recibir un numero como primer argumento, la funcion lo forzara a crear el ojbeto a partir del constructor
        ?parametrizado?
    */
    Punto& operator= (const Punto&);
    friend Punto operator+(const Punto& i, const Punto&);
    friend Punto operator-(const Punto& i, const Punto&);
    friend int operator==(const Punto&, const Punto&);
    friend int operator!=(const Punto&, const Punto&);
    friend int operator<(const Punto&, const Punto&);
    friend int operator>(const Punto&, const Punto&);
    friend ostream& operator<<(ostream&, const Punto&);
    friend istream& operator>>(istream&, Punto&);

};

#endif // Punto_H
