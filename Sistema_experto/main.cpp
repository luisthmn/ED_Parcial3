/*
    Nombre: Sistema Experto para identificar animales
    Autor: Luis Thomson
*/
#include <iostream>
#include <cstdlib>
#include "lista_nodos.h"
#include "lista_arcos.h"
#include "experto.h"
#include "lista.h"

using namespace std;

int main()
{
    enum{OR, AND};
    enum{PREGUNTA, CONCLUSION, CLAUSULA};
    enum{NOSE=-1, FALSO = 0, VERDADERO = 1};


    cout << endl << "Sistema Experto para Identificaci\242n de animales:" << endl << endl;

   experto A;

    A.agregarPregunta(1,"Tiene pelo?");
    A.agregarPregunta(2, "Da leche?");
    A.agregarPregunta(3,"Tiene plumas?");
    A.agregarPregunta(4,"Vuela?");
    A.agregarPregunta(5,"Pone huevos?");
    A.agregarPregunta(6,"Come carne?");
    A.agregarPregunta(7,"Tiene dientes agudos?");
    A.agregarPregunta(8,"Tiene garras?");
    A.agregarPregunta(9,"Tiene ojos que miran hacia adelante?");
    A.agregarPregunta(10,"Tiene pezunas?");
    A.agregarPregunta(11,"Rumia?");
    A.agregarPregunta(12,"Es de color leonado?");
    A.agregarPregunta(13,"Tiene manchas obscuras?");
    A.agregarPregunta(14,"Tiene franjas negras?");
    A.agregarPregunta(15,"Tiene patas largas?");
    A.agregarPregunta(16,"Tiene cuello largo?");
    A.agregarPregunta(17,"Es de color blanco?");
    A.agregarPregunta(18,"Es blanca y negra?");
    A.agregarPregunta(19,"Nada?");
    A.agregarPregunta(20,"Vuela muy bien?");
    A.agregarConclusion(21,AND,"Es una onza");
    A.agregarConclusion(22,AND,"Es un tigre");
    A.agregarConclusion(23,AND,"Es una jirafa");
    A.agregarConclusion(24,AND,"Es una zebra");
    A.agregarConclusion(25,AND,"Es un avestruz");
    A.agregarConclusion(26,AND,"Es un pinguino");
    A.agregarConclusion(27,AND,"Es un albatroz");
    A.agregarClausula(28,OR, "Es mamifero");
    A.agregarClausula(29,AND, " ");
    A.agregarClausula(30,AND, " ");
    A.agregarClausula(31,OR, "Es ave");
    A.agregarClausula(32,AND," ");
    A.agregarClausula(33,AND," ");
    A.agregarClausula(34,OR,"Es carnivoro");
    A.agregarClausula(35,AND," ");
    A.agregarClausula(36,AND,"Es ungulado");
    A.agregarClausula(37,OR," ");
    A.agregarClausula(38,AND," ");
    A.agregarClausula(39,AND," ");
    A.agregarArco(1,29,false);
    A.agregarArco(2,30,false);
    A.agregarArco(3, 32, false);

    A.agregarArco(4, 25, true);
    A.agregarArco(4, 26, true);
    A.agregarArco(4, 33, false);
    A.agregarArco(5, 33, false);
    A.agregarArco(6, 35, false);
    A.agregarArco(7, 36, false);
    A.agregarArco(8, 36, false);
    A.agregarArco(9, 36, false);
    A.agregarArco(10, 38, false);
    A.agregarArco(11, 39, false);
    A.agregarArco(12, 21, false);
    A.agregarArco(12, 22, false);
    A.agregarArco(12, 23, false);
    A.agregarArco(13, 21, false);
    A.agregarArco(13, 23, false);
    A.agregarArco(14, 22, false);
    A.agregarArco(14, 24, false);
    A.agregarArco(15, 23, false);
    A.agregarArco(15, 25, false);
    A.agregarArco(16, 23, false);
    A.agregarArco(16, 25, false);
    A.agregarArco(17, 24, false);
    A.agregarArco(18, 26, false);
    A.agregarArco(18, 25, false);
    A.agregarArco(19, 26, false);
    A.agregarArco(20, 27, false);
    A.agregarArco(28, 36,false);
    A.agregarArco(28, 35,false);
    A.agregarArco(28, 38,false);
    A.agregarArco(28, 39,false);
    A.agregarArco(29, 28, false);
    A.agregarArco(30, 28, false);
    A.agregarArco(31, 25, false);
    A.agregarArco(31, 26, false);
    A.agregarArco(31, 27, false);
    A.agregarArco(32, 31, false);
    A.agregarArco(33, 31, false);
    A.agregarArco(34, 22, false);
    A.agregarArco(34, 21, false);
    A.agregarArco(35, 34, false);
    A.agregarArco(36, 34,false);
    A.agregarArco(37, 23, false);
    A.agregarArco(37, 24, false);
    A.agregarArco(38, 37, false);
    A.agregarArco(39, 37, false);
    A.sistema_experto();



    cout << endl << endl;
    system("pause");
    return 0;
}
