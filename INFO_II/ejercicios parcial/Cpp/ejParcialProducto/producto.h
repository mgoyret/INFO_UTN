#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <ostream>
#include <string.h>
#include <string>

using namespace std;

class Producto
{
   private:
      char* nombre;

  protected:
      int codigo;

   public:
      /* constructor parametrizado con valores iniciales triviales */
      Producto(char* nom, int = 0);
      /* constructor de copia */
      Producto(Producto& prod): Producto(prod.nombre, prod.codigo){}
      /* destructor inline */
      ~Producto(){delete [] nombre;}

      void Set_Datos(char*, int);
      void Set_Nombre (char*);
      char* Get_Nombre(void);
      friend ostream& operator<<(ostream&, const Producto&);
      ostream& operator<<(ostream&);
};

#endif // PRODUCTO_H
