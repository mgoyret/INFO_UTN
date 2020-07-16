#include "functions.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main()
{    
    Punto p(12.34,-56.78);
    Punto r,s;
    s=78+p;
    r=78-p;
    cout <<"1. punto p= ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto 78+p: s= ("<<s.getX()<<";"<<s.getY()<<")"<<endl;
    cout <<"3. punto 78-p: r= ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    r=p+s-45;
    cout <<"4. punto p+s-45: r= ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    PRESS_KEY;

    return 0;
}

/*

Modificar el punto anterior para permitir la ejecución del siguiente código. Recordar realizar siempre la
menor cantidad de código. En este caso, sería que la implementación de la suma y resta se realice cada
una con un solo método miembro.

Justificar la implementacion
Al hacer las funciones de op. sobrecargado 'friends', se especifica el tipo de dato que son los argumentos que se reciben,
y de esta manera pude recibirse un double "suelto" de cualquier lado del operador ya que se generara el objeto correspondiente
por el constructor que recibe un double como parametro
*/
