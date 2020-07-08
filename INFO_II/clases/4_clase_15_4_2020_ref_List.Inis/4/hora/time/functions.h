#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class time
{
    public:
        time();
        time(const time&);

        int geth();
        int getm();
        int gets();

        void seth(int);
        void setm(int);
        void sets(int);

        void unitime();
        void stdtime();
private:
        int h, m, s;
};

#endif // FUNCTIONS_H
