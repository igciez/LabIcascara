#include "productoDep1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EProductoDep1* productoDep1_new()
{
    EProductoDep1* this;
    this=malloc(sizeof(EProductoDep1));
    return this;
}

void productoDep1_delete(EProductoDep1* this)
{
    free(this);
}

EProductoDep1* productoDep1_newConParametros(int producto,char* descripcion,int cantidad)
{
    EProductoDep1* this;
    this=productoDep1_new();

    if(
    !productoDep1_setProducto(this,producto)&&
    !productoDep1_setDescripcion(this,descripcion)&&
    !productoDep1_setCantidad(this,cantidad))
        return this;

    productoDep1_delete(this);
    return NULL;
}

int productoDep1_setProducto(EProductoDep1* this,int producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->producto=producto;
        retorno=0;
    }
    return retorno;
}

int productoDep1_getProducto(EProductoDep1* this,int* producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *producto=this->producto;
        retorno=0;
    }
    return retorno;
}

int productoDep1_setDescripcion(EProductoDep1* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int productoDep1_getDescripcion(EProductoDep1* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int productoDep1_setCantidad(EProductoDep1* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int productoDep1_getCantidad(EProductoDep1* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

