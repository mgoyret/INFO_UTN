#ifndef PILA_H
#define PILA_H

#include <iostream>

struct nodo {
    int valor;
    nodo *sig;
};


class pila
{

private:
    int cantidad;
    nodo *h;

public:
    //constructor
    pila():cantidad(0),h(nullptr){}

    //constructor sobrecargado
    pila(int valor);

    //constructor de copia
    pila(const pila &);

    //destructor
    ~pila();

    inline int GetCantidad() {return cantidad;}

    int AgregarElemento(int);
    int RetirarElemento();
    bool EstaVacio();
    void Listar();

};

#endif // PILA_H
