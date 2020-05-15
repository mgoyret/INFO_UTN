#include "punto.h"

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int main()
{
    punto p(1234.56);
    punto r(12,34);
    cout <<"1. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    p.setY(3.33);
    r.set_punto(p);
    cout <<"3. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    PRESS_KEY;
}
