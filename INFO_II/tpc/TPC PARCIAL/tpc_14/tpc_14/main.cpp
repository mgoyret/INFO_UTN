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
    int v_aux[]={0,5,10,15,20,25,30,35,40};
    IntArr A(10,sizeof(v_aux)/sizeof(int),v_aux);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(77);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(11);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(8,v_aux);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    PRESS_KEY;

    return 0;
}

/*

Agregar a la clase IntArr, los siguientes métodos públicos:
addElement (int xx): el cual agrega el elemento xx al final del array “IntArr”.
addElement (int qtty, int *vec): el cual agrega los qtty elementos que se encuentran en vec al
final del array “IntArr”.
Nota: tener en cuenta que al agregar elementos al objeto, se puede desbordar el Array dinámico, por lo
tanto habrá que redimensionarlo. En tal caso y en forma preventiva solicitar espacio para 5 elementos más
de los necesarios.

*/
