#ifndef EMPLOYERS_H_INCLUDED
#define EMPLOYERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char apellido [30];
    char nombre[30];
    char dni [10];
} stPersona;

typedef struct
{
    int id;
    stPersona persona;
    char cuil [15];
    char email[90];
    char domicilioParticular[50];
    char TelefonoFijo[15];
    char TelefonoCel[15];
    int idTipo;
    int sueldo;
} stEmpleado;

stPersona Persona ();
int verificarDNI(char dni[]);
stEmpleado empleado();
int id(char archivo1[]);
void ingresaEmpleadoArchivo();
void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado aux);
void mostrarEmpleado(stEmpleado aux);
void mostrarArchivoEmpleado();
int cuentaRegistros(char file[], int dataSize);


#endif // EMPLOYERS_H_INCLUDED
