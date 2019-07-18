#include "feed.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EFeed* feed_new()
{
    EFeed* this;
    this=malloc(sizeof(EFeed));
    return this;
}

void feed_delete(EFeed* this)
{
    free(this);
}

EFeed* feed_newConParametros(int id_mensaje,char* mensaje,int popularidad_mensaje,int id_usuario,char* nick,int popularidad_usuario)
{
    EFeed* this;
    this=feed_new();

    if(
    !feed_setId_mensaje(this,id_mensaje)&&
    !feed_setMensaje(this,mensaje)&&
    !feed_setPopularidad_mensaje(this,popularidad_mensaje)&&
    !feed_setId_usuario(this,id_usuario)&&
    !feed_setNick(this,nick)&&
    !feed_setPopularidad_usuario(this,popularidad_usuario))
        return this;

    feed_delete(this);
    return NULL;
}

int feed_setId_mensaje(EFeed* this,int id_mensaje)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_mensaje=id_mensaje;
        retorno=0;
    }
    return retorno;
}

int feed_getId_mensaje(EFeed* this,int* id_mensaje)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_mensaje=this->id_mensaje;
        retorno=0;
    }
    return retorno;
}

int feed_setMensaje(EFeed* this,char* mensaje)
{
    int retorno=-1;
    if(this!=NULL && mensaje!=NULL)
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}

int feed_getMensaje(EFeed* this,char* mensaje)
{
    int retorno=-1;
    if(this!=NULL && mensaje!=NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno=0;
    }
    return retorno;
}

int feed_setPopularidad_mensaje(EFeed* this,int popularidad_mensaje)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->popularidad_mensaje=popularidad_mensaje;
        retorno=0;
    }
    return retorno;
}

int feed_getPopularidad_mensaje(EFeed* this,int* popularidad_mensaje)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *popularidad_mensaje=this->popularidad_mensaje;
        retorno=0;
    }
    return retorno;
}

int feed_setId_usuario(EFeed* this,int id_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_usuario=id_usuario;
        retorno=0;
    }
    return retorno;
}

int feed_getId_usuario(EFeed* this,int* id_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_usuario=this->id_usuario;
        retorno=0;
    }
    return retorno;
}

int feed_setNick(EFeed* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(this->nick,nick);
        retorno=0;
    }
    return retorno;
}

int feed_getNick(EFeed* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(nick,this->nick);
        retorno=0;
    }
    return retorno;
}

int feed_setPopularidad_usuario(EFeed* this,int popularidad_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->popularidad_usuario=popularidad_usuario;
        retorno=0;
    }
    return retorno;
}

int feed_getPopularidad_usuario(EFeed* this,int* popularidad_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *popularidad_usuario=this->popularidad_usuario;
        retorno=0;
    }
    return retorno;
}

