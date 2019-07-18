#include "post.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EPost* post_new()
{
    EPost* this;
    this=malloc(sizeof(EPost));
    return this;
}

void post_delete(EPost* this)
{
    free(this);
}

EPost* post_newConParametros(int id_mensaje,char* mensaje,int popularidad,int id_usuario)
{
    EPost* this;
    this=post_new();

    if(
    !post_setId_mensaje(this,id_mensaje)&&
    !post_setMensaje(this,mensaje)&&
    !post_setPopularidad(this,popularidad)&&
    !post_setId_usuario(this,id_usuario))
        return this;

    post_delete(this);
    return NULL;
}

int post_setId_mensaje(EPost* this,int id_mensaje)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_mensaje=id_mensaje;
        retorno=0;
    }
    return retorno;
}

int post_getId_mensaje(EPost* this,int* id_mensaje)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_mensaje=this->id_mensaje;
        retorno=0;
    }
    return retorno;
}

int post_setMensaje(EPost* this,char* mensaje)
{
    int retorno=-1;
    if(this!=NULL && mensaje!=NULL)
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}

int post_getMensaje(EPost* this,char* mensaje)
{
    int retorno=-1;
    if(this!=NULL && mensaje!=NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno=0;
    }
    return retorno;
}

int post_setPopularidad(EPost* this,int popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->popularidad=popularidad;
        retorno=0;
    }
    return retorno;
}

int post_getPopularidad(EPost* this,int* popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *popularidad=this->popularidad;
        retorno=0;
    }
    return retorno;
}

int post_setId_usuario(EPost* this,int id_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_usuario=id_usuario;
        retorno=0;
    }
    return retorno;
}

int post_getId_usuario(EPost* this,int* id_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_usuario=this->id_usuario;
        retorno=0;
    }
    return retorno;
}

