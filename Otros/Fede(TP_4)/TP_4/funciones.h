#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
#include "cliente.h"


void imprimirClientes(ArrayList* pArray);
ArrayList* empleadosSoloMujeres(ArrayList* pArray);
int encontrarPersonaPorId(ArrayList* pArray, int id, int* indice);
void limpiarArray(ArrayList* pArray);

#endif // FUNCIONES_H_INCLUDED
