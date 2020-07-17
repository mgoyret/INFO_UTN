#include "producto.h"
#include <iostream>
#include <stdio.h>

using namespace std;

/* constructor parametrizado */
Producto::Producto(char* nom, int cod)
{
    codigo = cod;
    if(nom != nullptr)
    {
        nombre = new char [strlen(nom)+1];
        if(nombre != nullptr)
            strcpy(nombre, nom);
    }else
    {
        nombre = new char [strlen("sin nombre")+1];
        memset(nombre, '\0', strlen("sin nombre")+1);
        strcpy(nombre, "sin nombre");
    }
}

void Producto::Set_Datos(char* nom, int cod)
{
    codigo = cod;
    Set_Nombre(nom);
}

void Producto::Set_Nombre (char* nom)
{
    if(nombre != nullptr)
        delete nombre;
    if(nom != nullptr)
    {
        nombre = new char [strlen(nom)+1];
        if(nombre != nullptr)
            strcpy(nombre, nom);
    }else
    {
        nombre = new char [strlen("sin nombre")+1];
        memset(nombre, '\0', strlen("sin nombre")+1);
        strcpy(nombre, "sin nombre");
    }
}

/* Esta funcion pide memoria que deberia ser liberada desde el main. MALA PRACTICA pero es lo que piden... */
char* Producto::Get_Nombre(void)
{
    char* nom = nullptr;
    nom = new char[strlen(nombre)+1];
    if(nom != nullptr)
        strcpy(nom, nombre);
    return nom;
}


ostream& operator<<(ostream& os, const Producto& pro)
{
    os <<"PRODUCTO NOMBRE: "<<pro.nombre<<"\t\tCODIGO: "<<pro.codigo << endl;
    return os;
}


// Para llamarlo desde la sobrecarga en la clase derivada
ostream& Producto::operator<<(ostream& os)
{
    os <<"PRODUCTO NOMBRE: "<<nombre<<"\t\tCODIGO: "<<codigo << endl;
    //os <<"PRODUCTO NOMBRE: "<<nombre<<"\t\t"<<"CODIGO: "<<codigo << endl;
    return os;
}

