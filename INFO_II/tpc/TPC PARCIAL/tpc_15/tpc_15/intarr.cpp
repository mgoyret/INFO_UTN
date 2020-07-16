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
    used = 0;//la inicializo para luego posincrementarla
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

void IntArr::addElement(int pos, int xx)
{
    int i;
    int *aux;

    if(pos<0)
        pos = 0;
    if(pos>used)
        pos=used;

    if(used == size) //used nunca es mayor a size
        aux = new int[++size];
    else
        aux = new int[size];
    if(aux != nullptr)
    {
        for(i=0;i<pos;i++)
            aux[i]=p[i];

        aux[pos]=xx;

        for(i=0;i<used+1;i++)
            aux[pos+1+i]=p[pos+i];

        used++;
        delete[]p;
        p=aux;
    }
}

void IntArr::addElement(int pos, int qtty, int* vec)
{
    int i;
    int *aux;

    if(pos<0)
        pos = 0;
    if(pos>used)
        pos=used;

    /* Pidieron que pidamos 5 posiciones mas de las nesesarias */
    if(used+qtty+5 <= size)
        aux = new int[size];
    else
        aux = new int[used+qtty+5];
    if(aux != nullptr)
    {
        for(i=0;i<pos;i++)
            aux[i]=p[i];

        for(i=0;i<qtty;i++)
            aux[pos+i]=vec[i];

        for(i=pos;i<used;i++)
            aux[i+qtty]=p[i];

        if(used+qtty+5>size)
            size = used+qtty+5;
        used += qtty;

        delete[]p;
        p=aux;
    }
}
