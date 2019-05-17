#include <iostream>
#include <cstdlib>
#include "experto.h"

using namespace std;
enum{OR, AND};
enum{PREGUNTA, CONCLUSION, CLAUSULA};
enum{NOSE=-1, FALSO = 0, VERDADERO = 1};

//En este archivo están todas las
//funciones principales del sistema
//experto


experto::experto(){
    A.Iniciar();
    B.Iniciar();
}
/////////////////////////////////
experto::~experto(){
    A.~lista_nodos();
    B.~lista();
}
///////////////////////////////////
void experto::cambiarSalientes(caja2 *p){ //Manejar y editar los salientes de p usando la lista
    caja1 *q;                             //auxiliar
     q = p->salientes.Principio();        //Nos colocamos en el primer saliente del nodo

    while(q){

        if(p->valorVerdad == VERDADERO){                    //Para cada nodo saliente cambiamos sus atributos acordemente
            if((q->direccion_nodo)->conectivo == AND){      //Si el nodo saliente pasa su valor de verdad a 0 o 1
                if(q->cambiaValor == false){                //Entonces lo metemos en la lista auxiliar para manejar sus
                    (q->direccion_nodo)->cuantos++;         //sus salientes mas adelante
                }
                else{
                    if((q->direccion_nodo)->valorVerdad != FALSO){
                        B.agregar(q->direccion_nodo);
                    }
                    (q->direccion_nodo)->valorVerdad = FALSO;
                }
            }
            else{
                if(q->cambiaValor == false){
                    if((q->direccion_nodo)->valorVerdad != VERDADERO){
                        B.agregar(q->direccion_nodo);
                    }
                    (q->direccion_nodo)->valorVerdad = VERDADERO;
                }
                else{
                    (q->direccion_nodo)->cuantos++;
                }
            }
        }
        else{                                           //Caso en el que recibo un 0 como valor de verdad

            if((q->direccion_nodo)->conectivo == AND){
                if(q->cambiaValor == OR){
                    if((q->direccion_nodo)->valorVerdad != FALSO){
                        B.agregar(q->direccion_nodo);
                    }
                    (q->direccion_nodo)->valorVerdad = FALSO;
                }
                else{
                    (q->direccion_nodo)->cuantos++;
                }
            }
            else{ //Caso OR
                if(q->cambiaValor == false){
                    (q->direccion_nodo)->cuantos++;
                }
                else{
                    if((q->direccion_nodo)->valorVerdad != VERDADERO){
                        B.agregar(q->direccion_nodo);
                    }
                    (q->direccion_nodo)->valorVerdad = VERDADERO;
                }
            }
        }
        if((q->direccion_nodo)->cuantos == (q->direccion_nodo)->totales){
            if((q->direccion_nodo)->conectivo == AND){
                if((q->direccion_nodo)->valorVerdad != VERDADERO){
                        B.agregar(q->direccion_nodo);
                }
                (q->direccion_nodo)->valorVerdad = VERDADERO;
            }
            else{
                if((q->direccion_nodo)->valorVerdad != FALSO){
                        B.agregar(q->direccion_nodo);
                }
                (q->direccion_nodo)->valorVerdad = FALSO;
            }
        }
        if((q->direccion_nodo)->bandera == CONCLUSION && (q->direccion_nodo)->valorVerdad == VERDADERO){
            cout << endl << endl <<"TU ANIMAL HA SIDO ENCONTRADO!: " << (q->direccion_nodo)->texto << endl;
            exit(0);
        }
        q = q->siguiente;
    }
}

///////////////////////////////////////////////
caja2* experto::obtenerPregunta(){         //Función que revisa todos los nodos
    caja2 *p;                              //y regresa la primera pregunta no
    caja1 *q;                              //redundante sin responder que
    p = A.Principio();                     //encuentre

    while(p->bandera == PREGUNTA){
        q = p->salientes.Principio();
        if(p->valorVerdad == -1){
            while(q){
                if((q->direccion_nodo)->valorVerdad == -1) return p;
                q = q->siguiente;
            }
        }

        p = p->siguiente;
    }
    return NULL;
}
////////////////////////////////////////////////////
void experto::sistema_experto(){        //FUNCION PRINCIPAL QUE CORRE EL SISTEMA EXPERTO
    caja2 *p, *q;
    p = A.Principio();
    q = A.Principio();

    while(p){
        p = obtenerPregunta();                                          //Obtenemos una pregunta no redundante

        if(obtenerPregunta()){                //Si la pregunta no es redundante
            A.pintar(p);                                                //Escribimos la pregunta
            cin >> p->valorVerdad;                                       //Recibimos su respuesta
        }
       q = p;
       if(q->valorVerdad!=-1 && q->valorVerdad!=-2){            //Si la pregunta tiene valor de verdad
           while(q){                                            //Manejamos sus salientes
                cambiarSalientes(q);
                q = B.sacar();
           }
        }
        p = A.Principio();                                      //Volvemos al primer nodo para buscar otra pregunta viable para hacer
        if(obtenerPregunta()==NULL){
            cout << endl << endl <<  "Lo sentimos, no se ha encontrado el animal\n\n"; //No se encontró el animal y terminamos
            cout << endl << endl << "Los animales posibles son: \n";
            caja2 *s;
            s = A.Principio();
            while(s){                                                   //Mostramos los animales posibles
                if(s->bandera==CONCLUSION && s->numNodo!=0){
                    cout << endl << s->texto;
                }
                if(s->siguiente)s = s->siguiente;
                else return;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////
void experto::agregarPregunta(int numNodo, string texto){
    A.agregarPregunta(numNodo, texto);
}
///////////////////////////////////////////////////////////
void experto::agregarClausula(int numNodo, int tipoConectivo, string texto){
    A.agregarClausula(numNodo,tipoConectivo, texto);
}
//////////////////////////////////////////////////////////
void experto::agregarConclusion(int numNodo, int tipoConectivo, string texto){
    A.agregarConclusion(numNodo, tipoConectivo, texto);
}
//////////////////////////////////////////////////////////////
void experto::agregarArco(int a, int b, bool cambiaValor){
    A.agregarArco(a, b, cambiaValor);
}
//////////////////////////////////////////////////////////


