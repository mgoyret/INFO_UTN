#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    double mx, my, limSup = 1000, limInf = -1000;

    public:

    Punto(double a=0, double b=0) { setPunto(a, b); }
    ~Punto(){}

    void setPunto(double a, double b);
    inline Punto getPunto() {return *this;}

    void setX(double a){mx=enRango(a);}
    void setY(double b){my=enRango(b);}
    double getX(){return mx;}
    double getY(){return my;}
    double enRango(double);

};

#endif // PUNTO_H
