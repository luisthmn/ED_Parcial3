#include <iostream>
#include <cstdlib>
#include "Clases.cpp"

using namespace std;

//////////////////////////
//   Lista Nodos
//////////////////////////

////////////////////////////
lista_nodos::lista_nodos(){
    principio = NULL;
    anterior = NULL;
    Lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
////////////////////////////
lista_nodos::~lista_nodos(){

    caja2 *p;
    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }

    principio = NULL;
    anterior = NULL;
    Lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//////////////////////////////////////////////////////
void lista_nodos::buscar(int a){

    caja2 *p;
    if(principio == NULL){
        donde = VACIO;
        encontrado = NO;
        return;
    }
    p = principio;

    while(p){
        if(p->numNodo == a){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }
            else if(p ->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
            Lugaragregado = p;
            return;
        }
        else if(p->numNodo < a){
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
////////////////////////////////////////////////////
int lista_nodos::agregar(int a){

    caja2 *p;
    buscar(a);

    if(encontrado == SI) return 0;

    p = new caja2;
    p ->numNodo = a;
    p ->bandera = 0;

    if(donde == VACIO){
        p ->siguiente = NULL;
        principio = p;
    }
    else if(donde == PRINCIPIO){
        p ->siguiente = principio;
        principio = p;
    }
    else if(donde == FINAL){
        p->siguiente = NULL;
        anterior ->siguiente = p;
    }
    else{
        p->siguiente = anterior ->siguiente;
        anterior->siguiente = p;
    }
    Lugaragregado = p;
    cuantos++;
    return 1;
}
//////////////////////////////////////////////////////
int lista_nodos::borrar(int a){

    caja2 *p;
    buscar(a);
    if(encontrado == NO) return 0;
    if(donde == PRINCIPIO){
        p = principio;
        principio = p->siguiente;
    }
    else if(donde == ENMEDIO){
        p = anterior->siguiente;
        anterior->siguiente = p->siguiente;
    }
    else{
        p = anterior->siguiente;
        anterior->siguiente = NULL;
    }
    delete p;
    cuantos--;
    return 1;
}
////////////////////////////////////////////////////
void lista_nodos::pintar(){

    caja2 *p;
    p = principio;

    while(p){
        cout << "Nodo: " << p->numNodo << endl;
        cout << "S: ";
        (p->salientes).pintar();
        cout << endl << "E: ";
        (p->entrantes).pintar();
        p = p->siguiente;
        cout << endl << endl << endl;
    }
}
/////////////////////////////////////////////////////
caja2* lista_nodos::lugar_agregado(){
    return Lugaragregado;
}
/////////////////////////////////////////////////////
