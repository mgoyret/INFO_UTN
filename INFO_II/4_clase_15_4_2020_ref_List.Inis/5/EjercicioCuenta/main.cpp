#include <iostream>
#include "cuenta.h"

using namespace std;

int main()
{
    int valor;

    cout << "Ejemplo cuenta" << endl;

/*
    cout << "Cargar saldo de la cuenta: " ;
    cin >> valor;
    cout << "Ingresaste: " << valor << endl;
*/
    /* Este argumento lo recibira el constructor
        que recibe una variable 'int' (en este caso) como parametro */
    Cuenta cuenta1(50);

    cout << "saldo con sobrecarga: " << cuenta1.ObtenerSaldo() << endl;

    /* Este argumento lo recibira el constructor
        que recibe una variable 'class Cuenta' como parametro */
    Cuenta cuenta2(cuenta1);

    cout << "saldo con constructor de copia: " << cuenta2.ObtenerSaldo() << endl;
/*
    cout << "saldo antes: " << cuenta1.ObtenerSaldo() << endl;
    cuenta1.CargarSaldo(valor);

    cout << "Saldo despues: " << cuenta1.ObtenerSaldo() << endl;

    cout << "Cargar saldo de la cuenta: " ;
    cin >> valor;

    cout << "Ingresaste: " << valor << endl;

    cout << "saldo antes: " << cuenta1.ObtenerSaldo() << endl;
    cuenta1.CargarSaldo(valor);

    cout << "Saldo despeus: " << cuenta1.ObtenerSaldo() << endl;
*/
    return 0;
}
