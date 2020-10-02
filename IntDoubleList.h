#ifndef INTDOUBLELIST_H_INCLUDED
#define INTDOUBLELIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>


typedef struct _nodoint
{
    int number;
    struct _nodoint*next;
    struct _nodoint*before;
}nodo2Int;

nodo2Int*inicIntDoubleList();//todas las inic de algo no se puede implementar con otro dato. dado que este es nodo2 donde la estructura es distinta y el tipo de dato es distinto debe de generar un inic propio.

nodo2Int*createIntNodo2(int dat);
void addDoubleNodoGrowing(nodo2Int**lista,nodo2Int*newNodo);
nodo2Int*loadList(nodo2Int*lista);
nodo2Int*addAtFirstIntDoubList(nodo2Int*lista,nodo2Int*newNodo);
nodo2Int*searchingLastIntNodo(nodo2Int*lista);
void muestraDirecciones(nodo2Int* lista);
void eraseIntNodoIntheMiddleOfLista(nodo2Int**lista);

void showIntNodo2(nodo2Int*lista);
void showIntList2(nodo2Int*lista);
int palindromeList(nodo2Int*first,nodo2Int*last);


#endif // INTDOUBLELIST_H_INCLUDED
