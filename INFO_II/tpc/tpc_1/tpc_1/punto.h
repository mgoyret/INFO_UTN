#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    double mx, my;

    public:

    Punto(double a=0, double b=0): mx(a), my(b){};
    ~Punto(){}

    void setPunto(double a, double b) {mx=a; my=b;}
    inline Punto getPunto() {return *this;}

    void setX(double a){mx=a;}
    void setY(double b){my=b;}
    double getX(){return mx;}
    double getY(){return my;}

};

#endif // PUNTO_H
