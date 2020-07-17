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

        //void addElement(int);
        //void addElement(int, int*);
        void addElement (int, int);
        void addElement (int, int, int*);

        IntArr& operator=(const IntArr&);
        IntArr& operator+=(const IntArr&);
        friend ostream& operator<<(ostream&, const IntArr&);
        friend IntArr operator+(const IntArr&, const IntArr&);
};

#endif // INTARR_H
