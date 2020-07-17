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
    Punto r(12.34,34.56);
    cout <<"1. punto r: "<<r<<endl;
    cout <<"2. punto r++: "<<r++<<endl;
    cout <<"3. punto r: "<<r<<endl;
    cout <<"4. punto ++r: "<<++r<<endl;
    PRESS_KEY;


    Punto x(10,10);
    Punto z;
    cout <<"1. punto x: "<<x<<endl;
    cout <<"2. punto z: "<<z<<endl;
    z=x++ + x++;
    cout <<"3. punto x: "<<x<<endl;
    cout <<"4. punto z: "<<z<<endl;
    int h=10;
    cout <<"5. h: "<<h<<endl;
    int j;
    j=h++ + h++;
    cout <<"6. punto j: "<<j<<endl;


    return 0;
}

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

La operacion se realiza "de derecha a izquierda. Al aparecer el x++ de mas a la derecha, es la funcion
posincremento, por lo q lo que vale ese retorno es el (10, 10) que la x tenia. Pero luego al leer el x++ de la
izquierda, este fue incrementado en el anterior, por lo que ahora vale 11. Esa invocacion de la operacion posinc
retornara 11, y ademas lo incrementara, pero no nos afecta ahora. z=(11, 11) + (10, 10).
Luego x vale (12, 12)
Lo mismo con la h y j

*/
