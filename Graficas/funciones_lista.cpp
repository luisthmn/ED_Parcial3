#include <iostream>
#include <cstdlib>
#include "Clases.cpp"

using namespace std;

//////////////////////////
//   LISTA
//////////////////////////

//------------------------------------------------
lista::lista(){
    principio = NULL;
    Final = NULL;
    anterior = NULL;
    Lugaragregado = NULL;
    encontrado = NO;
    cuantos = 0;
    donde = VACIO;
}
//---------------------------------------------------
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
    Lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//------------------------------------------------------
void lista::buscar(float a){

    caja3 *p;

    if(principio == NULL){
        donde = VACIO;
        encontrado = NO;
        return;
    }

    p = principio;

    while(p){
        if(p ->direccion_nodo ->ruta_corta == a){

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
        else if(p ->direccion_nodo ->ruta_corta < a){
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
//---------------------------------------------------------------
int lista::agregar(caja2 *q, float a){

    caja3 *p;
    buscar(a);
    if(encontrado == SI) return 0;

    p = new caja3;
    p ->direccion_nodo = q;
    p ->direccion_nodo ->ruta_corta = a;

   if(donde == VACIO){
        principio = p;
        p ->siguiente = NULL;
        p ->anterior = NULL;
        Final = p;
    }
    else if(donde == PRINCIPIO){
        p ->siguiente = principio;
        p ->anterior = NULL;
        (p ->siguiente) ->anterior = p;
        principio = p;
    }
    else if(donde == FINAL){
        p ->siguiente = NULL;
        p ->anterior = Final;
        Final = p;
        anterior ->siguiente = p;
    }
    else{
        p ->siguiente = anterior ->siguiente;
        p ->anterior = anterior;
        (p ->siguiente) ->anterior = p;
        anterior ->siguiente = p;
    }

    Lugaragregado = p;
    cuantos++;
    return 1;
}
//-------------------------------------------------------------
void lista::pintar(){
    caja3 *p;

    p = principio;
    cout << "I:\n";

    while(p){
        cout << " " << p ->direccion_nodo ->numNodo << "\n";
        p = p ->siguiente;
    }
    cout << "\nLongitud: " << Final -> direccion_nodo->ruta_corta << "\n\n";
}
//-----------------------------------------------------------------
caja2* lista::sacar(){
    caja2 *p;
    caja3 *q;

    p = NULL;
    q = principio;

    if(principio == NULL) return p;

    p = q ->direccion_nodo;
    principio = q -> siguiente;

    if(principio != NULL) principio ->anterior = NULL;

    delete q;
    --cuantos;
    return p;
}
//-------------------------------------------------------------------
void lista::ajustar(caja3 *q, float a){
    caja3 *p;

    p = principio;

    while(p ->direccion_nodo != q ->direccion_nodo){
        p = p->siguiente;
    }

    p -> direccion_nodo ->ruta_corta = a;

    if(p != principio){
            if(p ->direccion_nodo ->ruta_corta < p ->anterior ->direccion_nodo ->ruta_corta){
                if(p->anterior == principio){
                    principio -> siguiente = p ->siguiente;
                    p ->siguiente = principio;
                    p ->siguiente ->anterior = p;
                    principio = p;
                    p ->anterior = NULL;
                    return;
            }else if( p == Final){
                p ->anterior = Final;
                p ->anterior ->siguiente = NULL;
                agregar( q-> direccion_nodo, a);
            }else{
                (p ->anterior) ->siguiente = p ->siguiente;
                (p->siguiente) ->anterior = p ->anterior;
                agregar( q->direccion_nodo, a);
            }
        }
    }
}
//---------------------------------------------------------------------
void lista::limpiar(){
  caja3 *p;

  while(principio){
    p = principio;
    principio = principio ->siguiente;
    delete p;
  }

  principio = NULL;
  anterior = NULL;
  Final = NULL;
  Lugaragregado = NULL;
  encontrado = NO;
  donde = VACIO;
  cuantos = 0;
}
//------------------------------------------------------
caja3* lista::lugaragregado(){
    return Lugaragregado;
}
//--------------------------------------------------------
