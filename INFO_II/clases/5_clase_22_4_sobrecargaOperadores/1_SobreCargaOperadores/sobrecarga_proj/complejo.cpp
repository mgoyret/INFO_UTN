#include "complejo.h"

/* Contructor de copia */
Complejo::Complejo(const Complejo &c)
{
    real = c.real;
    imag = c.imag;
}

/* Destructor */
Complejo::~Complejo()
{
}

/* Sobrecarga operador de asignacion */
Complejo& Complejo::operator=(const Complejo &c)
{
    if(*this != c){
        real = c.real;
        imag = c.imag;
    }
    return *this;
}

/* Sobrecarga operador suma */
Complejo Complejo::operator+(const Complejo &c)
{
  //Complejo c_aux((real + c.real),(imag + c.imag)); // Version una linea

    Complejo c_aux;

    c_aux.real = real + c.real;
    c_aux.imag = imag + c.imag;

    return c_aux;
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
    if( (c1.real == c2.real) && (c1.imag == c2.imag) )
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
