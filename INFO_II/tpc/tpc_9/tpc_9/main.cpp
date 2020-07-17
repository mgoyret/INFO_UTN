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
    cout <<"1. Rango de punto: "<<Punto::getLimiteInf()<< ":"<<Punto::getLimiteSup()<<endl;
    Punto p(3000.12,5000);
    Punto r(12.34,34.56);
    cout <<"2. punto p: "<<p<<endl;
    cout <<"3. punto r: "<<r<<endl;
    Punto::setLimites(50,85);
    cout <<"4. Rango de punto: "<<p.getLimiteInf()<< ":"<<p.getLimiteSup()<<endl;
    cout <<"5. punto p: "<<p<<endl;
    cout <<"6. punto r: "<<r<<endl;
    Punto t;
    cout <<"7. nuevo punto t: "<<t<<endl;
    r=p; // como la igualdad no esta redefinida, no se ve afectada por el nuevo límite
    cout <<"8. r=p r: "<<r<<endl;
    r.setPunto(p);
    cout <<"9. setPunto r: "<<r<<endl;
    r.setLimites(500,-85);
    cout <<"10. Rango de punto: "<<Punto::getLimiteInf()<< ":"<<Punto::getLimiteSup()<<endl;
    PRESS_KEY;

    return 0;
}

/*

Agregar un método público “set_limites (float,float)”, que modifique el rango válido de x e y de la clase.
Esto significa que el rango de todos los objetos existentes y de los objetos por crear se verán afectados
por este método.
Este método no debe modificar los valores de coordenadas x;y. (No importa que éstos queden fuera de
rango).
El primer parámetro corresponde al límite inferior y el segundo al superior. Si el límite inferior no es menor
al superior, se debe omitir el cambio del rango.
Implementar además las funciones “getLimiteSup” y “getLimiteInf”, del tipo inline, para saber cuáles son
los valores de estos límites. Por omisión, los límites son +/- 1000.

Ejemplos:
Punto Pa(5000,-5000); toma el valor (1000;-1000) por los límites definidos por omisión.
Si luego ejecuto:
Punto::set_limites (50,-50);
Punto Pb(5000,-5000); toma el valor (50;-50) por los límites definidos explícitamente.
Pa mantendrá el valor (1000;-1000), sin embargo si ejecuto Pa=Pa+100, su nuevo valor será (50;-50)
pues se ve afectado por el nuevo rango definido.


Nótese que al crear el objeto t, con parámetros por omisión, debería haber tomado el valor (0;0), sin
embargo como el límite inferior es ‘50’, toma el valor (50;50);
Además, como el operador igualdad (=) no está sobrecargado, la operación r=p, será una copia bit a bit y
no se controlará el rango, por ende r poseerá valores fuera del rango.

Pregunta: ¿por qué no se pude definir las funciones getLimiteSup y getLimiteInf como const?

??????????????????????
La variable limite es static, y la funcion getlim tambien, osea que son funciones que miran SIEMPRE a la misma
variable, no hay una variable en cada objeto, es siempre la misma, y varia, por lo que la funcion no puede
ser const ya que una variable no constante solo puede manipularce con una funcion no constante
??????????????????????
*/
