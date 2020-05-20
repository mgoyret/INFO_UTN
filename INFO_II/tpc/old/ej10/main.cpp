#include "functions.h"

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

/*
Sobrecargar el pre y post incremento de manera que incremente en una unidad tanto el valor de x como
de y.

Pregunta: que inconvenientes encuentra en una operación como la que sigue (revise los resultados
obtenidos):

    Punto x(10,10);
    Punto z;
    z=x++ + x++;
    int h=10;
    int j;
    j=h++ + h++;

    - Ningun inconveniente. Simplemente, por ej, si A=0 y B=1 => A = B++ + B++ = (1) + (2)
      el primer termino vale B, y el seugndo termino vale lo que era B, mas uno, ya que fue post incrementado.
      El segundo post incremento no afecta nada a esta ecuacion.

*/



int main()
{
    Punto r(12.34,34.56);
    cout <<"1. punto r: "<<r<<endl;
    cout <<"2. punto r++: "<<r++<<endl;
    cout <<"3. punto r: "<<r<<endl;
    cout <<"4. punto ++r: "<<++r<<endl;
    PRESS_KEY;
}

