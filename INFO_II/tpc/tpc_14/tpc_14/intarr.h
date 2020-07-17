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
        ~IntArr();
        void prtArr (void) const;
        void prtArr (int) const;

        int getSize(){return size;}
        int getUsed(){return used;}
        double getAvg();

        void addElement(int);
        void addElement(int, int*);
};

#endif // INTARR_H
