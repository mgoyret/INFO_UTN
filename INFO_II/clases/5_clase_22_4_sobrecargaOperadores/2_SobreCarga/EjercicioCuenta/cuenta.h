#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
using namespace std;


class Cuenta
{
    public:
        //constructor por defecto
        Cuenta();
        //constructor sobrecargado
        Cuenta(int);
        //constructor de copia
        Cuenta(const Cuenta&);

        //consultor
        int ObtenerSaldo();

        //modificador
        void CargarSaldo(int);

        friend  ostream& operator<< (ostream&, const Cuenta&);


    private:
        int saldo;


};

#endif // CUENTA_H
