//Implementar un programa que genere dos instancias de la clase cuenta, una denominada origen y otra destino.
//Se retira dinero de la cuenta origen y se deposita en  la cuenta destino, es decir, una transferencia.

#include <iostream>
#include "cuenta.h"

using namespace std;

int main()
{
    Cuenta origen, destino;
    int valor;

    cout << "Origen dispone de:\t$" << origen.ObtenerSaldo() << endl;
    cout << "Destino dispone de:\t$" << destino.ObtenerSaldo() << endl;
    cout << "cuanto desea transferir al destino?" <<endl;
    cout  << "Monto: ";
    cin >> valor;

    destino.CargarSaldo(origen.TransferirDinero(valor));

    cout << "Origen dispone de: $" << origen.ObtenerSaldo() << endl;
    cout << "Destino dispone de: $" << destino.ObtenerSaldo() << endl;

    return 0;
}
