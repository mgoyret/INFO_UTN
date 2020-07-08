#include "colapila.h"
#include <iostream>

using namespace  std;

//constructor parametrizado
ColaPila::ColaPila(int valor)
{
    h = new nodo;
    if(h != nullptr)
    {
        cantidad = 1;
        h->valor = valor;
        h->sig = nullptr;

        cout << this << " - constructor parametrizado clase ColaPila" << endl;
        cout << "h->valor = " << h->valor << endl;
        cout << "h->sig = " << h->sig << endl;
        cout << "cantidad = " << cantidad << endl;
    }
}


//constructor de copia
ColaPila::ColaPila(const ColaPila& orig)
{
    int i = 0;
    nodo *aux, *aux2;

    h = new nodo;
    if(h != nullptr)
    {
        h->sig = nullptr;
        aux = h;
        aux2 = orig.h;
        cantidad = orig.cantidad;

        aux->valor = aux2->valor;
        aux->sig = nullptr;
        i++;
        while(i < cantidad)
        {
            if((aux->sig = new nodo) != nullptr)
            {
                aux = aux->sig;
                aux2 = aux2->sig;
                aux->valor = aux2->valor;
                aux->sig = nullptr;
                i++;
            }
        }
    }
}


//destructor
ColaPila::~ColaPila()
{
    if(cantidad > 0)
    {
        Liberar();
        delete h;
    }
    cout << this << " - destructor clase ColaPila" << endl;
}

int ColaPila::AgregarFinal(int valor) //cola
{
    int res = -1;
    nodo *aux;

    aux = new nodo;

    if(aux != nullptr)
    {
        //cargo el nodo
        aux->valor = valor;
        aux->sig = nullptr;

        if(h==nullptr)
        {
            //si es el primero
            h = aux ;
        }
        else
        {
            nodo *ult;
            ult = h ;

            //voy hasta el final
            while(ult->sig != nullptr)
                ult = ult->sig ;

            ult->sig =  aux;
        }
        cantidad++;

        res = valor;
    }
    //retorna el valor agregado o -1 en caso de error
    return res ;
}

int ColaPila::AgregarDelante(int valor) //PIlA
{
    int res = -1;
    nodo *aux;

    aux = new nodo;
    if(aux != nullptr)
    {
        //cargo el nodo
        aux->valor = valor;
        aux->sig = h;
        h = aux;
        res = valor;
    }
    cantidad++;

    //retorna el valor agregado o -1 en caso de error
    return res ;
}

int ColaPila::RetirarDelante()
{
    int val = -1;

    nodo *aux=h;

    if(aux!= nullptr)
    {
        //guardo el valor a retornar
        val = aux->valor;
        //me muevo en la cola
        h= aux->sig;
        //libero el nodo
        delete aux;
        //actualizo el contador de nodos
        cantidad--;
    }

    //retorna el valor retirado, o -1 en caso de error
    return val;
}

bool ColaPila::EstaVacio()
{
    bool res = true;

    if(h!=nullptr)
        res = false;
    return res;
}

void ColaPila::Listar()
{
    nodo *aux;
    aux = h;
    cout << "cantidad = " << cantidad << endl;
    if(aux !=nullptr)
    {
        if(aux->sig == nullptr)
            cout<< "Valor: " << aux->valor << endl;
        else
        {
            while(aux !=nullptr)
            {
                cout<< "Valor: " << aux->valor << endl;
                aux = aux->sig ;
            }
        }
    }
}

void ColaPila::Liberar()
{
    int i = 0, cant = cantidad;
    while(i < cant)
    {
        cout << "retire: " << RetirarDelante() << endl;
        i++;
    }
}
