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
    PRESS_KEY;

    return 0;
}

/*

Se debe implementar la clase IntArr, la cual es una clase para trabajar con una array o vector de datos tipo
int en forma dinámica, cuya definición es la que sigue:

class IntArr
{
    private:
        int * p;
        int size;
        int used;
    public:
        IntArr (int sz);
        IntArr (int sz,int qtty,int *vec);
        ~IntArr();
        void prtArr (void) const;
};

En donde
p: es el puntero al array dinámico.
size: es la cantidad de elementos del array p.
used: es la cantidad de elementos usados del array p. used será siempre <= a size.
IntArr (int sz): crea un elemento IntArr con sz elementos disponibles.
IntArr (int sz,int qtty, int *vec): crea un elemento IntArr con sz elementos disponibles, y copia
qtty elementos del array vec al array p.
~IntArr (int sz): destructor.
prtArr: imprime el Array en pantalla.

Nota: si en IntArr (sz,qtty,vec); qtty es mayor a sz, se debe solucionar el error igualando sz a qtty
*/
