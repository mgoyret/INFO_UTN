#include "cola.h"

using namespace  std;


Cola::Cola(int valor1)
{
    h = new nodo;
    if(h != nullptr)
    {
        h->valor = valor1;
        h->sig = nullptr;
        cantidad++;
    }
}

Cola::~Cola()
{
    cout << "Inicia destructor" << endl;

    int i=0, auxCant = cantidad;
    while(i < auxCant)
    {
        cout << "Retirando" << RetirarElemento() << endl;
        i++;
    }

    cout << "Finaliza destructor" << endl;
}

int Cola::AgregarElemento(int valor)
{
    int res = -1;
    nodo *aux;

    aux = new nodo;

    if(aux != nullptr)
    {
        //cargo el nodo
        aux->valor = valor;
        aux->sig = nullptr;

        // si es el primero
        if(h==nullptr)
        {
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

        //incremento la cantidad de nodos
        cantidad++;

        res = valor;
    }

    return res ;


}

int Cola::RetirarElemento()
{
    int val = -1;
    nodo *aux;

    aux = h;
    if(aux != nullptr)
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
    return val;
}

void Cola::Listar()
{
    nodo *aux ;
    aux = h;

    if(aux !=nullptr)
    {
        // Si hay solo un elemento en la lista (el primero es el ultimo)
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


bool Cola::EstaVacio()
{
    bool res = true;

    if(h != nullptr)
        res = false;

    return res;
}
