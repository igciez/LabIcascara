#ifndef REPARTO_H_INCLUDED
#define REPARTO_H_INCLUDED
#include "utn.h"
#include "reparto.h"
#include "parser.h"
#include "ArrayList.h"
typedef struct
{
    int id;
    char producto[250];
    char direccion[250];
    char localidad[250];
    char recibe[250];
}EReparto;

EReparto* reparto_new();
void reparto_delete();
EReparto* reparto_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe);

int reparto_setId(EReparto* this,int id);
int reparto_getId(EReparto* this,int* id);

int reparto_setProducto(EReparto* this,char* producto);
int reparto_getProducto(EReparto* this,char* producto);

int reparto_setDireccion(EReparto* this,char* direccion);
int reparto_getDireccion(EReparto* this,char* direccion);

int reparto_setLocalidad(EReparto* this,char* localidad);
int reparto_getLocalidad(EReparto* this,char* localidad);

int reparto_setRecibe(EReparto* this,char* recibe);
int reparto_getRecibe(EReparto* this,char* recibe);
int  reparto_separarLocalidadesRepetidas(ArrayList* this,ArrayList* this2);
int reparto_imprimirRepartos(void* item);
int reparto_compareLocalidad(void* pClienteA,void* pClienteB);
int reparto_cargarDatosAlArchivo(char *name,ArrayList* this);
int reparto_agregarAlArraylistDeLocalidades(ArrayList* this,char* localidadIngresada,ArrayList*arrayListLocalidades);
#endif // REPARTO_H_INCLUDED

