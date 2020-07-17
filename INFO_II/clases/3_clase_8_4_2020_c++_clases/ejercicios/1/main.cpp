#include <iostream>
#include "cuenta.h"

using namespace std;

int main()
{
    int  op;

    cout << "Ejemplo cuenta" << endl;

    Cuenta MiCuenta;

    cout << "saldo actual: " << MiCuenta.ObtenerSaldo() << endl;

    do
    {
        cout << "1 - Ingresar saldo\n2 - Retirar saldo\n3 - Finalizar" << endl;
        cout << "opcion: ";
        cin >> op;
        cout << "\n";

        int valor;
        switch (op)
        {
            case 1:
                    cout << "Cargar saldo: " ;
                    cin >> valor;
                    cout << "Ingresaste: " << valor << endl;
                    MiCuenta.CargarSaldo(valor);
                    cout << "Saldo actual: " << MiCuenta.ObtenerSaldo() << endl << endl;
                break;
            case 2:
                    cout << "Retirar saldo: " ;
                    cin >> valor;
                    cout << "Ingresaste: " << valor << endl;
                    cout << "Saldo actual: " << MiCuenta.RetirarDinero(valor) <<endl << endl;
                break;
        default:
                break;
        }
    } while ((op == 1) || (op == 2));

    if(MiCuenta.HaySaldo()>0)
    {
        cout << "hay guita!!" << endl << endl;
    }
    else
    {
        cout << "Estas pobre" << endl << endl;
    }

    return 0;
}
