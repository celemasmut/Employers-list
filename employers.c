#include "employers.h"
char archivo1[]="employers.bin";// si no pongo archivo aca da error


stPersona Persona ()
{
    stPersona aux;
    char dni[10];
    printf("Nombre....... ");
    fflush(stdin);
    gets(aux.nombre);
    printf("Apellido....... ");
    fflush(stdin);
    gets(aux.apellido);
    printf("Dni....... ");
    gets(dni);
    while((verificarDNI(dni)) == 1)
    {
        printf("Error. el DNI ya existe. \nVuelva a cargar DNI: ");
        gets(dni);
    }
    strcpy(aux.dni,dni);

    return aux;
}
int verificarDNI(char dni[])
{
    stEmpleado aux;
    int flag=0;
    FILE*empresa=fopen(archivo1,"rb");
    fseek(empresa,0,SEEK_SET);
    while(flag == 0 && (fread(&aux,sizeof(stEmpleado),1,empresa)) > 0)
    {
        if((strcmp(dni,aux.persona.dni)) == 0)
        {
            flag=1;
        }
    }
    return flag;
}

stEmpleado empleado()
{
    stEmpleado aux;
    aux.id=id(archivo1)+1;
    printf("\nid: %i\n",aux.id);
    aux.persona=Persona();
    printf("\nCuil: ");
    fflush(stdin);
    gets(aux.cuil);
    printf("\nEmail: ");
    fflush(stdin);
    gets(aux.email);
    printf("\nSalary: ");
    scanf("%d",&aux.sueldo);
    return aux;
}

int id(char archivo1[])
{
    stEmpleado e;
    int id = 0;
    FILE *archi=fopen(archivo1, "rb");

    if(archi)   /// if(archi != NULL)
    {
        fseek(archi, sizeof(stEmpleado)*(-1),SEEK_END);
        if(fread(&e,sizeof(stEmpleado),1,archi) > 0)
        {
            id=e.id;
        }
        fclose(archi);
    }

    return id;
}


void ingresaEmpleadoArchivo()
{
    stEmpleado aux;
    char opcion;

    do
    {
        aux = empleado();
        guardaEmpleadoArchivo(archivo1, aux);

        printf("\n ESC para salir..... ");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=27);
}

void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado aux)
{
    FILE *archi=fopen(archivoEmpleados,"ab");
    if(archi)
    {
        fwrite(&aux,sizeof(stEmpleado),1,archi);
        fclose(archi);
    }
}
void mostrarEmpleado(stEmpleado aux)
{
   /* printf("\nID..... %d",aux.id);
    fflush(stdin);*/
    printf("\nName and Last name...%s %s",aux.persona.nombre,aux.persona.apellido);
    fflush(stdin);
    printf("\nDni.... %s",aux.persona.dni);
    fflush(stdin);
    printf("\nCuil.... %s",aux.cuil);
    fflush(stdin);
    printf("\nEmail..... %s",aux.email);
    printf("\nSalary....$ %d",aux.sueldo);
    fflush(stdin);
    printf("\n---------------");

}
void mostrarArchivoEmpleado()
{
    stEmpleado aux;
    FILE*empresa;
    empresa=fopen(archivo1,"rb");
    while((fread(&aux,sizeof(stEmpleado),1,empresa)) > 0)
    {
        mostrarEmpleado(aux);
    }
    fclose(empresa);
}
int cuentaRegistros(char archivo[], int dataSize)
{
    int cantidad;
    FILE*origen=fopen(archivo,"rb");
    if(origen!=NULL)
    {
        fseek(origen,0,SEEK_END);
        cantidad=ftell(origen)/dataSize;
    }
    fclose(origen);
    return cantidad;
}
