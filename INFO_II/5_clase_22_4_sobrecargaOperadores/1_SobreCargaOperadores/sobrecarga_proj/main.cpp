#include "complejo.h"

int main()
{
    Complejo c1,c2,c3,c4;

    c1.SetComplejo(3,2);    // 3 + j2
    c2.SetComplejo(1,1);    // 1 + j

    c3 = c4 = c1;

    if(c3 == c4){
        cout << "Son iguales" << endl;
    }
    else{
        cout << "Son distintos" << endl;
    }

    cout << "Valor c1: " << c1 << " y c2: " << c2 << endl;
    cout << "Resta: " << c1 - c2 << endl;

    return 0;
}


Complejo operator- (const Complejo& c1, const Complejo& c2)
{
//    Complejo c_aux((c1.real - c2.real),(c1.imag - c2.imag));      // Version una linea

    Complejo c_aux;

    c_aux.real = c1.real - c2.real;
    c_aux.imag = c1.imag - c2.imag;

    return c_aux;
}


int operator== (const Complejo& c1, const Complejo& c2)
{
    if(c1.real == c2.real && c1.imag == c2.imag)
        return 1;
    return 0;
}


int operator!= (const Complejo& c1, const Complejo& c2)
{
    if(c1.real != c2.real || c1.imag != c2.imag)
        return 1;
    return 0;
}


ostream& operator<< (ostream& os, const Complejo& c)
{
    os << c.real << " + j(" << c.imag << ")";
    return os;
}
