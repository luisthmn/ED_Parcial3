#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "lista_arcos.h"
#include "lista_nodos.h"

using namespace std;
//En este archivo se encuentra la clase de la lista auxiliar junto con la estructura de nodos auxiliares

struct caja2;
//------------------------------------------------------------------------
struct caja3{                   //Estructura para los nodos auxiliares
    caja2 *direccion_nodo;
    caja3 *siguiente, *anterior;
};
//--------------------------------------------------------------------------
class lista{                    //Clase de la lista auxiliar
    caja3 *principio, *anterior, *Final, *lugaragregado;

    enum _encontrado{SI, NO};
    enum _encontrado encontrado;
    enum _donde{VACIO, PRINCIPIO, ENMEDIO, FINAL};
    enum _donde donde;
    int cuantos;

    public:
    lista();
    ~lista();
    void Iniciar();
    void buscar(int a);
    int agregar( caja2 *p);
    caja2* sacar();
    caja3 *lugar_agregado();
    caja3* Principio();
};
//-------------------------------------------------------------------------

#endif // LISTA_H_INCLUDED
