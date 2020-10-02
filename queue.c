#include "queue.h"

void inicQueue(Queue*theQueue)
{
    theQueue->first=NULL;
    theQueue->last=NULL;
}
void addToQueue(Queue*theQueue, stEmpleado e)
{
    nodo2*newNodo=createNewNodoDoubList(e);
    theQueue->last=addAtheEndDoubList(theQueue->last,newNodo);//en caso de pasar null va a retornar el nodo nuevo por unica vez.
    if(theQueue->first == NULL)
    {
        theQueue->first=newNodo;
    }
    theQueue->last=newNodo;
}

stEmpleado toExtract(Queue*theQueue)
{
    stEmpleado e;
    if(theQueue->first)
    {
        e=topList2(theQueue->first);
        eraseFirstDobleList(&theQueue->first); //borrar primer nodo
        if(!theQueue->first)//se evalua inicio por si saque el ultimo dato de la fila
        {
            theQueue->last=inicDoubleList();
        }
    }
    return e;
}

void firstOnTheQueue(Queue*theQueue)//muestra primero
{
    if(theQueue->first)
    {
        showNodo2(theQueue->first);
    }
}
void lastOnTheQueue(Queue*theQueue)//muestra primero
{
    if(theQueue->last)
    {
        showNodo2(theQueue->last);
    }
}
void showQueue(Queue*theQueue)//
{
    showDoubleList(theQueue->first);
}
int emptyQueue(Queue*thequeue)
{
    int flag=0;
    if(!thequeue->first)// igual a theQueue->first == NULL
    {
        flag=1;
    }
    return flag;
}
int emptyQueuePro(Queue*theQueue)
{
    return (theQueue->first)?0:1;
}
