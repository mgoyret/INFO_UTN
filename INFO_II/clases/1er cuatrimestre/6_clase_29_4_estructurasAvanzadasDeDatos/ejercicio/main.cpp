#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
    pila mipila;
    int aux;

    cout << "-----------------------------------" << endl;
    cout << "Inserto el primer elemento" <<endl;
    mipila.AgregarElemento(5);
    mipila.Listar();
    cout << "Cantidad: " << mipila.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;


    cout << "-----------------------------------" << endl;
    cout << "inserto nuevamente" <<endl;
    mipila.AgregarElemento(3);
    mipila.Listar();
    cout << "Cantidad: " << mipila.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;



    cout << "-----------------------------------" << endl;
    cout << "inserto nuevamente" <<endl;

    mipila.AgregarElemento(8);
    mipila.Listar();
    cout << "Cantidad: " << mipila.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;

/////////////////////////////


    cout << "-----------------------------------" << endl;
    cout << "copia" <<endl;

    pila pila2(mipila);
    pila2.Listar();
    cout << "Cantidad: " << pila2.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;



//////////////////////////////

    cout << "-----------------------------------" << endl;
    cout << "remuevo elemento" <<endl;
    aux = mipila.RetirarElemento();

    if(aux!= -1)
    {
    cout << "Retiro: " << aux << endl;
    mipila.Listar();
    cout << "Cantidad: " << mipila.GetCantidad()<<endl;
    }
    else
    {
        cout << "No hay elementos para retirar" <<endl;
    }


    cout << "-----------------------------------" << endl;


    cout << "-----------------------------------" << endl;
    cout << "remuevo elemento" <<endl;
    aux = mipila.RetirarElemento();

    if(aux!= -1)
    {
    cout << "Retiro: " << aux << endl;
    mipila.Listar();
    cout << "Cantidad: " << mipila.GetCantidad()<<endl;
    }
    else
    {
        cout << "No hay elementos para retirar" <<endl;
    }


    cout << "-----------------------------------" << endl;


    cout << "-----------------------------------" << endl;
    cout << "remuevo elemento" <<endl;
    aux = mipila.RetirarElemento();

    if(aux!= -1)
    {
    cout << "Retiro: " << aux << endl;
    mipila.Listar();
    cout << "Cantidad: " << mipila.GetCantidad()<<endl;
    }
    else
    {
        cout << "No hay elementos para retirar" <<endl;
    }


    cout << "-----------------------------------" << endl;




    return 0;
}

