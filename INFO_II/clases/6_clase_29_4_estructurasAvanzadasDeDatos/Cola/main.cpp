#include <iostream>
#include "cola.h"

using namespace std;

int main()
{
    Cola MiCola;
    int aux;

    cout << "-----------------------------------" << endl;
    cout << "Inserto el primer elemento" <<endl;
    MiCola.AgregarElemento(5);
    MiCola.Listar();
    cout << "Cantidad: " << MiCola.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;


    cout << "-----------------------------------" << endl;
    cout << "inserto nuevamente" <<endl;
    MiCola.AgregarElemento(3);
    MiCola.Listar();
    cout << "Cantidad: " << MiCola.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;



    cout << "-----------------------------------" << endl;
    cout << "inserto nuevamente" <<endl;

    MiCola.AgregarElemento(8);
    MiCola.Listar();
    cout << "Cantidad: " << MiCola.GetCantidad()<<endl;
    cout << "-----------------------------------" << endl;



    cout << "-----------------------------------" << endl;
    cout << "remuevo elemento" <<endl;
    aux = MiCola.RetirarElemento();

    if(aux!= -1)
    {
    cout << "Retiro: " << aux << endl;
    MiCola.Listar();
    cout << "Cantidad: " << MiCola.GetCantidad()<<endl;
    }
    else
    {
        cout << "No hay elementos para retirar" <<endl;
    }


    cout << "-----------------------------------" << endl;


    cout << "-----------------------------------" << endl;
    cout << "remuevo elemento" <<endl;
    aux = MiCola.RetirarElemento();

    if(aux!= -1)
    {
    cout << "Retiro: " << aux << endl;
    MiCola.Listar();
    cout << "Cantidad: " << MiCola.GetCantidad()<<endl;
    }
    else
    {
        cout << "No hay elementos para retirar" <<endl;
    }


    cout << "-----------------------------------" << endl;


    cout << "-----------------------------------" << endl;
    cout << "remuevo elemento" <<endl;
    aux = MiCola.RetirarElemento();

    if(aux!= -1)
    {
    cout << "Retiro: " << aux << endl;
    MiCola.Listar();
    cout << "Cantidad: " << MiCola.GetCantidad()<<endl;
    }
    else
    {
        cout << "No hay elementos para retirar" <<endl;
    }


    cout << "-----------------------------------" << endl;

    // Para probar destructor
    cout << "Creo nodo con 1, 2, 4" << endl;
    MiCola.AgregarElemento(1);
    MiCola.AgregarElemento(2);
    MiCola.AgregarElemento(4);
    MiCola.Listar();




    return 0;
}

