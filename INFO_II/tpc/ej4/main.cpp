#include "punto.h"

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int main()
{
    punto p(12.34,-56.78);
    punto r(p);
    punto q=p;
    cout <<"1. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    cout <<"3. punto q: ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    PRESS_KEY;
}
