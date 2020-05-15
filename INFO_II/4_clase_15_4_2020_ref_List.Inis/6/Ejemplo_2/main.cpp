#include <iostream>
using std::cout;
using std::endl;

class Numero
{
    /*                   PARA TENER EN CUENTA.
        No es necesario poner las dos palabras public y private, la opción
        por defecto es private, de modo que todas las variables y funciones
        miembro son private excepto las indicadas expresamente como public.
    */

    friend void establecer(double ,Numero &);   //establecer es una funcion amiga.
//    double x;//dato miembro.

    public:
        Numero(double); // Constructor sobrecargado.
        void mostrar(); // Metodo publico

    private:
        double x;//dato miembro.
};

//void establecer(double ,Numero &);

Numero::Numero(double b)
{
  x = b;
}

void Numero::mostrar()
{
  cout << "El numero es: " << x << endl;
}

void establecer(double a, Numero &objeto)
{
  objeto.x = a; //puede modificar el dato miembro porque es amiga.
}

int main()
{
  cout << "Creamos el objeto Pi" << endl;
  Numero Pi(7.8);
  Pi.mostrar();

  cout << "Modificamos con la funcion amiga" << endl;

  establecer(3.14,Pi);//utilizamos la funcion amiga.
  Pi.mostrar();
  return 0;
}
