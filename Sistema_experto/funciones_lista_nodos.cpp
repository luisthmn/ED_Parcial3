#include <iostream>
#include <cstdlib>
#include "lista_nodos.h"

enum{OR, AND};
enum{PREGUNTA, CONCLUSION, CLAUSULA};
enum{NOSE=-1, FALSO = 0, VERDADERO = 1};

//En este archivo están todas las funciones
// de la lista de nodos, los nodos se refieren
// a las preguntas, conclusiones y clausulas
// intermedias del sistema experto


////////////////////////////////////////////////
lista_nodos::lista_nodos(){
    principio = NULL;
    anterior = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
//////////////////////////////////////////////
void lista_nodos::Iniciar(){
    principio = NULL;
    anterior = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
///////////////////////////////////////////
lista_nodos::~lista_nodos(){

    caja2 *p;
    while(principio){
        p = principio;
        principio = p ->siguiente;
        delete p;
    }

    principio = NULL;
    anterior = NULL;
    lugaragregado = NULL;
    encontrado = NO;
    donde = VACIO;
    cuantos = 0;
}
/////////////////////////////////////////
void lista_nodos::buscar(int a){

    caja2 *p;

    if(principio == NULL){      //Caso lista de nodos vacía
        encontrado = NO;
        donde = VACIO;
        return;
    }

    p = principio;

    while(p){
        if(p->numNodo == a){
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
            lugaragregado = p;
            return;
        }
        else if (p ->numNodo < a){
            encontrado = NO;
            anterior = p;
            p = p -> siguiente;

        }
        else{
            encontrado = NO;
            if (p == principio){
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
int lista_nodos::agregarPregunta(int numNodo, string texto){
    caja2 *p;
    buscar(numNodo);

    if(encontrado == SI) return 0;

    p = new caja2;
    p->numNodo = numNodo;
    p->bandera = 0;
    p->conectivo = 0;  //En el caso de los preguntas no existe conectivo, este dato es innecesario
    p->cuantos = -1;  //En el caso de las preguntas no necesitamos el cuantos, pongo -1 solo para que no cause conflicto mas adelante
    p->texto = texto;
    p->totales = -2;   //El totales tampoco se utiliza en las preguntas, pongo -2 para que no cause conflicto mas adelante
    p->valorVerdad = -1;
    (p->salientes).Iniciar();

    if(donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    }
    if(donde == PRINCIPIO){
        p->siguiente = principio;
        principio = p;
    }
    if(donde == FINAL){
        p->siguiente = NULL;
        anterior ->siguiente = p;
    }
    if(donde == ENMEDIO){
        p->siguiente = anterior ->siguiente;
        anterior->siguiente = p;
    }
    lugaragregado = p;
    return 1;
}
////////////////////////////////////////////
int lista_nodos::agregarClausula(int numNodo, int tipoConectivo, string pregunta){
    caja2 *p;
    buscar(numNodo);

    if(encontrado == SI) return 0;

    p = new caja2;
    p->numNodo = numNodo;
    p->bandera = CLAUSULA;              //Marcamos el nodo como CLAUSULA para distinguirlo
    p ->totales = 0;                    //El totales lo inicializamos en 0 para cambiarlo mas adelante al agregar los arcos
    p ->conectivo = tipoConectivo;      //Agregamos el tipo de conectivo (AND-OR)
    p -> texto = pregunta;              //Agregamos el texto que tenga el nodo
    p ->cuantos = 0;                    //Cuantos inicializado en 0 para cambiarse mas adelante
    p ->valorVerdad = -1;               //El valor de verdad de todos los nodos se inicializa en -1
    (p->salientes).Iniciar();           //Creamos una clase de salientes para los salientes de nuestro nodo

    if(donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    }
    if(donde == PRINCIPIO){
        p->siguiente = principio;
        principio = p;
    }
    if(donde == FINAL){
        p->siguiente = NULL;
        anterior ->siguiente = p;
    }
    if(donde == ENMEDIO){
        p->siguiente = anterior ->siguiente;
        anterior->siguiente = p;
    }
    lugaragregado = p;
    return 1;
}
////////////////////////////////
int lista_nodos::agregarConclusion(int numNodo, int tipoConectivo, string pregunta){
    caja2 *p;
    buscar(numNodo);

    if(encontrado == SI) return 0;

    p = new caja2;
    p->numNodo = numNodo;
    p->bandera = CONCLUSION;           //Marcamos el nodo con bandera de CONCLUSION para distinguirlo
    p ->totales = 0;                   //Inicializamos el totales en 0 para cambiarlo mas adelante cuando se agreguen los arcos
    p ->conectivo = tipoConectivo;     //Establecemos el tipo de conectivo del nodo (AND-OR)
    p -> texto = pregunta;             //Guardamos el texto que contenga el nodo
    p ->cuantos = 0;                   //Inicializamos el cuantos en 0 para cambiarlo más adelante
    p ->valorVerdad = -1;              //Inicializamos todos los nodos con valor de verdad -1
    (p->salientes).Iniciar();          //Creamos una clase salientes para los salientes del nodo

    if(donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    }
    if(donde == PRINCIPIO){
        p->siguiente = principio;
        principio = p;
    }
    if(donde == FINAL){
        p->siguiente = NULL;
        anterior ->siguiente = p;
    }
    if(donde == ENMEDIO){
        p->siguiente = anterior ->siguiente;
        anterior->siguiente = p;
    }
    lugaragregado = p;
    return 1;
}
////////////////////////////////
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
///////////////////////////////////////////
void lista_nodos::agregarArco(int a, int b, bool cambiaValor){ //Ingresamos como parametro los numeros de nodos que unira el arco (a y b)
    caja2 *p, *q;
    p = q = principio;

    buscar(a);
    if(encontrado == NO) return;
    buscar(b);
    if(encontrado == NO) return;

    while(p){
        if(p->numNodo==a) break;            //Ubicamos y nos colocamos en el nodo A
        p = p->siguiente;
    }
    while(q){
        if(q->numNodo==b) break;            //Ubicamos y nos colocamos en el nodo B
        q = q->siguiente;
    }
    (p->salientes).agregar(q, cambiaValor);     //Creamos un arco en el nodo A (p) que tenga como destino el nodo B (q)
    q->totales++;                               //Aumentamos el totales del nodo B (q)
}
////////////////////////////////////////////
caja2* lista_nodos::lugar_agregado(){
    return lugaragregado;
}
//////////////////////////////////////////
void lista_nodos::pintar(caja2 *p){  //Esta funcion pregunta una pregunta y si es contestada con si regresa 1 y con no 0
            cout << "\n#" << p->numNodo << " ";
            cout << p->texto << endl;                //Escribimos la pregunta para
            cout << "(1)  Si \n(0)  No \n(-2) No se";//que la lea el usuario
            cout << endl << "Tu respuesta: ";
}
///////////////////////////////////////////
caja2* lista_nodos::Principio(){
    return principio;
}
///////////////////////////////////////////////
