#include "localidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ELocalidades* localidades_new()
{
    ELocalidades* this;
    this=malloc(sizeof(ELocalidades));
    return this;
}

void localidades_delete(ELocalidades* this)
{
    free(this);
}

ELocalidades* localidades_newConParametros(char* localidad)
{
    ELocalidades* this;
    this=localidades_new();

    if(
    !localidades_setLocalidad(this,localidad))
        return this;

    localidades_delete(this);
    return NULL;
}

int localidades_setLocalidad(ELocalidades* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int localidades_getLocalidad(ELocalidades* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

