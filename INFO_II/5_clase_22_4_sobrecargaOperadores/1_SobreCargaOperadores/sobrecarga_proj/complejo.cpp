#include "complejo.h"

//Contructor de copia
Complejo::Complejo(const Complejo &c)
{
    real = c.real;
    imag = c.imag;
}

// Destructor
Complejo::~Complejo()
{
}

// Sobrecarga operador de asignacion
Complejo& Complejo::operator=(const Complejo &c)
{
    if(*this != c){
        real = c.real;
        imag = c.imag;
    }
    return *this;
}

// Sobrecarga operador suma
Complejo Complejo::operator+(const Complejo &c)
{
//    Complejo c_aux((real + c.real),(imag + c.imag));      // Version una linea

    Complejo c_aux;

    c_aux.real = real + c.real;
    c_aux.imag = imag + c.imag;

    return c_aux;
}
