#include "depositoI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eDepositoI* depositoI_new()
{
    eDepositoI* this;
    this=malloc(sizeof(eDepositoI));
    return this;
}

void depositoI_delete(eDepositoI* this)
{
    free(this);
}

eDepositoI* depositoI_newConParametros(int producto,char* descripcion,int cantidad)
{
    eDepositoI* this;
    this=depositoI_new();

    if(
    !depositoI_setProducto(this,producto)&&
    !depositoI_setDescripcion(this,descripcion)&&
    !depositoI_setCantidad(this,cantidad))
        return this;

    depositoI_delete(this);
    return NULL;
}

int depositoI_setProducto(eDepositoI* this,int producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->producto=producto;
        retorno=0;
    }
    return retorno;
}

int depositoI_getProducto(eDepositoI* this,int* producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *producto=this->producto;
        retorno=0;
    }
    return retorno;
}

int depositoI_setDescripcion(eDepositoI* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int depositoI_getDescripcion(eDepositoI* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int depositoI_setCantidad(eDepositoI* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int depositoI_getCantidad(eDepositoI* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

