#include "complejo.h"

int main()
{
    Complejo c1,c2,c3,c4;

    c1.SetComplejo(3,2);    // 3 + j2
    c2.SetComplejo(1,1);    // 1 + j

    c3 = c4 = c1;

    if(c3 == c4){
        cout << "Son iguales" << endl;
    }
    else{
        cout << "Son distintos" << endl;
    }

    cout << "Valor c1: " << c1 << " y c2: " << c2 << endl;
    cout << "Resta: " << c1 - c2 << endl;

    cout << c1 << endl;

    return 0;
}
