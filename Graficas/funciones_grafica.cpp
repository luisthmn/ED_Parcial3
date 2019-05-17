#include <iostream>
#include <cstdlib>
#include "Clases.cpp"

using namespace std;

//////////////////////////
//   GRAFICA
//////////////////////////

//-----------------------------------
grafica::grafica(){
    existe_ruta = false;
}
//-----------------------------------------
grafica::~grafica(){
    A.~lista_nodos();
    B.~lista();
    existe_ruta = false;
}
//--------------------------------------
void grafica::agregarArco(int a, int b, float l){

    caja1 *p;
    caja2 *q, *q2;


    A.agregar(a);
    q = A.lugar_agregado();
    q2 = A.lugar_agregado();
    (q->salientes).agregar(b);
    p = (q->salientes).lugar_agregado();

    A.agregar(b);
    q = A.lugar_agregado();
    p->direccion_nodo = q;
    p->longitud = l;
    (q->entrantes).agregar(a);
    ((q->entrantes).lugar_agregado())->direccion_nodo = q2;
    ((q->entrantes).lugar_agregado())->longitud = l;

}
//-------------------------------------------------------------
void grafica::pintar(){
    A.pintar();
}
//----------------------------------------------------------
void grafica::ruta_mas_corta(int a, int b){

    caja2 *p;
    caja1 *q;

    A.agregar(a);
    p = A.lugar_agregado();
    p ->antecesor= NULL;

    while(p){
        p -> bandera = 2;
        if(p -> numNodo == b){
            existe_ruta = true;
            B.limpiar();
            while(p){
                B.agregar(p, p -> ruta_corta);
                p = p -> antecesor;
            }
            return;
        }
        q = p -> salientes.Principio();
        while(q){
            if(q -> direccion_nodo -> bandera == 0){
                q -> direccion_nodo -> bandera = 1;
                q -> direccion_nodo -> ruta_corta = ((p -> ruta_corta) + (q -> longitud));
                q -> direccion_nodo -> antecesor = p;
                B.agregar(q -> direccion_nodo,q -> direccion_nodo -> ruta_corta);
                q -> direccion_nodo -> direccion = B.lugaragregado();
            }
            else if(q -> direccion_nodo -> bandera == 1 && ((p -> ruta_corta) + (q -> longitud)) < q -> direccion_nodo -> ruta_corta){
                q -> direccion_nodo -> ruta_corta = ((p -> ruta_corta) + (q -> longitud));
                (q -> direccion_nodo) -> antecesor = p;
                B.ajustar(q -> direccion_nodo -> direccion,q -> direccion_nodo -> ruta_corta);
            }
            q = q -> siguiente;
        }
        p = B.sacar();
    }
}

//-----------------------------------------------------------------------
void grafica::pintar_ruta(int I, int F){
    A.pintar();
    cout << "\n\n\n";
    cout << "Inicio: " << I << " | Final: " << F << "\n\n";
    if(existe_ruta == true){
        cout << "Ruta mas corta: \n";
        B.pintar();
    }else{
        cout << "No hay ruta";
        cout << endl << endl;
    }
}
//--------------------------------------------------------------------------
