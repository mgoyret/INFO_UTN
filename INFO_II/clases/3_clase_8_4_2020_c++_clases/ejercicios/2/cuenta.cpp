#include "cuenta.h"

Cuenta::Cuenta()
{
    saldo = 1000;
}


int Cuenta::ObtenerSaldo()
{
    return saldo;

}

void Cuenta::CargarSaldo(int valor)
{
    saldo += valor;

}

int Cuenta::TransferirDinero(int valor)
{
    saldo -= valor;
    return valor;
}
