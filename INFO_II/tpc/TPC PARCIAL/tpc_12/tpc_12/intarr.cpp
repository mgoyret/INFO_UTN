#include "intarr.h"

IntArr::IntArr(int sz)
{
    size = sz;
    used = 0;
    p = new int(size);
}

IntArr::IntArr(int sz,int qtty,int *vec)
{
    int i;
    if(sz < qtty)
        size = qtty;
    else
        size = sz;
    p = new int [size];
    for(i=0; i<qtty;i++)
    {
        p[i] = vec[i];
        used++;
    }
}

void IntArr::prtArr(void) const
{
    int i;
    if(used > 0)
    {
        cout << "Array: [";
        /* size-1 para al ultimo elemento agregarle el corchete y no poner los ':' */
        for(i=0; i<used-1; i++)
        {
            cout << p[i] << "; ";
        }
        cout << p[i] << "]" << endl;
    }
    else
        cout << "Array: VACIO" << endl;
}
