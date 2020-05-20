#include "functions.h"

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

/*
    Modificar el punto anterior para permitir la comparación entre objetos tipo punto: igualdad (==);
    desigualdad (!=), mayor (>) y menor (<), sobrecargar el flujo de salida y entrada (<< y >>).
    En el caso de la sobrecarga de mayor (>) y menor (<), se debe comparar la distancia que existe al centro
    de coordenadas (0;0).
*/

int main()
{
    punto p(12.34,-56.78);
    double r=45;
    cout <<"1. punto p= "<<p<<endl;
    cout <<"2. punto r= "<<r<<endl;
    cout <<"Ingrese valor del punto"<<endl;
    punto h;
    cin >>h;
    cout <<"3. punto h= "<<h<< "(*)" <<endl<<endl<<endl;

    cout <<" 4. Es h igual a p?     : "<<((h==p)?"si":"no") << endl;
    cout <<" 5. Es h distinto a p?  : "<<((h!=p)?"si":"no") << endl;
    cout <<" 6. Es h mayor a p?     : "<<((h>p)?"si":"no")  << endl;
    cout <<" 7. Es h menor a p?     : "<<((h<p)?"si":"no")  << endl << endl;

    cout <<" 8. Es h igual a r?     : "<<((h==r)?"si":"no") << endl;
    cout <<" 9. Es h distinto a r?  : "<<((h!=r)?"si":"no") << endl;
    cout <<"10. Es h mayor a r?     : "<<((h>r)?"si":"no")  << endl;
    cout <<"11. Es h menor a r?     : "<<((h<r)?"si":"no")  << endl << endl;

    PRESS_KEY;
}
