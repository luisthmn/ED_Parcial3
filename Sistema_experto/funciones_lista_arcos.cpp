#include <iostream>
#include <cstdlib>
#include "lista_nodos.h"
#include "lista_arcos.h"
enum{OR, AND};
enum{PREGUNTA, CONCLUSION, CLAUSULA};
enum{NOSE=-1, FALSO = 0, VERDADERO = 1};



//En este archivo están todas las funciones
//de los arcos que contienen los nodos del sistema experto

lista_arcos::lista_arcos(){
    principio = NULL;
    anterior = NULL;
    siguiente = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/////////////////////////////
void lista_arcos::Iniciar(){
principio = NULL;
    anterior = NULL;
    siguiente = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
///////////////////////////////
lista_arcos::~lista_arcos(){
    caja1 *p;

    while(principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }

    principio = NULL;
    anterior = NULL;
    siguiente = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/////////////////////////////
void lista_arcos::buscar(int a){
    caja1 *p;

    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    p = principio;

    while(p){
        if( p -> direccion_nodo -> numNodo == a){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }
            else if (p -> siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
            lugaragregado = p;
            return;
        }
        else if(p -> direccion_nodo -> numNodo < a){
            encontrado = NO;
            anterior = p;
            p = p->siguiente;
        }
        else{
            encontrado = NO;
            if(p == principio){
                donde = PRINCIPIO;
            }
            else{
                donde = ENMEDIO;
            }
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;
}
///////////////////////////////////////////////////////
int lista_arcos::agregar(caja2 *p, bool cambiaValor){

    caja1 *r;
    buscar(p->numNodo);                 //Buscamos el nodo destino del arco
    if(encontrado == SI) return 0;
    r = new caja1;
    r ->direccion_nodo = p;             //Agregamos la direccion del nodo destino al arco
    r ->cambiaValor = cambiaValor;      //Establecemos si este arco debe de aumentar el cuantos cuando p=0 (cambiaValor = 1)
                                        //o cuando p=1 (cambiaValor = 0)

    if(donde == VACIO){
        r->siguiente = NULL;
        principio = r;
    }
    else if(donde == PRINCIPIO){
        r ->siguiente = principio;
        principio = r;
    }
    else if (donde == FINAL){
        r ->siguiente = NULL;
        anterior ->siguiente = r;
    }
    else{
        r ->siguiente = anterior ->siguiente;
        anterior ->siguiente = r;
    }
    lugaragregado = r;
    cuantos++;
    return 1;
}
////////////////////////////////////////////////////
int lista_arcos::Cuantos(){
    return cuantos;
}
/////////////////////////////////////////////////////////
caja1* lista_arcos::lugar_agregado(){
    return lugaragregado;
}
/////////////////////////////////////////////////////////
void lista_arcos::pintar(){
    caja1 *p;
    p = principio;

    while(p){
        cout << p->direccion_nodo->numNodo << "  ";
        p = p->siguiente;
    }
}
/////////////////////////////////////////////////////////
caja1* lista_arcos::Principio(){
    return principio;
}
//////////////////////////////////////////////////////////
