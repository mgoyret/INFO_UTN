#include "pila.h"

using namespace  std;

pila::pila(int valor)
{
    h = new nodo;
    if(h != nullptr)
    {
        h->valor = valor;
        h->sig = nullptr;
    }
}

//constructor de copia
/*
    La funcion AgregarElemento() armaba la pila al revez por su implementacion, por lo que se implemento
    un metodo especifico para agregar los elementos al utilizar el constructor de copia
*/
pila::pila(const pila &orig)
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

pila::~pila()
{
    int i = 0;

    while(i < cantidad)
    {
        RetirarElemento();
        i++;
    }
}


int pila::AgregarElemento(int valor)
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

    }

        //incremento la cantidad de nodos
    cantidad++;
    res = valor;

    return res ;
}

int pila::RetirarElemento()
{
    int val = -1;

    nodo *aux=h;

    if(aux!= nullptr)
    {
        //guardo el valor a retornar
        val = aux->valor;

        //me muevo en la pila
        h= aux->sig;

        //libero el nodo
        delete aux;

        //actualizo el contador de nodos
        cantidad--;

    }

    return val;

}

void pila::Listar()
{
    nodo *aux ;
    aux = h;

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

bool pila::EstaVacio()
{
    bool res = true;

    if(h!=nullptr)
        res = false;

    return res;



}
