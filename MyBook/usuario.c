#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EUsuario* usuario_new()
{
    EUsuario* this;
    this=malloc(sizeof(EUsuario));
    return this;
}

void usuario_delete(EUsuario* this)
{
    free(this);
}

EUsuario* usuario_newConParametros(int id_usuario,char* nick,int popularidad)
{
    EUsuario* this;
    this=usuario_new();

    if(
    !usuario_setId_usuario(this,id_usuario)&&
    !usuario_setNick(this,nick)&&
    !usuario_setPopularidad(this,popularidad))
        return this;

    usuario_delete(this);
    return NULL;
}

int usuario_setId_usuario(EUsuario* this,int id_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_usuario=id_usuario;
        retorno=0;
    }
    return retorno;
}

int usuario_getId_usuario(EUsuario* this,int* id_usuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_usuario=this->id_usuario;
        retorno=0;
    }
    return retorno;
}

int usuario_setNick(EUsuario* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(this->nick,nick);
        retorno=0;
    }
    return retorno;
}

int usuario_getNick(EUsuario* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(nick,this->nick);
        retorno=0;
    }
    return retorno;
}

int usuario_setPopularidad(EUsuario* this,int popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->popularidad=popularidad;
        retorno=0;
    }
    return retorno;
}

int usuario_getPopularidad(EUsuario* this,int* popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *popularidad=this->popularidad;
        retorno=0;
    }
    return retorno;
}

