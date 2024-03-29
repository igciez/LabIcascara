#include "Service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

S_Service* Service_new()
{
    S_Service* this;
    this=malloc(sizeof(S_Service));
    return this;
}

void Service_delete(S_Service* this)
{
    free(this);
}

S_Service* Service_newConParametros(int id,char* name,char* email)
{
    S_Service* this;
    this=Service_new();

    if(
    !Service_setId(this,id)&&
    !Service_setName(this,name)&&
    !Service_setEmail(this,email))
        return this;

    Service_delete(this);
    return NULL;
}

int Service_setId(S_Service* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Service_getId(S_Service* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Service_setName(S_Service* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int Service_getName(S_Service* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

int Service_setEmail(S_Service* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int Service_getEmail(S_Service* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}

