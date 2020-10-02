#include "IntDoubleList.h"
#include "DoubleListEmployers.h"

nodo2Int*inicIntDoubleList()//todas las inic de algo no se puede implementar con otro dato. dado que este es nodo2 donde la estructura es distinta y el tipo de dato es distinto debe de generar un inic propio.
{
    return NULL;
}

nodo2Int*createIntNodo2(int dat)
{
    nodo2Int*aux=(nodo2Int*)malloc(sizeof(nodo2Int));
    aux->number=dat;
    aux->next=NULL;
    aux->before=NULL;
    return aux;
}

nodo2Int*addAtFirstIntDoubList(nodo2Int*lista,nodo2Int*newNodo)
{
    if(lista==NULL)//consulto si la lista esta vacia
    {
        lista=newNodo;
    }
    else//consulto si la lista tiene dato la vinculo
    {
        newNodo->next=lista;
        lista->before=newNodo;
        lista=newNodo;
    }
    return lista;
}
//searchingLastNodo
//addAtheEndDoubList

void addDoubleNodoGrowing(nodo2Int**lista,nodo2Int*newNodo)
{
    if((*lista)==NULL)
    {
        (*lista)=newNodo;
    }
    else
    {
        nodo2Int*supporter=(*lista)->next;
        nodo2Int*previous=(*lista);
        while(supporter!=NULL && newNodo->number > supporter->number)
        {
            previous=supporter;
            supporter=supporter->next;
        }
        previous->next=newNodo;
        newNodo->before=previous;
        newNodo->next=supporter;
        if(supporter)
        {
            supporter->before=newNodo;
        }
    }

}

nodo2Int*loadList(nodo2Int*lista)
{
    int dat;
    char control;
    nodo2Int*newnodo;
    do
    {
        printf("Number: ");
        scanf("%d",&dat);
        newnodo=createIntNodo2(dat);
        lista=addAtFirstIntDoubList(lista,newnodo);
        printf(" \n........ESC to finish \n");
        control=getch();
    }
    while(control!=27);
    return lista;
}

void showIntNodo2(nodo2Int*lista)
{
    printf("\nNumero:......%d\n",lista->number);
}

void showIntList2(nodo2Int*lista)
{
    nodo2Int*supporter=lista;
    if(supporter)
    {
        showIntNodo2(supporter);
        showIntList2(supporter->next);
    }
}
nodo2Int*searchingLastIntNodo(nodo2Int*lista)
{
    nodo2Int*supporter = lista;
    while(supporter->next)// lo mismo que poner supporter->next != NULL
    {
        supporter=supporter->next;
    }
    return supporter;
}

int palindromeList(nodo2Int*first,nodo2Int*last)
{
    int asw=1;
    if(first && last)
    {
        if (first->number == last->number)
        {
            if(first != last)

            {
                asw=palindromeList(first->next,last->before);
            }
        }
        else
        {
            asw=0;
        }
    }
    return asw;
}

void muestraDirecciones(nodo2Int* lista)
{
    printf("\n nodo: %p - nodo->anterior: %p - nodo->siguiente: %p",  lista, lista->before, lista->next);
    showIntNodo2(lista);
}

void eraseIntNodoIntheMiddleOfLista(nodo2Int**lista)
{
    nodo2Int*first;
    nodo2Int*last;
    if((*lista)->next == NULL)
    {
        free(*lista);
    }
    else
    {
        first=(*lista);
        last=searchingLastIntNodo(*lista);
        nodo2Int*copyLast;
      /*  muestraDirecciones(first);
        muestraDirecciones(last);*/
        while( first->next != last->before  && first->next != last)//no corta
        {

            first=first->next;
            last=last->before;
          /*  muestraDirecciones(first);
            muestraDirecciones(last);
            system("pause");*/
        }
        if(first->next == last->before)
        {
            copyLast=last;
            last=last->before;
            first->next=copyLast;
            copyLast->before=first;
        }
        else
        {
            copyLast=last->next;
            first->next=copyLast;
            copyLast->before=first;
        }
        free(last);
    }
}
