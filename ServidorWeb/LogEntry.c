#include "LogEntry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

S_LogEntry* LogEntry_new()
{
    S_LogEntry* this;
    this=malloc(sizeof(S_LogEntry));
    return this;
}

void LogEntry_delete(S_LogEntry* this)
{
    free(this);
}

S_LogEntry* LogEntry_newConParametros(char* date,char* time,int serviceId,int gravedad,char* msg)
{
    S_LogEntry* this;
    this=LogEntry_new();

    if(
    !LogEntry_setDate(this,date)&&
    !LogEntry_setTime(this,time)&&
    !LogEntry_setServiceId(this,serviceId)&&
    !LogEntry_setGravedad(this,gravedad)&&
    !LogEntry_setMsg(this,msg))
        return this;

    LogEntry_delete(this);
    return NULL;
}

int LogEntry_setDate(S_LogEntry* this,char* date)
{
    int retorno=-1;
    if(this!=NULL && date!=NULL)
    {
        strcpy(this->date,date);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getDate(S_LogEntry* this,char* date)
{
    int retorno=-1;
    if(this!=NULL && date!=NULL)
    {
        strcpy(date,this->date);
        retorno=0;
    }
    return retorno;
}

int LogEntry_setTime(S_LogEntry* this,char* time)
{
    int retorno=-1;
    if(this!=NULL && time!=NULL)
    {
        strcpy(this->time,time);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getTime(S_LogEntry* this,char* time)
{
    int retorno=-1;
    if(this!=NULL && time!=NULL)
    {
        strcpy(time,this->time);
        retorno=0;
    }
    return retorno;
}

int LogEntry_setServiceId(S_LogEntry* this,int serviceId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->serviceId=serviceId;
        retorno=0;
    }
    return retorno;
}

int LogEntry_getServiceId(S_LogEntry* this,int* serviceId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *serviceId=this->serviceId;
        retorno=0;
    }
    return retorno;
}

int LogEntry_setGravedad(S_LogEntry* this,int gravedad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->gravedad=gravedad;
        retorno=0;
    }
    return retorno;
}

int LogEntry_getGravedad(S_LogEntry* this,int* gravedad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *gravedad=this->gravedad;
        retorno=0;
    }
    return retorno;
}

int LogEntry_setMsg(S_LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(this->msg,msg);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getMsg(S_LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(msg,this->msg);
        retorno=0;
    }
    return retorno;
}

