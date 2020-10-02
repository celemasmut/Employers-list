#include "listOfEmployers.h"
#include "DPListOfEmployers.h"
#include "employers.h"


nodo* inicList()
{
    return NULL;
}

nodo* createNewNodo(stEmpleado e)
{
    nodo* aux= (nodo*)malloc(sizeof(nodo));
    aux->dat=e;
    aux->next=NULL;
    return aux;
}

nodo* addAtFirst(nodo*lista,nodo*newNodo)//lo que paso por parametro es una copia por eso retornamos la lista.
{
    if(lista==NULL)
    {
        lista=newNodo;
    }
    else
    {
        newNodo->next=lista;
        lista=newNodo;
    }
    return lista;
}

void showNodo(nodo* emploNodo)
{
    mostrarEmpleado(emploNodo->dat);
}


stEmpleado topList(nodo* lista)//retorno el primer empleado
{
    return lista->dat;
}
void showList(nodo*lista)//elrecorrido iterativo se realiza sobre una auxiliar por las dudas
{
    nodo*aux=lista;
    while(aux) // es = a (aux!=NULL)
    {
        showNodo(aux);
        aux=aux->next; //apunto al siguiente nodo para el ciclo.
    }
}

nodo* lookingForLastOne(nodo*lista)
{
    nodo*last=lista;
    while(last->next)// se necesita que el ultimo apunte a null
    {
        last=last->next;
    }
    return last;//se retorna el ultimo nodo
}
nodo*addAtLast(nodo*lista,nodo*newNodo)
{
    if(lista==NULL)
    {
        lista=newNodo;
    }
    else
    {
        nodo*last=lookingForLastOne(lista);
        last->next=newNodo;
    }
    return lista;
}
// 1 y 2
nodo*archToList(nodo*lista,char archEmployers[])
{
    stEmpleado e;
    FILE *arch=fopen(archEmployers,"rb");
    if(arch)
    {
        while(fread(&e,sizeof(stEmpleado),1,arch) > 0) // se lee el dato de empleado en el archivo
        {
            // lista = addAtFirst(lista,createNewNodo(e));
            // lista= addAtLast(lista,createNewNodo(e));
          //  lista = addInOrderByDni(lista,createNewNodo(e));
            addInOrderByDniDP(&lista,createNewNodo(e));
        }
        fclose(arch);
    }
  //  return lista;
}

nodo* eraseLista(nodo* lista)//borra toda la lista
{
    nodo*prox;
    nodo*next=lista;
    while(next)
    {
        prox=next->next;
        free(next);
        next=prox;
    }
    return next;//apunta a null, lista vacia
}
//2
nodo*addInOrderByDni(nodo*lista,nodo*newNodo)
{
    if(lista== NULL)//primera posibilidad verficar si la lusta es nula
    {
        lista=newNodo;
    }
    else
    {
        if(atoi(newNodo->dat.persona.dni) < atoi(lista->dat.persona.dni))//segunda posibilidad, se evalua si el dato nuevo es menor al primer dato de la lista
        {
            lista=addAtFirst(lista,newNodo);
        }
        else
        {
            nodo*before=lista;//puntero a la lista que va a a ser la anterior
            nodo*next=lista->next;//puntero al siguiente nodo de la lista
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
    return lista;
}
//3
nodo*lookingForSpecificNodoByDni(nodo*lista,char dni[10])
{
    nodo*aux=lista;
    while(atoi(aux->dat.persona.dni) != atoi(dni))
    {
        aux=aux->next;
    }
    return aux;
}
//4
nodo*toMergeListasPorId(nodo*lista_A,nodo*lista_B)//intercalar
{
    nodo*aux;
    nodo*destiny=NULL;

    while(lista_A && lista_B)//recorre hasta que alguna quede vacia o que las dos queden vacias
    {
        if(lista_A->dat.id < lista_B->dat.id)//comparo si A es menor a B
        {
            aux=lista_A;//guardo dato  para luego moverme
            lista_A=lista_A->next;//me muevo para comparar en el ciclo
        }
        else
        {
            aux=lista_B;
            lista_B=lista_B->next;

        }
        aux->next=NULL;//desvinculo nodo
        destiny=addAtLast(destiny,aux);//agrego al final el nodo menor desvinculado

    }
    if(lista_A)//si en lista A todavia quedo datos
    {
        destiny=addAtLast(destiny,lista_A);
    }
    if(lista_B)
    {
        destiny=addAtLast(destiny,lista_B);
    }
    return destiny;//retorno nueva lista intercalada.
}
//8
nodo*eraseSpecificNodoByDni(nodo*lista, char dni[])
{
    nodo*next;
    nodo*before;
    if(lista && strcmp(lista->dat.persona.dni,dni)==0)//primer plateo es comparar con el primero
    {
        nodo*aux=lista;//copio la direccion de memoria del primer nodo de lista
        lista=lista->next;//me muevo
        free(aux);//desvinculo y borro. Free libera la memoria
    }
    else
    {
        next=lista;
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
    return lista;
}
//6
nodo* toReverseList(nodo*lista)//invierto lista
{
    nodo*inverted=inicList();
    nodo*aux;
    while(lista)
    {
        aux=lista;
        lista=lista->next;
        aux->next=NULL;
        inverted=addAtFirst(inverted,aux);
    }
    return inverted;
}

nodo* eraseLastNodo(nodo*lista)
{
    nodo*aux=lista;
    nodo*before;
    while(aux->next)//usamos el puntero next para que ciclo cuando termine quede parado en el ultimo nodo a eliminar
    {
        before=aux;//guardo nodo actual.
        aux=aux->next;//me muevo. ciclo continual hasta que llegue a null
    }
    free(aux);
    before->next=NULL;

    return lista;
}

nodo* eraseFirstNodo(nodo*lista)
{
    nodo*aux=lista;
    lista=lista->next;
    free(aux);
    return lista;
}

void showRecursiveList(nodo*lista)// aca no se usa auxiliar por que la llamada recursiva es un viaje de ida y vuelta
{
    if(lista)//condicion de corte, solucion trivial implicita
    {
        showNodo(lista);
        showRecursiveList(lista->next);//llamada recursiva y acercamiento a la condicion de corte
    }
}
int sumRecursiveList(nodo*lista)
{
    int sum=0;
    if(lista)
    {
       sum=lista->dat.sueldo + sumRecursiveList(lista->next);
    }
    return sum;
}
int sumRecursiveListPROO(nodo*lista)
{
    return (lista)?lista->dat.sueldo+sumRecursiveListPROO(lista->next):0;
}

