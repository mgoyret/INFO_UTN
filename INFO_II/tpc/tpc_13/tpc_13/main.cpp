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
    IntArr A(30);
    int v_aux[]={23,4,54,634,6677,32,56};
    IntArr B(40,sizeof(v_aux)/sizeof(int),v_aux);
    A.prtArr();
    B.prtArr();
    B.prtArr(3);
    cout<<"\n\nObjeto B -"<<endl;
    cout<<" size:"<<B.getSize()<<endl;
    cout<<" used:"<<B.getUsed()<<endl;
    cout<<" promedio:"<<B.getAvg()<<endl;
    PRESS_KEY;

    return 0;
}

/*

Agregar a la clase IntArr, los siguientes métodos públicos:
getSize del tipo inline que devuelve el tamaño del IntArr.
getUsed del tipo inline que devuelve la cantidad de elementos usados del IntArr.
getAvg devuelve el promedio de los elementos del IntArr. El promedio devuelto es del tipo double.
Y sobrecargar el método prtArr, de manera de indicar cuantos elementos imprimir desde el inicio del Array.

*/
