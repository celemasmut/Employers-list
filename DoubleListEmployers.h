#ifndef DOUBLELISTEMPLOYERS_H_INCLUDED
#define DOUBLELISTEMPLOYERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "employers.h"

typedef struct _nodo2
{
    stEmpleado dat;
    struct _nodo2*before;
    struct _nodo2*next;
}nodo2;


nodo2*inicDoubleList();//todas las inic de algo no se puede implementar con otro dato. dado que este es nodo2 donde la estructura es distinta y el tipo de dato es distinto debe de generar un inic propio.
nodo2*createNewNodoDoubList(stEmpleado);
void showDoubleList(nodo2*lista);
void showNodo2(nodo2*lista);
nodo2*addAtheEndDoubList(nodo2*lista,nodo2*newNodo);
nodo2*searchingLastNodo(nodo2*lista);
nodo2*addAtFirstDoubList(nodo2*lista,nodo2*newNodo);
nodo2*archToDoubleList(char archEmployers[],nodo2*lista);
stEmpleado topList2(nodo2* lista);//retorno el primer empleado
void eraseFirstDobleList(nodo2**lista);
void eraseLastDobleList(nodo2**lista);
void*eraseSpecificDoubleNodoByDniDP(nodo2**lista,char dni[]);



#endif // DOUBLELISTEMPLOYERS_H_INCLUDED
