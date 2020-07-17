#include "functions.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int Punto::creados = 0;
int Punto::vivos = 0;

int main()
{    
    cout <<"1. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    Punto p(12.34,-56.78);
    cout <<"2. Puntos Creados:"<<p.getCantCreada()<< " - Existentes:"<< p.getCantExistente()<<endl;
    Punto h(p);
    cout <<"3. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    ff();
    cout <<"4. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    PRESS_KEY;
    return 0;
}

/*

Agregar a la clase Punto, del ejercicio anterior, dos métodos públicos del tipo inline que indiquen la
cantidad de instancias del tipo objeto que han sido creadas y cuantas se encuentran en memoria.
Nota: los contadores debe ser miembros privados de la clase.
Justificar la invocación de los métodos getCantCreada y getCantExistente antes de la creación de
cualquier objeto.

son metodos static para manipular variables static, osea que no dependen de la existencia de un objeto concreto,
viven desde que arranca el programa hasta que muere el mismo;

*/
