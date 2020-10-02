#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DoubleListEmployers.h"

typedef struct
{
    struct nodo2*first;
    struct nodo2*last;
}Queue;

void inicQueue(Queue*theQueue);
void addToQueue(Queue*theQueue, stEmpleado e);
void firstOnTheQueue(Queue*theQueue);
void showQueue(Queue*theQueue);
stEmpleado toExtract(Queue*theQueue);
int emptyQueue(Queue*thequeue);
int emptyQueuePro(Queue*theQueue);
void lastOnTheQueue(Queue*theQueue);//muestra primero




#endif // QUEUE_H_INCLUDED
