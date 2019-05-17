#ifndef LISTA_ARCOS_H_INCLUDED
#define LISTA_ARCOS_H_INCLUDED
#include "lista.h"


using namespace std;

struct caja2;
//--------------------------------------------------------------------
struct caja1{               //Estructuras de los arcos
   bool cambiaValor;        //Para ver si se tiene que cambiar el valor de verdad en ese arco
   caja1 *siguiente;
   caja2 *direccion_nodo;
};
//------------------------------------------------------------------------
class lista_arcos{

    caja1 *principio, *anterior, *siguiente, *lugaragregado;
    enum _encontrado{SI, NO};
    enum _encontrado encontrado;
    enum _donde{VACIO, PRINCIPIO, ENMEDIO, FINAL};
    enum _donde donde;
    int cuantos;

    public:
    lista_arcos();
    ~lista_arcos();
    void Iniciar();
    void buscar(int a);
    int agregar(caja2* p, bool cambiaValor);
    int Cuantos();
    void pintar();
    caja1* lugar_agregado();
    caja1* Principio();

};
//-------------------------------------------------------------------------------

#endif // LISTA_ARCOS_H_INCLUDED
