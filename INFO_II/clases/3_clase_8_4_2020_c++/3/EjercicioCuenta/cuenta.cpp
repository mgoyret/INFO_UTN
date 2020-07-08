#include "cuenta.h"

Cuenta::Cuenta()
{
    saldo = 0;
}


int Cuenta::ObtenerSaldo()
{
    return saldo;

}

void Cuenta::CargarSaldo(int valor)
{
    saldo += valor;

}
