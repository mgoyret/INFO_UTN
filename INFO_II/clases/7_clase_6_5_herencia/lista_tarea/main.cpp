#include <iostream>
#include "colapila.h"
#include "lista.h"

using namespace std;

int main()
{
    int i = 1, j;
    lista list1;
    lista listP(10);
    cout << endl << endl << "BIENVENIDA DEL MAIN" << endl << endl;

    cout << "Agregue nodos a list1 (-1 para finalizar)" << endl;
    cout << "ingrese: ";
    cin >> i;
    while(i != -1)
    {
        list1.insertar(i);
        cout << "ingrese: ";
        cin >> i;
    }
    cout <<endl << "visualizando list1" << endl;
    list1.Listar();

    cout <<endl<< "Agregue nodos a listP (-1 para finalizar)" << endl;
    cout << "ingrese: ";
    cin >> i;
    while(i != -1)
    {
        listP.insertar(i);
        cout << "ingrese: ";
        cin >> i;
    }
    cout << endl << "visualizando listP" << endl;
    listP.Listar();

    cout << endl<< "retirar elemento de list1 (-1 para finalizar)" << endl;
    cout << "valor a retirar: ";
    cin >> i;
    while(i != -1)
    {
        if(list1.GetCantidad() == 0)
        {
            cout << "no hay elementos" << endl;
            break;
        }
        j = list1.Retirar(i);
        if(j != -1)
        {
            cout << "valor [" << j << "] retirado" << endl;
        }
        cout << "valor a retirar: ";
        cin >> i;
    }
    list1.Listar();

    cout <<endl<< "Coppio list1 y muestro la copia" << endl;
    lista list2(list1);
    list2.Listar();

    cout << endl<< "liberamos listP" << endl;
    listP.Liberar();
    listP.Listar();

    cout << endl<< endl<< "FIN DEL MAIN" << endl;
    return 0;
}
