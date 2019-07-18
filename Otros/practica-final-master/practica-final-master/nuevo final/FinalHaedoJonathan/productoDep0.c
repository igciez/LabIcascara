#include "productoDep0.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EProducto* producto_new()
{
    EProducto* this;
    this=malloc(sizeof(EProducto));
    return this;
}

void producto_delete(EProducto* this)
{
    free(this);
}

EProducto* producto_newConParametros(int producto,char* descripcion,int cantidad)
{
    EProducto* this;
    this=producto_new();

    if(
    !producto_setProducto(this,producto)&&
    !producto_setDescripcion(this,descripcion)&&
    !producto_setCantidad(this,cantidad))
        return this;

    producto_delete(this);
    return NULL;
}

int producto_setProducto(EProducto* this,int producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->producto=producto;
        retorno=0;
    }
    return retorno;
}

int producto_getProducto(EProducto* this,int* producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *producto=this->producto;
        retorno=0;
    }
    return retorno;
}

int producto_setDescripcion(EProducto* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int producto_getDescripcion(EProducto* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int producto_setCantidad(EProducto* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int producto_getCantidad(EProducto* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

