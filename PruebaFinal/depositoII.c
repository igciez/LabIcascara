#include "depositoII.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eDepositoII* depositoII_new()
{
    eDepositoII* this;
    this=malloc(sizeof(eDepositoII));
    return this;
}

void depositoII_delete(eDepositoII* this)
{
    free(this);
}

eDepositoII* depositoII_newConParametros(int producto,char* descripcion,int cantidad)
{
    eDepositoII* this;
    this=depositoII_new();

    if(
    !depositoII_setProducto(this,producto)&&
    !depositoII_setDescripcion(this,descripcion)&&
    !depositoII_setCantidad(this,cantidad))
        return this;

    depositoII_delete(this);
    return NULL;
}

int depositoII_setProducto(eDepositoII* this,int producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->producto=producto;
        retorno=0;
    }
    return retorno;
}

int depositoII_getProducto(eDepositoII* this,int* producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *producto=this->producto;
        retorno=0;
    }
    return retorno;
}

int depositoII_setDescripcion(eDepositoII* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int depositoII_getDescripcion(eDepositoII* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int depositoII_setCantidad(eDepositoII* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int depositoII_getCantidad(eDepositoII* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

