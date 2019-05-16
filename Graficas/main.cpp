#include <iostream>
#include <cstdlib>
#include "Clases.cpp"

int main()
{
    grafica G;

    G.agregarArco(1,2,1);
    G.agregarArco(1,3,1.4);
    G.agregarArco(2,3,1);
    G.agregarArco(2,4,1);
    G.agregarArco(3,5,1);
    G.agregarArco(3,6,1.4);
    G.agregarArco(4,5,1);
    G.agregarArco(4,7,1);
    G.agregarArco(5,6,1);
    G.agregarArco(5,8,1);
    G.agregarArco(6,9,1);
    G.agregarArco(6,10,1.4);
    G.agregarArco(7,8,1);
    G.agregarArco(8,9,1);
    G.agregarArco(9,10,1);

    G.ruta_mas_corta(1,10);
    cout << endl;
    G.pintar_ruta(1,10);

    G.~grafica();

    cout << endl;
    system("pause");
    return 0;
}
