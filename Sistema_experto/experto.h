#ifndef EXPERTO_H_INCLUDED
#define EXPERTO_H_INCLUDED
#include "lista_nodos.h"
#include "lista.h"
#include "lista_arcos.h"

using namespace std;

//En este archivo se encuentra la clase del sistema experto

//------------------------------------------------------------------------------
class experto{
    lista_nodos A;  //Lista de nodos
    lista B;        //Lista auxiliar para los salientes de las preguntas y clausulas

    public:
    experto();
    ~experto();
    void sistema_experto();                             //ARCHIVO PRINCIPAL PARA INICIAR EL SISTEMA EXPERTO
    caja2* obtenerPregunta();                           //Revisa toda la lista de nodos y devuelve el primero que encuentre que sea una pregunta no redundante
    void cambiarSalientes(caja2 *p);                    //Esta funcion maneja todos los salientes de un nodo usando la lista auxiliar
    void agregarPregunta(int numNodo, string texto);
    void agregarConclusion(int numNodo, int tipoConectivo, string texto);
    void agregarClausula(int numNodo, int tipoConectivo, string texto);
    void agregarArco(int a, int b, bool cambiaValor);   //Agregar arco entre dos nodos
};
//---------------------------------------------------------------------------
#endif // EXPERTO_H_INCLUDED
