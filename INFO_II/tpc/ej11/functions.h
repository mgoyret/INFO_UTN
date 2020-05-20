#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "punto.h"
#include <iostream>

using namespace std;

const int EXITO = 1;
const int ERROR = 0;

Punto operator+ (const Punto& i, const Punto&);
Punto operator- (const Punto& i, const Punto&);

int operator==(const Punto&, const Punto&);
int operator!=(const Punto&, const Punto&);
int operator<(const Punto&, const Punto&);
int operator>(const Punto&, const Punto&);
ostream& operator<<(ostream&, const Punto&);
istream& operator>>(istream&, Punto&);

void ff (void);

#endif // FUNCTIONS_H
