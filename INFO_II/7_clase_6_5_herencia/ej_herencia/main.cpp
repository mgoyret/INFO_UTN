#include <iostream>
#include "base.h"
#include "derivada.h"

using namespace std;

int main()
{
    float num;
    Base a, b(5);
    cout << " objA: " ;
    a.Base::display();

    cout << " objB: ";
    b.Base::display();

    Derivada c, d(10.0), e(20, 10.5);

    c.setX(3);
    cout << " objC: " <<endl;
    c.Base::display();

    cout << " objD: " <<endl;
    d.display();

    cout << " objE: " <<endl;
    e.display();

    cout << " objC: "<<endl;
    c.Base::display();
    cout << " objC: "<<endl;
    cout << "z = " << c.getZ() << endl;
    cout << "setear \"z\" a: ";
    cin >> num;
    c.setZ(num);
    cout << "ahora z es: " << c.getZ() << endl;
    cout << "Muestro todo con display redefinida" << endl;
    c.display();

    Base h;
    cout << " objH: " <<endl;
    cout << "x=" << h.getX() << endl << "y=" << h.getY() << endl;
    h.Base::operator=(b);
    cout << " objH: " <<endl;
    cout << "x=" << h.getX() << endl << "y=" << h.getY() << endl;

    d = e;
    cout << " objD: " <<endl;
    d.display();

    cout << " objE: " <<endl;
    e.display();

    return 0;

// Desarrollar y verificar el funcionamiento de los siguientes ítems:

// 1) Definir un método en la Clase Derivada que permita setear el valor de la variable miembro 'z'.

// 2) Redefinir la función display en la Clase Derivada para imprimir todas las variables.
// IMPORTANTE: Aprovechar la función display de la Clase Base!

// 3) Definir en la Clase Base una variable miembro como "protected" y verificar el acceso desde
//  la nueva función display en la Clase Derivada. NOTA: Incorporar los cambios para imprimir también
//  esta nueva variable.

// 4) Definir el operador = en la Clase Base para permitir la asignación entre dos objetos dicha clase.

// 5) Definir el operador = en la Clase Derivada para permitir la asignación entre dos objetos dicha clase.
// IMPORTANTE: Aprovechar el operador = definidor para la Clase Base!

}
