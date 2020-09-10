#include <iostream>
#include <string.h>
#include "cadena.h"

int main()
{

    cadena miCadena("hola");
    cadena otro = "hola";
    cadena final;

    if(miCadena != otro)
    {

        cout<<"son diferentes" << endl;
    }
    else
        cout<<"son iguales" << endl;


    miCadena.view();
    otro.view();
    final = miCadena + otro;
    final.view();

    return 0;
}
