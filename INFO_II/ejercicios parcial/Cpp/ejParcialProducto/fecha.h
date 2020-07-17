#ifndef FECHA_H
#define FECHA_H

#include <ostream>

using namespace std;

class Fecha
{
    private:
        int dia; // 1-31
        int mes; // 1-12
        int anio;

    public:
        Fecha( int d, int m, int a): dia(d), mes(m), anio(a){}
        Fecha( Fecha& f): dia(f.dia), mes(f.mes), anio(f.anio){}
        ~Fecha(){}
        friend ostream& operator<<(ostream&, Fecha&);
};

#endif // FECHA_H
