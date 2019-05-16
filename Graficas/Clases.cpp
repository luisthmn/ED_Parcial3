#include <iostream>
#include <cstdlib>

using namespace std;


////////////////////////////
struct caja2;                   //Estructura de los nodos
////////////////////////////
struct caja1{                   //Estructura de los arcos
    int numNodo;
    float longitud;
    caja1 *siguiente;
    caja2 *direccion_nodo;

};
////////////////////////////
struct caja3{                   //Estructura de los nodos auxiliares
    caja2 *direccion_nodo;
    float longitud;

    caja3 *siguiente, *anterior;
};
////////////////////////////



/////////////////////////////////////////////////////
class lista_arcos{
    caja1 *principio, *anterior, *siguiente, *Lugaragregado;

    enum _encontrado{SI, NO}; enum _encontrado encontrado;
    enum _donde{VACIO, PRINCIPIO, ENMEDIO, FINAL}; enum _donde donde;
    int cuantos;

    public:
    lista_arcos();
    ~lista_arcos();
    void buscar(int a);
    int agregar(int a);
    int borrar(int a);
    void pintar();
    int Cuantos();
    caja1* lugar_agregado();
    caja1* Principio();
};
/////////////////////////////////////////////////////


//////////////////////////////////
struct caja2{                                   //Estructua de los nodos
    int numNodo, bandera;
    float ruta_corta;
    lista_arcos salientes, entrantes;

    caja2 *anterior, *siguiente, *antecesor;
    caja3 *direccion;
};
//////////////////////////////////


//////////////////////////////////
class lista_nodos{
    caja2 *principio, *anterior, *Lugaragregado;

    enum _encontrado{SI, NO}; enum _encontrado encontrado;
    enum _donde{VACIO, PRINCIPIO, ENMEDIO, FINAL}; enum _donde donde;
    int cuantos;

    public:
    lista_nodos();
    ~lista_nodos();
    void buscar(int a);
    int agregar(int a);
    int borrar(int a);
    void pintar();
    caja2* lugar_agregado();
};
/////////////////////////////////////////////////////
class lista{                                            //Lista de los nodos auxiliares

    caja3 *principio, *anterior, *Final, *Lugaragregado;
    enum _encontrado{SI, NO};
    enum _encontrado encontrado;
    enum _donde{VACIO, PRINCIPIO, ENMEDIO, FINAL};
    enum _donde donde;
    int cuantos;

    public:
    lista();
    ~lista();
    void buscar(float a);
    int agregar( caja2 *p, float a);
    void pintar();
    caja2* sacar();
    void ajustar(caja3 *q, float a);
    void limpiar();
    caja3* lugaragregado();
};
/////////////////////////////////////////////////////
class grafica{

    lista_nodos A;
    lista B;
    bool existe_ruta;     //Variables que detecta si el algoritmo de Dykstra
                          //encontró una ruta
    public:
    grafica();
    ~grafica();
    void agregarArco(int a, int b, float l);
    void ruta_mas_corta(int a, int b);          //Funcion que emplea el algoritmo de Dykstra
    void pintar();                              //Funcion que pinta la gráfica
    void pintar_ruta(int I, int F);             //Funcion que pinta la gráfica y el camino encontrado por Dikstra
};
//////////////////////////////////////////////////////
