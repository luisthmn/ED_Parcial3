#ifndef LISTA_NODOS_H_INCLUDED
#define LISTA_NODOS_H_INCLUDED
#include "lista_arcos.h"

using namespace std;
//En este archivo se encuentra la clase
//y la estructura para los nodos del sistema
//experto

///////////////////////////////////////////////////////////////////
struct caja2{ //Nodos (preguntas, clausulas intermedias, conclusiones)
    int numNodo;  //Numero de nodo
    int bandera;  //(0)Pregunta  (1)Conclusión   (2)Clausula intermedia
    int cuantos;
    int totales;
    int conectivo;  // (1)And (0)Or
    int valorVerdad; // (-1)No se   (0)Falso (1)Verdadero
    string texto;

    lista_arcos salientes;
    caja2 *siguiente;
};
/////////////////////////////////////////////////////
class lista_nodos{
    caja2 *principio, *anterior, *lugaragregado;

    enum _encontrado{SI, NO};
    enum _encontrado encontrado;
    enum _donde{VACIO, PRINCIPIO, ENMEDIO, FINAL};
    enum _donde donde;
    int cuantos;


    public:
    lista_nodos();
    ~lista_nodos();
    void Iniciar();      //Para inicializar la lista de los nodos desde la clase del sistema experto
    void buscar(int a);
    int agregarPregunta(int numNodo, string texto);                     //Agregar nodo tipo pregunta
    int agregarClausula(int numNodo, int tipoConectivo, string texto);  //Agregar nodo tipo clausula
    int agregarConclusion(int numNodo, int tipoConectivo, string texto);//Agregar nodo tipo conclusión
    int borrar(int a);
    void agregarArco(int a, int b, bool cambiaValor);                   //Arco entre dos nodos (Recibe los num nodos)
    void pintar(caja2 *p);
    caja2* Principio();
    caja2* lugar_agregado();
};
////////////////////////////////////////////////////////



#endif // LISTA_NODOS_H_INCLUDED
