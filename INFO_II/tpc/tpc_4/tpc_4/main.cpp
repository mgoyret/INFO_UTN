#include <iostream>
#include "punto.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main()
{    
    Punto p(12.34,-56.78);
    Punto r(p);
    Punto q=p;
    cout <<"1. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    cout <<"3. punto q: ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    Punto s(1,2);
    cout <<"4. punto s: ("<<s.getX()<<";"<<s.getY()<<")"<<endl;

    PRESS_KEY;

    return 0;
}

/*
Modificar el punto anterior de manera que acepte la creación de un objeto de la siguiente manera:
Punto pd (pc); o Punto pd=pc; // donde pc es un objeto Punto.

SOLO HUBO QUE AGREGAR UN CONSTRUCTO DE COPIA.
LA IGUALACION YA FUNCIONABA YA QUE ERA UNA OPERACION BIT A BIT
*/
