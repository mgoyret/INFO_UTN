#ifndef CUENTA_H
#define CUENTA_H


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


    private:
        int saldo;


};

#endif // CUENTA_H
