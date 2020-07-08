#include "base.h"
#include <iostream>

Base::Base() : x(0), y(0)
{
    std::cout << this << " - constructor por defecto clase base" << std::endl;
}

Base::Base(int xx) : x(xx)
{
    std::cout << this << " - constructor parametrizado clase base: ";
    std::cout << "x=" << x << std::endl;
    y=0;
}

Base::~Base()
{
    std::cout << this << " - destructor clase base" << std::endl;
}

void Base::display()
{
    std::cout<< "x=" << x << "\t- " << this <<std::endl;
}

Base& Base::operator= (const Base &var)
{
    x = var.x;
    y = var.y;

    return *this;
}
