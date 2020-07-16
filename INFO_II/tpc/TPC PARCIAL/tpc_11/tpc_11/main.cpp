#include "functions.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int Punto::creados = 0;
int Punto::vivos = 0;
float Punto::limInf = LIMINF;
float Punto::limSup = LIMSUP;

int main()
{    
    Punto *r=new Punto(12.34,34.56);
    Punto *q;
    q=r;
    cout <<"1. punto r: "<<*r<<endl;
    cout <<"2. Puntos Creados:"<<r->getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    delete (r);
    cout <<"3. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    PRESS_KEY;

    return 0;
}

/*

Modificar el punto anterior de manera que acepte los operadores new y delete.

¿Cuáles fueron las modificaciones necesarias? Justificar.

No modifique nada...calculo que tendre que hacer la sobrecarga del op=() por si la uso...

*/
