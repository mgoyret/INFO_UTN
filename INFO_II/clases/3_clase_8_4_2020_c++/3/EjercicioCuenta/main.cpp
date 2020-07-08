#include <iostream>
#include "cuenta.h"

using namespace std;

int main()
{
    int valor;

    cout << "Ejemplo cuenta" << endl;
    cout << "Cargar saldo de la cuenta: " ;
    cin >> valor;

    cout << "Ingresaste: " << valor << endl;

    Cuenta MiCuenta;

    MiCuenta.CargarSaldo(valor);

    cout << "Saldo asignado: " << MiCuenta.ObtenerSaldo() << endl;

    cout << "Cargar saldo de la cuenta: " ;
    cin >> valor;

    cout << "Ingresaste: " << valor << endl;

    MiCuenta.CargarSaldo(valor);

    cout << "Saldo asignado: " << MiCuenta.ObtenerSaldo() << endl;

    return 0;
}
