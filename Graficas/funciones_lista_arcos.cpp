#include <iostream>
#include <cstdlib>
#include "Clases.cpp"

using namespace std;

//////////////////////////
//   Lista Arcos
//////////////////////////
lista_arcos::lista_arcos(){

    principio = NULL;
    anterior = NULL;
    siguiente = NULL;
    Lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//--------------------------------------------------
lista_arcos::~lista_arcos(){
    caja1 *p;

    while(principio){
        p = principio;
        principio = p ->siguiente;
        delete p;
    }

    principio = NULL;
    anterior = NULL;
    siguiente = NULL;
    Lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//----------------------------------------------------------
void lista_arcos::buscar(int a){

    caja1 *p;

    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }

    p = principio;

    while(p){
        if( p ->numNodo == a){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }
            else if (p ->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
            Lugaragregado = p;
            return;
        }
        else if( p->numNodo < a){
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
//------------------------------------------------------------
int lista_arcos::agregar(int a){

    caja1 *p;
    buscar(a);
    if(encontrado == SI) return 0;
    p = new caja1;
    p->numNodo = a;

    if(donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    }
    else if(donde == PRINCIPIO){
        p ->siguiente = principio;
        principio = p;
    }
    else if (donde == FINAL){
        p ->siguiente = NULL;
        anterior ->siguiente = p;
    }
    else{
        p ->siguiente = anterior ->siguiente;
        anterior ->siguiente = p;
    }
    Lugaragregado = p;
    cuantos++;
    return 1;
}
//-----------------------------------------------------------------
int lista_arcos::borrar(int a){
    caja1 *p;
    buscar(a);

    if(encontrado == NO) return 0;

    if(donde == PRINCIPIO){
        p = principio;
        principio = p->siguiente;
    }
    else if(donde == ENMEDIO){
        p = anterior ->siguiente;
        anterior ->siguiente = p->siguiente;
    }
    else{
        p = anterior ->siguiente;
        anterior ->siguiente = NULL;
    }
    delete p;
    cuantos--;
    return 1;
}
//--------------------------------------------------------------------
void lista_arcos::pintar(){

    caja1 *p;
    p = principio;

    while(p){
        cout << p->numNodo;
    //    cout << ":" << p->direccion_nodo->numNodo;
        cout << ":" << p->longitud;
        if(p->siguiente != NULL) cout << ", ";
        p = p->siguiente;
    }
}
//------------------------------------------------------------------
int lista_arcos::Cuantos(){
    return cuantos;
}
//-------------------------------------------------------------------
caja1* lista_arcos::lugar_agregado(){
    return Lugaragregado;
}
//------------------------------------------------------------------
caja1* lista_arcos::Principio(){
    return principio;
}
//--------------------------------------------------------------------
