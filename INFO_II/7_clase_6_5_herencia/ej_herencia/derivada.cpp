#include "derivada.h"
#include <iostream>

Derivada::Derivada()
{
    z = 0.0;
    std::cout << this << " - constructor por defecto clase derivada" << std::endl;
}

Derivada::Derivada(float zz)
{
    z = zz;
    std::cout << this << " - constructor parametrizado clase derivada: ";
    std::cout << "z=" << z << std::endl;
}

Derivada::Derivada(int xx, float zz) : Base(xx)
{
    z = zz;
    std::cout << this << " - constructor parametrizado clase derivada+base: " ;
    std::cout << "x=" << Base::getX() << " z=" << z << std::endl;
}

Derivada::~Derivada()
{
    std::cout << this << " - destructor clase derivada" << std::endl;
}

void Derivada::display()
{
    std::cout << "z=" << z << "\t- " << this << std::endl;
    std::cout << "y=" << y << "\t- " << this << std::endl;
    Base::display();

}

Derivada& Derivada::operator=(const Derivada& var)
{
    z = var.z;
    Base::operator=(var);
    return  *this;
}
