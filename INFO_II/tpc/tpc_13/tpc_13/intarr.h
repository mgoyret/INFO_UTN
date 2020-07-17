#ifndef INTARR_H
#define INTARR_H

#include <iostream>

using namespace std;

class IntArr
{
    private:
        int * p;
        int size;
        int used;
    public:
        IntArr (int sz);
        IntArr (int sz,int qtty,int *vec);
        ~IntArr(){delete[] p;}
        void prtArr (void) const;
        void prtArr (int) const;

        int getSize(){return size;}
        int getUsed(){return used;}
        double getAvg();
};

#endif // INTARR_H
