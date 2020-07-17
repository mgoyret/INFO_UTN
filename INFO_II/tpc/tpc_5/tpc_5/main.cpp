#include <iostream>
#include "punto.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main()
{    
    Punto p(12.34,-56.78);
    Punto r(1,4);
    Punto q;
    cout <<"1. punto p= ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto r= ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    q=p+r;
    cout <<"3. punto p+r: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    q=p-r;
    cout <<"4. punto p-r: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    Punto s(990,-990);
    cout <<"5. punto s= ("<<s.getX()<<";"<<s.getY()<<")"<<endl;
    q=s+p;
    cout <<"6. punto s+p: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    q=r+47;
    cout <<"7. punto r+47: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    PRESS_KEY;

    return 0;
}

/*

Modificar el punto anterior para permitir la suma (+), resta (-) y asignación (=) de objetos tipo Punto.
Nota: tener en cuenta que las operaciones de deben controlar que los valores de x e y, no desborden el
rango de +/- 1000.
No utilizar friend, para realizar la sobrecarga de los operadores suma (+) y resta (-).

- ¿Requiere sobrecargar el operador de asignación (=)? ¿Por qué?
  No hace falta, ya que el '=' sin sobrecargarce operara bit a bit copiando todo un objeto sobre el otro

- Justifique la ejecución de la línea q=r+47; (como se produce la suma entre el objeto Punto y el
objeto int, suponiendo que mantuvo la consigna de escribir lo menos posible y no sobrecargó la
suma de Punto con int)
la funcion sobrecargada del operador '+' al segundo parametro lo recibe como un objeto Punto, creando un obj temporal,
como tiene solo un parametro se construira este objeto a partir del constructor que recibe un parametro double, y
a la 'my' le asigna 0. Por eso, r+47 es como hacer (r.mx; r.my) + (47, 0)

*/
