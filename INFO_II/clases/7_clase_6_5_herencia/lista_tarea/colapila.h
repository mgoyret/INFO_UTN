#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo *sig;
};

class ColaPila
{
protected:
    int cantidad;
    nodo *h;
public:

    ColaPila():cantidad(0),h(nullptr){cout << this << " - constructor por defecto clase ColaPila" << endl;}

    //constructor sobrecargado
    ColaPila(int);

    //constructor de copia
    ColaPila(const ColaPila&);

    //destructor
    ~ColaPila();

    inline int GetCantidad() {return cantidad;}
    int AgregarFinal(int); //cola
    int AgregarDelante(int); //pila
    int RetirarDelante();
    bool EstaVacio();
    void Listar();
    void Liberar();

};

#endif // NODO_H
