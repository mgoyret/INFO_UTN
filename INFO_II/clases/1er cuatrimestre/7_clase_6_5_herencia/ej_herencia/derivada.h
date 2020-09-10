#ifndef DERIVADA_H
#define DERIVADA_H

#include "base.h"

class Derivada : public Base
{  
public:
    Derivada();
    Derivada(float zz);
    Derivada(int xx, float zz);
    ~Derivada();
    float getZ() const { return z; }
    void setZ(float num) {z = num;}
    void display();
    Derivada& operator= (const Derivada&);

private:
    float z;
};

#endif // DERIVADA_H
