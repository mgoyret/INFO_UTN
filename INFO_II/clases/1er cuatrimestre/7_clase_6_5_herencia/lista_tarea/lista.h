/*
    Lista contará con un método público denominado: int insertar (int); el cual recibe el dato y lo
    insertará de forma ordenada (de menor a mayor), si se produce error devuelve -1
*/

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "colapila.h"

class lista: public ColaPila
{
public:
    lista();
    lista(int);
    lista(const lista&);
    ~lista();

    int insertar(int);
    int Retirar(int);

};

#endif // LISTA_H
