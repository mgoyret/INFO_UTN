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

IntArr& IntArr::operator=(const IntArr& arr)
{
    int i;
    if(p != arr.p)
    {
        p = new int [arr.size];
        if(p != nullptr)
        {
            size = arr.size;
            for(i=0;i<arr.used;i++)
                p[i]=arr.p[i];
            used=arr.used;
        }
    }
    return (*this);
}

IntArr& IntArr::operator+=(const IntArr& arr)
{
    addElement(used, arr.used, arr.p);
    return (*this);
}

/* FUNCIONES FRIEND */
ostream& operator<<(ostream& os, const IntArr& arr)
{
    int i;
    os << "Array <size:"<<arr.size<<">-<used:"<<arr.used<<">"<<endl;
    if(arr.used == 0)
        os << "Array Vacio" << endl;
    else
    {
        os << "[";
        for(i=0;i<arr.used-1;i++)
        {
            os << arr.p[i] << "; ";
        }
        os << arr.p[i] << "]" << endl;
    }

    return os;
}

IntArr operator+(const IntArr& p, const IntArr& q)
{
    IntArr res(p.used + q.used, p.used, p.p);
    res.addElement(res.used, q.used, q.p);

    return res;
}
