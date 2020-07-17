#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    double mx, my, limSup = 1000, limInf = -1000;

    public:

    Punto(): mx(0), my(0){}
    Punto(double, double);
    Punto(double);
    Punto(Punto&);
    ~Punto(){}

    double enRango(double);
    void setPunto(double a, double b);
    void setPunto(Punto);
    inline Punto getPunto() {return *this;}

    void setX(double a){mx=enRango(a);}
    void setY(double b){my=enRango(b);}
    double getX(){return mx;}
    double getY(){return my;}

};

#endif // PUNTO_H
