#ifndef DPLISTOFEMPLOYERS_H_INCLUDED
#define DPLISTOFEMPLOYERS_H_INCLUDED
#include "listOfEmployers.h"
#include "PILA.h"
/*typedef struct _nodoDP  //elimina los warnings
{
    stEmpleado dat;
    struct _nodoDP*next;
}nodoDP;*/
nodo* inicListDP();
nodo* createNewNodoDP(stEmpleado e);
void addAtFirstDP(nodo**lista,nodo*newNodo);//paso por parametro lista con puntero doble para modificar por parametro por lo que no se necesita el retorno de lista
void addAtFirstDPpro(nodo**lista,nodo*newNodo);
void  eraseFirstNodoDP(nodo**lista);
nodo*archToListDP1(nodo*lista,char archEmployers[]);
void archToListDP2(nodo**lista,char archEmployers[]);
void addAtLastDP(nodo**lista,nodo*newNodo);
void eraseListaDP(nodo** lista);//borra toda la lista
void addInOrderByDniDP(nodo**lista,nodo*newNodo);
void eraseSpecificNodoByDniDP(nodo**lista, char dni[]);
void eraseLastNodoDP(nodo**lista);
void pilaToLista(Pila p, nodo**lista);


#endif // DPLISTOFEMPLOYERS_H_INCLUDED
