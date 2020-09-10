#include "cuenta.h"

Cuenta::Cuenta()
{
    saldo = 0;
}

Cuenta::Cuenta(int monto)
{
    saldo = monto;
}

Cuenta::Cuenta(const Cuenta& Cref): saldo(Cref.saldo) {}

int Cuenta::ObtenerSaldo()
{
    return saldo;

}

void Cuenta::CargarSaldo(int valor)
{
    saldo += valor;

}

ostream& operator<< (ostream& os, const Cuenta& c)
{
    os << "El saldo de la cuenta es: " << c.saldo << endl;
    return os;
}
