#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class Complejo
{
private:
    float real;
    float imag;

public:

    Complejo() : real(0) , imag(0) {}                       // Constructor por defecto
    Complejo(float x, float y=0) : real(x) , imag(y) {}     // Constructor parametrizado
    Complejo(const Complejo&);                              // Constructor de copia

    ~Complejo();                                            // Destructor

    // Metodos o funciones miembro de la clase
    inline void SetComplejo(float x, float y){
        real = x;
        imag = y;
    }

    // Sobrecarga de operadores
    Complejo& operator= (const Complejo&);
    Complejo operator+ (const Complejo&);
//    friend Complejo operator+ (const Complejo&, const Complejo&);
    friend Complejo operator- (const Complejo&, const Complejo&);
    friend int operator== (const Complejo&, const Complejo&);
    friend int operator!= (const Complejo&, const Complejo&);
    friend ostream& operator<< (ostream&, const Complejo& );

};

#endif // COMPLEJO_H
