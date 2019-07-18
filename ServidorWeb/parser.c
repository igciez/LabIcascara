#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "LogEntry.h"
#include "Service.h"


int parserLogEntry(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char date[4000];
    char time[4000];
    char serviceId[4000];
    char gravedad[4000];
    char msg[4000];
    int auxServiceId;
    int auxGravedad;
    S_LogEntry* auxLogEntry;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
               date, time, serviceId, gravedad, msg);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
               date, time, serviceId, gravedad, msg);
            auxServiceId=atoi(serviceId);
            auxGravedad=atoi(gravedad);
            auxLogEntry = LogEntry_newConParametros(date,time,auxServiceId,auxGravedad,msg);
            al_add(pArrayListEmployee, auxLogEntry);
        }
        fclose(pFile);
    }
    return retorno;
}

int parserService(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char id[4000];
    char name[4000];
    char email[4000];
    int auxId;
    S_Service* auxService;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^;];%[^;];%[^\n]\n",
               id, name, email);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^;];%[^;];%[^\n]\n",
               id, name, email);
            auxId=atoi(id);
            auxService = Service_newConParametros(auxId,name,email);
            al_add(pArrayListEmployee, auxService);
        }
        fclose(pFile);
    }
    return retorno;
}


int parser_guardar(char* path ,char* auxTime,char* auxDate,char* auxName,char* auxMsg,char* auxEmail)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path, "a");
    if(pFile != NULL)
    {
        fprintf(pFile,"Fecha;Hora;Nombre servicio;Mensaje de error;E-mail soporte\n");
        fprintf(pFile, "%s;%s;%s;%s;%s\n", auxTime, auxDate, auxName, auxMsg, auxEmail);
        fclose(pFile);
        retorno=0;
    }
    return retorno;
}

