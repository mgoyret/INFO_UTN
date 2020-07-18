#ifndef PRODUCTOENSTOCK_H
#define PRODUCTOENSTOCK_H

#include "producto.h"
#include "fecha.h"
#include <iostream>

class PRODUCTOenSTOCK: public Producto
{
    private:
        unsigned int Cantidad;
        char* Proveedor;
        Fecha fecha_compra;
    public:
        //PRODUCTOenSTOCK();
        inline PRODUCTOenSTOCK(): Producto(nullptr, 0), fecha_compra(1, 1, 2020)
        {
            Cantidad = 0;
            Proveedor = new char [strlen("proveedor")+1];
            if(Proveedor != nullptr)
            {
                memset(Proveedor, '\0', strlen("proveedor")+1);
                strcpy(Proveedor, "sin proveedor");
            }
        }


        PRODUCTOenSTOCK(char*, int, unsigned int, char*, Fecha);
        PRODUCTOenSTOCK(PRODUCTOenSTOCK&);

        void Set_Datos(char*, int, unsigned int, char*, Fecha);

        PRODUCTOenSTOCK operator++(int);
        PRODUCTOenSTOCK operator--(int);

        friend ostream& operator<<(ostream&, PRODUCTOenSTOCK&);
};

#endif // PRODUCTOENSTOCK_H
