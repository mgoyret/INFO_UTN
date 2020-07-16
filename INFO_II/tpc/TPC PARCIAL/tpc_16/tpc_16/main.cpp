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
    cout<<"\n==================> Inicio <==================\n";
    int v1[]={0,5,10,15,20,25,30,35,40};
    int v2[]={1,2,3,4,5,6};
    IntArr A(10,SZ_VEC(v1),v1);
    IntArr B(10,SZ_VEC(v2),v2);
    IntArr C=B;
    B.addElement(0,99);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    cout<<"\n> Array B\n"<<B;
    cout<<"\n> Array C\n"<<C;
    cout<<"\n==================> Medio <==================\n";

    A=B+C;
    cout<<"\n> Array A=B+C\n"<<A;
    IntArr D(10,SZ_VEC(v1),v1);
    D=D;
    cout<<"\n> Array A\n"<<A;
    cout<<"\n==================> Medio <==================\n";
    D+=B;
    cout<<"\n> Array D+=B\n"<<D;
    PRESS_KEY;

    return 0;
}

/*

Agregar a la clase IntArr del ejercicio anterior, los elementos necesarios para permitir las sentencias que
se visualizan en el siguiente código:

*/
