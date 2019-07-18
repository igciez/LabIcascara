#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "ArrayList.h"
#include "utn.h"
#include "parser.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}EEmpleado;

EEmpleado* Empleado_new();
void Empleado_delete();

int Empleado_setId(EEmpleado* this,int id);
int Empleado_getId(EEmpleado* this,int* id);

int Empleado_setNombre(EEmpleado* this,char* nombre);
int Empleado_getNombre(EEmpleado* this,char* nombre);

int Empleado_setHorasTrabajadas(EEmpleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(EEmpleado* this,int* horasTrabajadas);

int Empleado_setSueldo(EEmpleado* this,int sueldo);
int Empleado_getSueldo(EEmpleado* this,int* sueldo);
EEmpleado* Empleado_newParametros(char *strName,char* strId,char*strHsTrabajadas);

int Empleado_calcularSueldo(void* pElement);
int generarArchivoSueldos(char* fileName,ArrayList* this);
int imprimirDatos(ArrayList* this);
int Empleado_sueldoMayorA(void* item);

#endif // EMPLEADO_H_INCLUDED
