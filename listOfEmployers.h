#ifndef LISTOFEMPLOYERS_H_INCLUDED
#define LISTOFEMPLOYERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "employers.h"


typedef struct _nodo //elimina los warnings
{
    stEmpleado dat;
    struct _nodo*next;
}nodo;

nodo* inicList();
nodo* createNewNodo(stEmpleado e);
nodo* addAtFirst(nodo*lista,nodo* newNodo);
nodo*addAtLast(nodo*lista,nodo*newNodo);
void showNodo(nodo* emploNodo);
void showList(nodo*lista);
nodo* lookingForLastOne(nodo*lista);
nodo* eraseLista(nodo* lista);//borra toda la lista
nodo*archToList(nodo*lista,char archEmployers[]);
nodo*addInOrderByDni(nodo*lista,nodo*newNodo);
nodo*lookingForSpecificNodoByDni(nodo*lista,char dni[10]);
nodo*toMergeListasPorId(nodo*lista_A,nodo*lista_B);//intercalar
nodo*eraseSpecificNodoByDni(nodo*lista, char dni[]);
nodo* toReverseList(nodo*lista);//invierto lista
nodo* eraseLastNodo(nodo*lista);
nodo* eraseFirstNodo(nodo*lista);
stEmpleado topList(nodo* lista);//retorno el primer empleado
void showRecursiveList(nodo*lista);
int sumRecursiveList(nodo*lista);
int sumRecursiveListPROO(nodo*lista);


#endif // LISTOFEMPLOYERS_H_INCLUDED
