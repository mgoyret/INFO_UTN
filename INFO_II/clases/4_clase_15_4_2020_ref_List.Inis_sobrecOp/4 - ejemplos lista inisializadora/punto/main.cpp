#include "functions.h"

int main()
{
    cout << "Hello World!" << endl;

    Punto p1;
    Punto p2(1, 2, 3);
    int a, b, c;

    cout << "objeto de clase 'Punto' creado" << endl;
    p1.getall();

    cout << "ingrese 3 coordenadas: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    p1.setall(a, b, c);
    p1.getall();

    p1.showobj();
    p2.showobj();
    return 0;
}
