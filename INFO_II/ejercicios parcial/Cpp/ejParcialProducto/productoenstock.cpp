#include "productoenstock.h"

/* Constructor por defecto */
/*
inline PRODUCTOenSTOCK::PRODUCTOenSTOCK(): Producto(nullptr, 0), fecha_compra(1, 1, 2020)
{
    Cantidad = 0;
    Proveedor = new char [strlen("proveedor")+1];
    if(Proveedor != nullptr)
    {
        memset(Proveedor, '\0', strlen("proveedor")+1);
    }
}
*/
/* Constructor parametrizado */
PRODUCTOenSTOCK::PRODUCTOenSTOCK(char* pName, int pCod, unsigned int cant, char* prov, int d, int m, int a):
                                                                                          Producto(pName, pCod), fecha_compra(d, m, a)
{
    Cantidad = cant;
    Proveedor = new char[strlen(prov)+1];
    if(Proveedor != nullptr)
        strcpy(Proveedor, prov);
}

/* Constructor de copia */
PRODUCTOenSTOCK::PRODUCTOenSTOCK(PRODUCTOenSTOCK& p): Producto(p.Get_Nombre(), p.codigo), fecha_compra(p.fecha_compra)
{
    Cantidad = p.Cantidad;
    Proveedor = new char[strlen(p.Proveedor)+1];
    if(Proveedor != nullptr)
        strcpy(Proveedor, p.Proveedor);
}

void PRODUCTOenSTOCK::Set_Datos(char* pName, int pCod, unsigned int cant, char* prov, int d, int m, int a)
{
    Producto::Set_Nombre(pName);
    codigo = pCod;
    Cantidad = cant;
    Proveedor = new char[strlen(prov)+1];
    if(Proveedor != nullptr)
        strcpy(Proveedor, prov);
    fecha_compra=Fecha(d, m, a);
}

PRODUCTOenSTOCK PRODUCTOenSTOCK::operator++(int)
{
    PRODUCTOenSTOCK aux(*this);
    Cantidad++;
    return aux;
}

PRODUCTOenSTOCK PRODUCTOenSTOCK::operator--(int)
{
    PRODUCTOenSTOCK aux(*this);
    if(Cantidad>0)
    {
        Cantidad--;
    }else
        cout<<"No hay stock"<<endl;

    return aux;
}

ostream& operator<<(ostream& os, PRODUCTOenSTOCK& p)
{
    p.Producto::operator<<(os);
    os << "CANTIDAD: "<<p.Cantidad<<"\t\tProveedor: "<<p.Proveedor<<endl;
    os << p.fecha_compra;

    return os;
}
