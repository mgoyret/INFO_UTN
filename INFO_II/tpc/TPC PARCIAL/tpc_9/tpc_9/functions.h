#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "punto.h"
#include <iostream>
#include <cmath>

Punto operator+(const Punto&, const Punto&);
Punto operator-(const Punto&, const Punto&);
int operator<(const Punto&, const Punto&);
int operator>(const Punto&, const Punto&);
int operator!=(const Punto&, const Punto&);
int operator==(const Punto&, const Punto&);
ostream& operator<<(ostream&, const Punto&);
istream& operator>>(istream&, Punto&);

void ff (void);

#endif // FUNCTIONS_H
