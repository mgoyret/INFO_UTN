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

        //devuelve true si el saldo es mayor que cero
        //devuelve false en caso contrario
        bool HaySaldo();

        //recibe como argumento el dinero a retirar y devuelve el saldo luego de la extracción,
        //asumimos en esta instancia que hay plata suficiente y se puede extraer lo que se necesite
        int RetirarDinero(int);


    private:
        int saldo;
        const bool TRUE = 1;
        const bool FALSE = 0;


};

#endif // CUENTA_H
