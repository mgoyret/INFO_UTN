#include "functions.h"

time::time()
{
    h = 0;
    m = 0;
    s = 0;
}

time::time(const time& Tref): h(Tref.h), m(Tref.m), s(Tref.s) {}

int time::geth()
{
    return h;
}

int time::getm()
{
    return m;
}

int time::gets()
{
    return s;
}

void time::seth(int a)
{
    h = a;
}

void time::setm(int a)
{
    m = a;
}

void time::sets(int a)
{
    s = a;
}

void time::unitime()
{
    cout << "" << h << ":" << m << ":" << s << endl;
}

void time::stdtime()
{
    int auxh = h;
    if(auxh > 12)
    {
        auxh -= 12;
        cout << "" << auxh << ":" << m << ":" << s << " PM" << endl;
    }
    else
    {
        cout << "" << auxh << ":" << m << ":" << s << " AM" << endl;
    }
}
