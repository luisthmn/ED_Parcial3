#include <iostream>
#include <cstdlib>
#include "lista.h"
enum{OR, AND};
enum{PREGUNTA, CONCLUSION, CLAUSULA};
enum{NOSE=-1, FALSO = 0, VERDADERO = 1};


//Este archivo contiene todas las funciones de la
//lista auxiliar usada en el sistema experto
//Con cada pregunta se guardaran en esta lista los salientes
//afectados y se harán sus cambios, esta lista se vaciara
//antes de hacer una nueva pregunta

/////////////////////////////
lista::lista(){
    principio = NULL;
    Final = NULL;
    anterior = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    cuantos = 0;
    donde = VACIO;
}
////////////////////////////
void lista::Iniciar(){
    principio = NULL;
    Final = NULL;
    anterior = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    cuantos = 0;
    donde = VACIO;
}
/////////////////////////////
lista::~lista(){
    caja3 *p;

    while(principio){
        p = principio;
        principio = principio ->siguiente;
        delete p;
    }

    principio = NULL;
    anterior = NULL;
    Final = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
////////////////////////////
void lista::buscar(int a){
     caja3 *p;

    if(principio == NULL){
        donde = VACIO;
        encontrado = NO;
        return;
    }

    p = principio;

    while(p){
        if(p ->direccion_nodo ->numNodo == a){

            encontrado = SI;

            if(p == principio){
                donde = PRINCIPIO;
            }
            else if(p->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }

            return;
        }
        else if(p ->direccion_nodo ->numNodo < a){
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
////////////////////////////
int lista::agregar(caja2 *p){

    caja3 *nodo_aux;
    buscar(p->numNodo);

    nodo_aux = new caja3;

   if(donde == VACIO){
        principio = nodo_aux;
        nodo_aux ->siguiente = NULL;
        nodo_aux ->anterior = NULL;
        nodo_aux ->direccion_nodo = p;
        Final = nodo_aux;
    }
    else if(donde == PRINCIPIO){
        nodo_aux ->siguiente = principio;
        nodo_aux ->anterior = NULL;
        (nodo_aux ->siguiente) ->anterior = nodo_aux;
        principio = nodo_aux;
        nodo_aux ->direccion_nodo = p;
    }
    else if(donde == FINAL){
        nodo_aux ->siguiente = NULL;
        nodo_aux ->anterior = Final;
        Final = nodo_aux;
        anterior ->siguiente = nodo_aux;
        nodo_aux ->direccion_nodo = p;
    }
    else{
        nodo_aux ->siguiente = anterior ->siguiente;
        nodo_aux ->anterior = anterior;
        (nodo_aux ->siguiente) ->anterior = nodo_aux;
        anterior ->siguiente = nodo_aux;
        nodo_aux ->direccion_nodo = p;
    }

    nodo_aux ->direccion_nodo ->bandera = p->bandera;
    nodo_aux ->direccion_nodo ->conectivo = p->conectivo;
    nodo_aux ->direccion_nodo ->cuantos = p->cuantos;
    nodo_aux ->direccion_nodo ->numNodo = p->numNodo;
    nodo_aux ->direccion_nodo ->totales = p->totales;
    nodo_aux ->direccion_nodo ->valorVerdad = p->valorVerdad;
    lugaragregado = nodo_aux;
    cuantos++;
    return 1;
}
/////////////////////////////////////////
caja2* lista::sacar(){
    caja2 *p;
    caja3 *q;

    p = NULL;
    q = principio;

    if(principio == NULL){
        return p;
    }
    else{
        p = q ->direccion_nodo;
        principio = q -> siguiente;
        if(principio != NULL){
            principio ->anterior = NULL;
        }
    }
    delete q;
    --cuantos;
    return p;
}
//////////////////////////////////////////
caja3* lista::lugar_agregado(){
    return lugaragregado;
}
////////////////////////////////////////////
caja3* lista::Principio(){
    return principio;
}
///////////////////////////////////////////////
