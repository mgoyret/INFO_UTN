#include "functions.h"

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

/*
    Modificar el punto anterior de manera que acepte los operadores new y delete.

    ¿Cuáles fueron las modificaciones necesarias? Justificar.
    No se modifico nada...
*/



int main()
{
    Punto *r=new Punto(12.34,34.56);
    cout <<"1. punto r: "<<*r<<endl;
    cout <<"2. Puntos Creados:"<<r->getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    delete (r);
    cout <<"3. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    PRESS_KEY;
}
