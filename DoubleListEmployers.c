#include "DoubleListEmployers.h"

nodo2*inicDoubleList()//todas las inic de algo no se puede implementar con otro dato. dado que este es nodo2 donde la estructura es distinta y el tipo de dato es distinto debe de generar un inic propio.
{
    return NULL;
}

nodo2*createNewNodoDoubList(stEmpleado e)
{
    nodo2*newNodo=(nodo2*)malloc(sizeof(nodo2));
    newNodo->dat=e;
    newNodo->before=NULL;
    newNodo->next=NULL;
    return newNodo;
}

nodo2*addAtFirstDoubList(nodo2*lista,nodo2*newNodo)
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

nodo2*searchingLastNodo(nodo2*lista)
{
    nodo2*supporter = lista;
    while(supporter->next)// lo mismo que poner supporter->next != NULL
    {
        supporter=supporter->next;
    }
    return supporter;
}
nodo2*addAtheEndDoubList(nodo2*lista,nodo2*newNodo)
{
    if(!lista)
    {
        lista=newNodo;
    }
    else
    {
        nodo2*last=searchingLastNodo(lista);
        last->next=newNodo;
        newNodo->before=last;
    }
    return lista;
}
void showNodo2(nodo2*lista)
{
    mostrarEmpleado(lista->dat);
}
void showDoubleList(nodo2*lista)
{
    nodo2*supporter=lista;
    while(supporter)
    {
        showNodo2(supporter);
        supporter=supporter->next;
    }
}

nodo2*archToDoubleList(char archEmployers[],nodo2*lista)
{
    FILE*arch=fopen(archEmployers,"rb");
    stEmpleado e;
    if(arch)
    {
        while(fread(&e,sizeof(stEmpleado),1,arch) > 0)
        {
            lista=addAtFirstDoubList(lista,createNewNodoDoubList(e));
        }
        fclose(arch);
    }
    return lista;
}

stEmpleado topList2(nodo2* lista)//retorno el primer empleado
{
    return lista->dat;
}

//hacer borrarPrimer nodo y los demas borrar

void eraseFirstDobleList(nodo2**lista)
{
    nodo2*aux;
    if((*lista))
    {
        aux=(*lista);
        (*lista)=(*lista)->next;
        if((*lista))
        {
            (*lista)->before=NULL;
        }
        free(aux);
    }
}
void eraseLastDobleList(nodo2**lista)
{
    nodo2*aux=(*lista);
    nodo2*previous;
    if(aux)
    {
        while(aux->next)
        {
            previous=aux;
            aux=aux->next;
            aux->before=previous;
        }
        previous->next=aux->next;
        free(aux);
    }
}

void*eraseSpecificDoubleNodoByDniDP(nodo2**lista,char dni[])
{
    nodo2*previous=inicDoubleList();
    if((*lista))
    {
        if( strcmp((*lista)->dat.persona.dni,dni)==0 )
        {
            eraseFirstDobleList(lista);
        }
        else
        {
            nodo2*previous=inicDoubleList();
            nodo2*aux=inicDoubleList();
            aux=(*lista);
            while(aux && strcmp(aux->dat.persona.dni,dni)!=0)
            {
                previous=aux;
                aux=aux->next;
            }
            if(aux)
            {
                nodo2*following=aux->next;
                if(following)
                {
                    following->before=previous;
                }
                previous->next=following;
                free(aux);

            }
        }
    }
}

