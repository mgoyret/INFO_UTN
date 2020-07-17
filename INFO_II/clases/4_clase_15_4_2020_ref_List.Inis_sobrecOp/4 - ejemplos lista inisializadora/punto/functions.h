#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class Punto
{
    public:

        //constructor parametrizado con lista inicializadora
        Punto(int a = 0, int b = 2, int c = 4): x(a), y(b), z(c){}
        //constructor de copia
        Punto(const Punto&);

        void getx();
        void gety();
        void getz();
        void getall();

        void setx(int);
        void sety(int);
        void setz(int);
        void setall(int, int, int);

        void showobj();

    private:
        int x, y, z;

};

#endif // FUNCTIONS_H


#ifndef CUENTA_H
#define CUENTA_H

#endif // CUENTA_H
