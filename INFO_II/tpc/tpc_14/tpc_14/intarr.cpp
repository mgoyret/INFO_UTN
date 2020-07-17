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

IntArr::~IntArr()
{
    if(p != nullptr)
        delete []p;
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

void IntArr::addElement(int xx)
{
    int i;
    int *aux;
    if(used<size)
        p[used++] = xx;
    /* La consigna pedia agregar 5 posiciones mas de las nesecitadas */
    else if( (aux = new int [size+1 +5]) != nullptr)
    {
        for(i=0;i<size;i++)
            aux[i] = p[i];
        aux[i] = xx;
        size += 1 + 5;
        used++;
        delete[] p;
        p=aux;
    }
}

void IntArr::addElement(int qtty, int* vec)
{
    int i;
    int* aux;
    if((used+qtty) <= size)
    {
        for(i=0;i<qtty;i++)
            p[used++] = vec[i];
    }
    else if( (aux = new int [used+qtty +5]) != nullptr)
    {
        size = used + qtty +5;
        for(i=0;i<used;i++)
            aux[i]=p[i];

        for(i=0;i<qtty;i++)
            aux[used++]=vec[i];

        delete[]p;
        p=aux;
    }
}
