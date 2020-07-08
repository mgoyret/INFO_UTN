#include "cola.h"

using namespace  std;


Cola::Cola(int valor)
{

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

        //incremento la cantidad de nodos
        cantidad++;

        res = valor;
    }

    return res ;


}

int Cola::RetirarElemento()
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

    return val;

}

void Cola::Listar()
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

/*
void Cola::Liberar()
{
    nodo *aux;
    aux = h;

    if(aux ==nullptr)
    {
        cout << "No hay nodos en la cola" << endl;

    }
    else
    {
        //tomo el primer elemento
        h = aux->sig;
        delete aux;

        while(h!=nullptr)
        {
            h = aux->sig;
            if(h!=nullptr)
                delete aux;

        }
    }


}
*/

bool Cola::EstaVacio()
{
    bool res = true;

    if(h!=nullptr)
        res = false;

    return res;



}


Cola::~Cola()
{




}
