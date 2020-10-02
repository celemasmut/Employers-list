#include "PILA.h"


void inicPila(Pila*p)
{
    (*p)=inicList();// a lo que apunta p
}

int emptyPila(Pila*p)
{
    int rta=0;
    if((*p)==NULL)
    {
        rta=1;
    }
    return rta;
}
int emptyPilaPro(Pila*p)//ternario
{
    return ((*p)==NULL)?1:0;// si la condicion es V retorna lo que esta desp del signo de interrogacion si es F retorna lo que hay despues de los :
}

void pileUp(Pila* p, stEmpleado e)// se usa pila como lista por que solo usamos la lista con comportamiento de pila
{
    (*p)=addInOrderByDni((*p),createNewNodo(e));
}

void pileUpDP(Pila* p, stEmpleado e)// se usa pila como lista por que solo usamos la lista con comportamiento de pila
{
    addAtFirstDP(p,createNewNodo(e));
}

//desapilar va a ser del tipo de dato que se desapila
stEmpleado unStack (Pila*p)
{
    stEmpleado e = topList(*p);
    (*p)=eraseFirstNodo(*p);
    return e;
}

stEmpleado top(Pila*p)
{
    return topList(*p);
}
//7
void archToPila(char archEmployers[], Pila*p)//usamos puntero para modificarla
{
    stEmpleado e;
    FILE *arch=fopen(archEmployers,"rb");
    if(arch)
    {
        while(fread(&e,sizeof(stEmpleado),1,arch) > 0) // se lee el dato de empleado en el archivo
        {
            pileUp(p,e);//pide doble pero como tenemos enmascarado
        }
        fclose(arch);
    }
}
void showPila(Pila p)
{
    Pila aux;
    inicPila(&aux);//usamos ampersand por que la funcion pide puntero
    while(!emptyPila(&p))//pasamos ampersand por que por que la funcion solicita puntero y por parametro no vino la pila con puntero.
    {
        mostrarEmpleado(top(&p));
        pileUp(&aux,unStack(&p));

    }
    while(!emptyPila(&aux))//para no perder la pila
    {
        pileUp(&p,unStack(&aux));
    }
}

