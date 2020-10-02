#include "employers.h"
#include "DPListOfEmployers.h"
#include "listOfEmployers.h"

nodo* inicListDP()
{
    return NULL;
}


void addAtFirstDP(nodo**lista,nodo*newNodo)//paso por parametro lista con puntero doble para modificar por parametro por lo que no se necesita el retorno de lista
{
    if((*lista) == NULL)
    {
        (*lista)=newNodo;
    }
    else
    {
        newNodo->next=(*lista);
        (*lista)=newNodo;
    }
}
void addAtFirstDPpro(nodo**lista,nodo*newNodo)//paso por parametro lista con puntero doble para modificar por parametro por lo que no se necesita el retorno de lista
{

    newNodo->next=(*lista);
    (*lista)=newNodo;
}

void eraseFirstNodoDP(nodo**lista)//cuandp recibo una referecia se trabaj con dato original.
{
    nodo*aux=(*lista);
    (*lista)=(*lista)->next;
    free(aux);
}
//caso 1
nodo*archToListDP1(nodo*lista,char archEmployers[])
{
    stEmpleado e;
    FILE *arch=fopen(archEmployers,"rb");
    if(arch)
    {
        while(fread(&e,sizeof(stEmpleado),1,arch) > 0) // se lee el dato de empleado en el archivo
        {

            addAtFirstDP(&lista,createNewNodo(e));//paso ampersand por qu la funcion pide un puntero doble entonces paso una refencia con el ampersand
        }
        fclose(arch);
    }
    return lista;
}
//caso2
void archToListDP2(nodo**lista,char archEmployers[])
{
    stEmpleado e;
    FILE *arch=fopen(archEmployers,"rb");
    if(arch)
    {
        while(fread(&e,sizeof(stEmpleado),1,arch) > 0) // se lee el dato de empleado en el archivo
        {
            //addInOrderByDniDP(lista,createNewNodoDP(e));

            //addAtFirstDP(lista,createNewNodoDP(e));//no uso el ampersand por que ya recibo lista como puntero doble
            addAtLastDP(lista,createNewNodo(e));
        }
        fclose(arch);
    }
    //atencion con la funcion mostrar
    // showList(*lista);// showlist pide un puntero simple y como estamoc trabajando con DP a lista se le debe pasar un * simple.
}

void addAtLastDP(nodo**lista,nodo*newNodo)
{
    if((*lista)==NULL)
    {
        (*lista)=newNodo;
    }
    else
    {
        nodo*last=lookingForLastOne(*lista);
        last->next=newNodo;
    }
}

void eraseListaDP(nodo** lista)//borra toda la lista
{
    nodo*prox;
    // nodo*next=(*lista);
    while(*lista)
    {
        prox=(*lista)->next;
        free(*lista);
        (*lista)=prox;
    }
}

void addInOrderByDniDP(nodo**lista,nodo*newNodo)
{
    if((*lista)== NULL)//primera posibilidad verficar si la lusta es nula
    {

        (*lista)=newNodo;
    }
    else
    {

        if(atoi(newNodo->dat.persona.dni) < atoi((*lista)->dat.persona.dni))//segunda posibilidad, se evalua si el dato nuevo es menor al primer dato de la lista
        {
            addAtFirstDP(lista,newNodo);
        }
        else
        {
            nodo*before=(*lista);//puntero a la lista que va a a ser la anterior
            nodo*next=(*lista)->next;//puntero al siguiente nodo de la lista
            while(next && atoi(newNodo->dat.persona.dni) >= atoi(next->dat.persona.dni))// si no cumple 1° ni 2°, recorro y comparo que el nuevo dato sea mayor o igual al
            {
                // funcion atoi convierte un string en int.
                before=next;//en caso de entrar, guardo la direccion de memoria de next.
                next=next->next;// a next le asigno al puntero del proximo nodo para seguir evaluando.

            }
            newNodo->next=next;//apunto desdee el nuevo nodo a next para no perderlo.
            before->next=newNodo;//apunto desde el nodo before a nuevo nodo. asi se inserta el nuevo nodo entre el before y next.

        }
    }
}

void eraseSpecificNodoByDniDP(nodo**lista, char dni[])
{
    nodo*next;
    nodo*before;
    if((*lista) && strcmp((*lista)->dat.persona.dni,dni)==0)//primer plateo es comparar con el primero
    {
        nodo*aux=(*lista);//copio la direccion de memoria del primer nodo de lista
        (*lista)=(*lista)->next;//me muevo
        free(aux);//desvinculo y borro. Free libera la memoria
    }
    else
    {
        next=(*lista);//copio la direccion de memoria del primer nodo de lista
        while(strcmp(next->dat.persona.dni,dni)!=0)//ciclo corta hasta que encuentre dato o quede sin datos para recorrer
        {
            before=next;//va a ser la direccion de memoria anterior al que luego voy a vincular una vez haya borrado el nodo buscado
            next=next->next;//muevo puntero
        }
        if(next)//si encuantra ej: next queda parado en 3 el num a buscar
        {
            before->next=next->next;//before apuntaba a 3 ahora lo cambiamos para que apunte a 4
            free(next);//elimino nodo desvinculado
        }
    }
}

void eraseLastNodoDP(nodo**lista)
{
    nodo*aux=(*lista);
    nodo*before;
    while(aux->next)//usamos el puntero next para que ciclo cuando termine quede parado en el ultimo nodo a eliminar
    {
        before=aux;//guardo nodo actual.
        aux=aux->next;//me muevo. ciclo continual hasta que llegue a null
    }
    free(aux);
    before->next=NULL;

}
//7.a
void pilaToLista(Pila p, nodo**lista)
{
    Pila aux;
    inicPila(&aux);
    stEmpleado e;
    while(!emptyPila(&p))
    {
        e=top(&p);
        if( atoi(e.persona.dni) %2 ==0)
        {
            addAtLastDP(lista,createNewNodo(e));
        }
        pileUp(&aux,unStack(&p));
    }
    while(!emptyPila(&aux))//para no perder la pila
    {
        pileUp(&p,unStack(&aux));
    }
}

