#ifndef COLA_H
#define COLA_H

#include <iostream>

struct nodo {
    int valor;
    nodo *sig;
};


class Cola
{

private:
    int cantidad;
    nodo *h;

public:
    //constructor por defecto
    Cola():cantidad(0),h(nullptr){}

    //constructor sobrecargado
    Cola(int valor);

    //constructor de copia
    Cola(const Cola &);

    //destructor
    ~Cola();

    inline int GetCantidad() {return cantidad;}

    int AgregarElemento(int);
    int RetirarElemento();
    void Liberar();
    bool EstaVacio();
    void Listar();

};

#endif // COLA_H
