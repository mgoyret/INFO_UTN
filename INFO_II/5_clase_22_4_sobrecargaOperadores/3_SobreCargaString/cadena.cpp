#include "cadena.h"

// constructor por defecto
cadena::cadena()
{
    pstr = new char[1];
    strcpy(pstr, "");
    nchar = 0;

}

// constructor general
cadena::cadena(const char* c)
{
    nchar = strlen(c);
    pstr = new char[nchar + 1];
    strcpy(pstr, c);

}

//constructor de copia
cadena::cadena(const cadena& cd)
{
    nchar = cd.nchar;
    pstr = new char[nchar +1];
    strcpy(pstr, cd.pstr);

}

// destructor
cadena::~cadena()
{
    delete [] pstr;

}

// función miembro setcad()
void cadena::setcad(const char* c)
{
    nchar = strlen(c);
    delete [] pstr;
    pstr = new char[nchar + 1];
    strcpy(pstr, c);

}

void cadena::view()
{

    cout << pstr << endl;
}

// operador de asignación
//sobrecargado (=) cadena&
cadena& cadena::operator= (const cadena& cd)
{
    if(*this != cd)
    {
        nchar = cd.nchar;
        delete [] pstr;
        pstr = new char[nchar + 1];
        strcpy(pstr, cd.pstr);
    }
    return *this;

}
/*
//operadores para concatenar cadenas
cadena operator+ (const cadena& a, const cadena&b)
{
    cadena c;
    c.nchar = a.nchar + b.nchar;
    c.pstr = new char[c.nchar + 1];
    strcpy(c.pstr, a.pstr);
    strcat(c.pstr, b.pstr);
    return c;
}
*/

cadena operator+ (const cadena& c1, const cadena& c2)
{
    cadena res;

    res.nchar = c1.nchar + c2.nchar;
    res.pstr = new char[res.nchar + 1];
    strcpy(res.pstr, c1.pstr);
    strcat(res.pstr, c2.pstr);

    return(res);
}

cadena operator+ (const cadena& a, const char*ch)
{
    cadena c;
    c.nchar = a.nchar + strlen(ch);
    c.pstr = new char[c.nchar + 1];
    strcpy(c.pstr, a.pstr);
    strcat(c.pstr, ch);
    return c;
}

cadena operator+(const char* ch,const cadena&b)
{
    cadena c;
    c.nchar = strlen(ch) + b.nchar;
    c.pstr = new char[c.nchar + 1];
    strcpy(c.pstr, ch);
    strcat(c.pstr, b.pstr);
    return c;
}

// sobrecarga de los operadores relacionales
int operator== (const cadena& c1, const cadena& c2)
{
    if(strcmp(c1.pstr, c2.pstr)==0)
        return 1;
    return 0;
}

int operator!= (const cadena& c1, const cadena& c2)
{
    int dif = strcmp(c1.pstr, c2.pstr);

    if(dif<0)
        return (-1);

    if(dif==0)
        return 0;
    else
        return 1;
}

