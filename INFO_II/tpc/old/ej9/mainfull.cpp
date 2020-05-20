#include <iostream>
#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();
using namespace std;
/*
    Agregar a la clase Punto, del ejercicio anterior, dos métodos públicos del tipo inline que indiquen la
    cantidad de instancias del tipo objeto que han sido creadas y cuantas se encuentran en memoria.
    Nota: los contadores debe ser miembros privados de la clase.
    Justificar la invocación de los métodos getCantCreada y getCantExistente antes de la creación de
    cualquier objeto.
*/

const int EXITO = 1;
const int ERROR = 0;

class Punto
{

    double mx, my;
    static int creados;
    static int vivos;
public:
    Punto();
    Punto(double, double);
    Punto(double);
    Punto(Punto&);
    ~Punto();

    void valcheck(double&, double&);
    void setPunto(double, double);
    void set_Punto(Punto);

    static int getCantCreada() {return creados;}
    static int getCantExistente() {return vivos;}
    static void addCreado() {creados++;}
    static void addVivo() {vivos++;}
    static void rmVivo() {vivos--;}

    inline Punto getPunto()
    {
        return (*this);
    }
    inline void setX(double x)
    {
        valcheck(x, x);
        mx = x;
    }
    inline void setY(double y)
    {
        valcheck(y, y);
        my = y;
    }
    inline double getX()
    {
        return mx;
    }
    inline double getY()
    {
        return my;
    }
    /*
        Al declararlas friend a "+" y a "-", y hacerlas funciones globales, el primer argumento no nesesariamente debe ser un objeto de la
        clase. Al recibir un numero como primer argumento, la funcion lo forzara a crear el ojbeto a partir del constructor
        ?parametrizado?
    */
    Punto& operator= (const Punto&);
    friend Punto operator+(const Punto& i, const Punto&);
    friend Punto operator-(const Punto& i, const Punto&);
    friend int operator==(const Punto&, const Punto&);
    friend int operator!=(const Punto&, const Punto&);
    friend int operator<(const Punto&, const Punto&);
    friend int operator>(const Punto&, const Punto&);
    friend ostream& operator<<(ostream&, const Punto&);
    friend istream& operator>>(istream&, Punto&);

};

int Punto::creados = 0;
int Punto::vivos = 0;


Punto::Punto()
{
    mx = my = 0;
    addCreado();
    addVivo();
}

Punto::Punto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
    addCreado();
    addVivo();
}


Punto::Punto(double x)
{
    valcheck(x, x);
    mx = x;
    my = 0;
    addCreado();
    addVivo();
}

Punto::Punto(Punto& p)
{
    mx = p.getX();
    my = p.getY();
    addCreado();
    addVivo();
}

Punto::~Punto()
{
    rmVivo();
}

void Punto::setPunto(double x, double y)
{
    valcheck(x, y);
    mx = x;
    my = y;
}

void Punto::set_Punto(Punto p)
{
    //es imposible darle un valor -1000<valor<1000 a los campos de la clase Punto, por lo que
    //al copiar de una clase a otra se da por sentado que los valores estan entre ese rango

    mx = p.getX();
    my = p.getY();
}

void Punto::valcheck(double& x, double& y)
{
    if(x > 1000)
        x = 1000;
    if(x < -1000)
        x = -1000;
    if(y > 1000)
        y = 1000;
    if(y < -1000)
        y = -1000;
}


Punto& Punto::operator=(const Punto& p)
{
    mx = p.mx;
    my = p.my;
    return (*this);
}

Punto operator+ (const Punto& i, const Punto& p)
{
    Punto aux;

    aux.mx = i.mx + p.mx;
    aux.my = i.my + p.my;
    aux.valcheck(aux.mx, aux.my);
    return aux;
}

Punto operator- (const Punto& i, const Punto& p)
{
    Punto aux;

    aux.mx = i.mx - p.mx;
    aux.my = i.my - p.my;
    aux.valcheck(aux.mx, aux.my);
    return aux;
}

int operator==(const Punto& a, const Punto& b)
{
    int exit = ERROR;
    if((a.mx == b.mx) && (a.my == b.my))
    {
        exit = EXITO;
    }

    return exit;
}

int operator!=(const Punto& a, const Punto& b)
{
    int exit = ERROR;

    if((a.mx != b.mx) || (a.my != b.my))
    {
        exit = EXITO;
    }

    return exit;
}

int operator<(const Punto& a, const Punto& b)
{
    int exit = ERROR;

    if( (((a.mx)*(a.mx)) + ((a.my)*(a.my))) < (((b.mx)*(b.mx)) + ((b.my)*(b.my))) )
    {
        exit = EXITO;
    }

    return exit;
}

int operator>(const Punto& a, const Punto& b)
{
    int exit = ERROR;

    if( (((a.mx)*(a.mx)) + ((a.my)*(a.my))) > (((b.mx)*(b.mx)) + ((b.my)*(b.my))) )
    {
        exit = EXITO;
    }

    return exit;
}

ostream& operator<<(ostream& os, const Punto& a)
{
    os << "( " << a.mx << ", " << a.my << " )" << endl;

    return os;
}

istream& operator>>(istream& is, Punto& a)
{
    double x, y;
    cout << "x: ";
    is >> x;
    cout << "y: ";
    is >> y;
    a.setPunto(x, y);

    return is;
}


void ff (void)
{
    Punto p,q,w;
    Punto h(34);
    Punto r=h;
    cout <<"a. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< r.getCantExistente()<<endl;
}

int main()
{
    cout <<"1. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    Punto p(12.34,-56.78);
    cout <<"2. Puntos Creados:"<<p.getCantCreada()<< " - Existentes:"<< p.getCantExistente()<<endl;
    Punto h(p);
    cout <<"3. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
    ff();
    cout <<"4. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;

    PRESS_KEY;
}
