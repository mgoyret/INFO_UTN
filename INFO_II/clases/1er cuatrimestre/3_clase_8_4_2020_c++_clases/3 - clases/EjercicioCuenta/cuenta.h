#ifndef CUENTA_H
#define CUENTA_H


class Cuenta
{
    public:
        //constructor por defecto
        Cuenta();

        //consultor
        int ObtenerSaldo();

        //modificador
        void CargarSaldo(int);


    private:
        int saldo;


};

#endif // CUENTA_H
