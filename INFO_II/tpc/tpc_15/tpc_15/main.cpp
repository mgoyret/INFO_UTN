#include "functions.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int Punto::creados = 0;
int Punto::vivos = 0;
float Punto::limInf = LIMINF;
float Punto::limSup = LIMSUP;

#define SZ_VEC(x) (sizeof(x)/sizeof(x[0]))

int main()
{
    int v1[]={0,5,10,15,20,25,30,35,40};
    int v2[]={1,2,3,4,5,6};
    IntArr A(10,SZ_VEC(v1),v1);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(0,77);
    A.addElement(56,11);
    A.addElement(4,SZ_VEC(v2),v2);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(4,99);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    PRESS_KEY;

    return 0;
}

/*

Modificar los métodos addElement, incluidos en el ejercicio anterior, de manera de poder indicar a partir
de qué se deben agregar los nuevos elementos. Siendo el nuevo prototipo como sigue:

    addElement (int pos, int xx).
    addElement (int pos, int qtty, int *vec)

En donde pos, indica la posición a partir de donde comienza la inserción. Los demás parámetros
mantienen su significado.

Nota: En caso que pos fuese negativo, se considera inserción desde el inicio y sí el valor de pos, supera
la máxima ubicación posible dentro del Array dinámico, se debe insertar al final.

*/
