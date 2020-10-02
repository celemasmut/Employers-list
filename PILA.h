#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
//#include "DPListOfEmployers.h"
#include "listOfEmployers.h"
//usamos el define para que el precompilador busque en la libreria la palabra Pila y la va a reemplazar por nodo*
#define Pila nodo*

//para pila necesitamos usar punteros dobles para modificar la pila.
//entonces cuando el compilardor cambie Pila por nodo* va a quedar nodo**
void inicPila(Pila*p);
int emptyPila(Pila*p);
int emptyPilaPro(Pila*p);//ternario
void pileUp(Pila* p, stEmpleado e);// se usa pila como lista por que solo usamos la lista con comportamiento de pila
void pileUpDP(Pila* p, stEmpleado e);// se usa pila como lista por que solo usamos la lista con comportamiento de pila
stEmpleado unStack (Pila*p);
stEmpleado top(Pila*p);
void archToPila(char archEmployers[], Pila*p);//usamos puntero para modificarla
void showPila(Pila p);


#endif // PILA_H_INCLUDED
