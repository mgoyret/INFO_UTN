#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "punto.h"
#include <iostream>

using namespace std;

const int EXITO = 1;
const int ERROR = 0;

punto operator+ (const punto& i, const punto&);
punto operator- (const punto& i, const punto&);

int operator==(const punto&, const punto&);
int operator!=(const punto&, const punto&);
int operator<(const punto&, const punto&);
int operator>(const punto&, const punto&);
ostream& operator<<(ostream&, const punto&);
istream& operator>>(istream&, punto&);

#endif // FUNCTIONS_H
