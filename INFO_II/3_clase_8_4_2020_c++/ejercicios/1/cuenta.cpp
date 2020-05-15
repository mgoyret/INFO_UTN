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

bool Cuenta::HaySaldo()
{
    bool out;
    if(Cuenta::ObtenerSaldo() > 0)
    {
        out = TRUE;
    }
    else
    {
        out = FALSE;
    }
    return out;
}

int Cuenta::RetirarDinero(int valor)
{
    saldo -= valor;
    return saldo;
}
