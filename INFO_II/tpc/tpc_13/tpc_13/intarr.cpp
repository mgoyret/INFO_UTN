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

void IntArr::prtArr(int cnt) const
{
    int i;
    if(cnt > size)
    {
        cout << "Se solicitan " << cnt << " elementos pero solo hay " << size << endl;
        cnt = size;
    }

    if(used > 0)
    {
        cout << "Array: [";
        /* size-1 para al ultimo elemento agregarle el corchete y no poner los ':' */
        for(i=0; i<cnt-1; i++)
        {
            cout << p[i] << "; ";
        }
        cout << p[i] << "]" << endl;
    }
    else
        cout << "Array: VACIO" << endl;
}

double IntArr::getAvg()
{
    int i;
    double exit=0, suma = 0;

    for(i=0; i<used;i++)
        suma += p[i];
    exit = suma/used;

    return exit;
}
