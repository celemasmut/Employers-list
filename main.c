#include <stdio.h>
#include <stdlib.h>
#include "listOfEmployers.h"
#include "employers.h"
#include "DPListOfEmployers.h"
#include "PILA.h"
#include "queue.h"
#include "IntDoubleList.h"
#define archivo1 "employers.bin"

#define DIM_EMP 100

void menu();
void switchMenu();
void doubleListToQueue(nodo2*lista, Queue*myQueue);
void answewPalindrome(int asw);





int main()
{
    switchMenu();

    return 0;
}

void menu ()
{
    printf("\n\t [--->  Menu for Lists / Double Pointer / Stack / Queue / Double Lists / Recursion Lists <---]\n\n");
    printf("\n 1 - File to List in an ordered way by DNI with double pointer");
    printf("\n 2 - Searching for an specific DNI");
    printf("\n 3 - FILE to Stack / Stack´s top / Show stack");
    printf("\n 4 - To reverse a list");
    printf("\n 5. - Stack to List.Adding at the end of the list only those even Dni's and ussing double pointer");
    printf("\n 6 - Erase an specific nodo by DNI with double pointer. For this please first execute number 2");
    printf("\n 7 - Erase list with double pointer");
    printf("\n 8 - FIle to a Double list ");
    printf("\n 9 - Erase the first Nodo of a double list");
    printf("\n a - Erase the last Nodo of a double list");
    printf("\n b - Erase an specific Nodo of a double list");
    printf("\n c - Load some numbers and see if the list is or is not palindrome");
    printf("\n d - Erase nodo in the middle of the list");
    printf("\n e - Load List to Queue / show first and last");
    printf("\n f - To extract first on the queue and show queue");

    printf("\n\n ---------> ESC para salir....\n");
}

void switchMenu()
{
    char option;
    stEmpleado e;
    nodo*lista;
    nodo*pila2list=inicList();
    nodo*wanted=inicList();
    lista=inicList();
    nodo*inverted=inicList();

    //usamos un nodo emmascarado en pila
    Pila pila;
    inicPila(&pila);

    nodo2*doubList=inicDoubleList();
    nodo2Int*int2List=inicIntDoubleList();

    Queue employersQueue;
    inicQueue(&employersQueue);

    do
    {
        menu();
        option=getch();

        switch(option)
        {
        case 49:
            archToListDP2(&lista,archivo1);
            showList(lista);
            system("pause");
            printf("\n -------------------The last employer-------------------- \n ");
            showNodo(lookingForLastOne(lista));
            system("pause");
            break;
        case 50:
            wanted=lookingForSpecificNodoByDni(lista,"5234876");
            printf("\n -------------------The searched employer-------------------- \n ");
            showNodo(wanted);
            system("pause");
            break;
        case 51:
            archToPila(archivo1,&pila);
            showPila(pila);
            system("pause");
            printf("\n -------------------TOP Pila-------------------- \n ");
            mostrarEmpleado(top(&pila));
            system("pause");
            break;
        case 52:
            inverted=toReverseList(lista);// es posible que esta funcion haga que no pueda ejecutar el 6
            showList(inverted);
            system("pause");
            break;
        case 53:
            if(!emptyPilaPro(&pila))
            {
                pilaToLista(pila,&pila2list);
                showList(pila2list);
                system("pause");
            }
            else
            {
                printf("\n --------------------Empty Stack-----------------\n");
                system("pause");
            }
            break;
        case 54:
            printf("\n -------------------To Erase-------------------- \n ");
            showNodo(wanted);
            system("pause");
            eraseSpecificNodoByDniDP(&pila2list,wanted->dat.persona.dni);
            showList(pila2list);
            system("pause");
            break;
        case 55:
            eraseListaDP(&lista);
            if(lista==NULL)
            {
                printf("\n --------------------Empty List-----------------\n");

            }
            system("pause");
            break;
        case 56:
            doubList=archToDoubleList(archivo1,doubList);
            showDoubleList(doubList);
            system("pause");
            break;
        case 57:
            eraseFirstDobleList(&doubList);
            showDoubleList(doubList);
            system("pause");
            break;
        case 97:
            eraseLastDobleList(&doubList);
            showDoubleList(doubList);
            system("pause");
            break;
        case 98:
            eraseSpecificDoubleNodoByDniDP(&doubList,"4753378");
            showDoubleList(doubList);
            system("pause");
            break;
        case 99:
            int2List= loadList(int2List);
            showIntList2(int2List);
            system("pause");
            system("cls");
            answewPalindrome(palindromeList(int2List,searchingLastIntNodo(int2List)));
            system("pause");
            break;
        case 100:
            system("cls");
            showIntList2(int2List);
            system("pause");
            eraseIntNodoIntheMiddleOfLista(&int2List);
            showIntList2(int2List);
            system("pause");
            break;
        case 101:
            doubleListToQueue(doubList,&employersQueue);
            firstOnTheQueue(&employersQueue);
            lastOnTheQueue(&employersQueue);
            system("pause");
            break;
        case 102:
            printf("\n--------------Complete Queue-----------\n");
            showQueue(&employersQueue);
            e=toExtract(&employersQueue);
            printf("\n--------------After-----------\n");
            showQueue(&employersQueue);
            system("pause");
            break;
        }
        system("cls");
    }
    while(option!=27);

}

void answewPalindrome(int asw)
{
    if(asw==1)
    {
        printf("\n\n     [ THE LIST IS PALINDROME!! ]\n");
    }
    else
    {
        printf("\n\n   [ THE LIST IS NOT PALINDROME D: ]\n");
    }
}

void doubleListToQueue(nodo2*lista, Queue*myQueue)
{
    if(lista)
    {
        while(lista)
        {
            addToQueue(myQueue,lista->dat);
            lista=lista->next;
        }
    }
}






