#include <iostream>
#include "punto.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main()
{

    Punto p(1234.56);
    Punto r(12,34);
    cout <<"1. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    p.setY(3.33);
    r.setPunto(p);
    cout <<"3. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    PRESS_KEY;

    return 0;
}
