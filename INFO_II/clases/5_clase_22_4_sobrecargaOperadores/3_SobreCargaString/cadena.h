#ifndef CADENA_H
#define CADENA_H

/*
    Basado en el material de: Álvaro Bustinduy Candelas
    Profesor de la Universidad Antonio de Nebrija
*/
#include <string.h>
#include <iostream>

using namespace std;

class cadena
{
    private:
    char* pstr;
    int nchar; // nº de caracteres (sin el '\0')

    public:
    cadena(); // constructor por defecto
    cadena(const char*); // constructor general
    cadena(const cadena&); // constructor de copia

    ~cadena(); // destructor

    void setcad(const char*); // dar valor a la variable privada pstr
    void view ();

    // sobrecarga de operadores
    cadena& operator= (const cadena&);
    friend cadena operator+ (const cadena&, const cadena&);
    friend cadena operator+ (const cadena&, const char* );
    friend cadena operator+ (const char*, const cadena&);
    friend int operator== (const cadena&, const cadena&);
    friend int operator!= (const cadena&, const cadena&);

    /* Otros operadores que se podrían sobrecargar:
    friend int operator== (const cadena&, const char*);
    friend int operator== (const char*, const cadena&);
    friend int operator!= (const cadena&, const char*);
    friend int operator!= (const char*, const cadena&);
    */
};

#endif // CADENA_H
