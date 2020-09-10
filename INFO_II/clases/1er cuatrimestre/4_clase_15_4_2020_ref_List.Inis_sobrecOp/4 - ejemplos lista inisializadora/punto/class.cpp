#include "functions.h"

//constructor de copia
Punto::Punto(const Punto& Pref)
{
    x=Pref.x;
    y=Pref.y;
    z=Pref.z;
}

void Punto::getx()
{
    cout << "x = " << x << endl;
}

void Punto::gety()
{
    cout << "y = " << y << endl;
}

void Punto::getz()
{
    cout << "z = " << z << endl;
}

void Punto::getall()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}

void Punto::setx(int a)
{
    x = a;
}

void Punto::sety(int a)
{
    y = a;
}

void Punto::setz(int a)
{
    z = a;
}

void Punto::setall(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}
 void Punto::showobj()
 {
     cout << "(" << x << ", " << y << ", " << z << ")" << endl;
 }
