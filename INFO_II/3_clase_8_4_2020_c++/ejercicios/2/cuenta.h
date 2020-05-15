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

        //recibe como argumento el dinero a retirar y devuelve el dinero extraido,
        //asumimos en esta instancia que hay plata suficiente y se puede extraer lo que se necesite
        int TransferirDinero(int);


    private:
        int saldo;
};

#endif // CUENTA_H
