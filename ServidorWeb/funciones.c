#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "parser.h"
#include "LogEntry.h"
#include "Service.h"

int procesarInformacion(ArrayList* pLog, ArrayList* pService){

    int i;
    int j;
    int auxGravedad;
    int auxServiceId;
    int auxServiceServiceId;
    char auxName[500];
    char auxDate[500];
    char auxTime[500];
    char auxMsg[500];
    char auxEmail[500];
    S_LogEntry* pAuxLog= NULL;
    S_Service* pAuxService= NULL;

    for(i=0;i<al_len(pLog);i++){
        pAuxLog=al_get(pLog,i);//<------------
        LogEntry_getGravedad(pAuxLog,&auxGravedad);

        if(auxGravedad > 2){

            if(auxGravedad == 3 || auxGravedad > 7 ){
                LogEntry_getServiceId(pAuxLog,&auxServiceId);

                if(auxServiceId != 45){
                    LogEntry_getDate(pAuxLog,auxDate);
                    LogEntry_getTime(pAuxLog,auxTime);
                    LogEntry_getMsg(pAuxLog,auxMsg);

                    for(j=0;j<al_len(pService);j++){
                        pAuxService=al_get(pService,j); //<------
                        Service_getId(pAuxService,&auxServiceServiceId);

                        if(auxServiceServiceId == auxServiceId){
                            Service_getName(pAuxService,auxName);
                            Service_getEmail(pAuxService,auxEmail);
                        }
                    }
                    parser_guardar("error.txt", auxTime,auxDate,auxName,auxMsg,auxEmail);
                }
            }
            else if(auxGravedad > 3 && auxGravedad<=7){
                for(j=0;j<al_len(pService);j++){
                    pAuxService=al_get(pService,j); //<------
                    Service_getId(pAuxService,&auxServiceServiceId);

                    if(auxServiceServiceId == auxServiceId){
                        Service_getName(pAuxService,auxName);
                    }
                }
                LogEntry_getDate(pAuxLog,auxDate);
                LogEntry_getTime(pAuxLog,auxTime);
                LogEntry_getMsg(pAuxLog,auxMsg);
                printf("\nFecha: %s\nHora: %s\nNombre del Servicio: %s\nMensaje de Error: %s\nGravedad: %d\n",auxTime,auxDate,auxName,auxMsg,auxGravedad);
            }
        }
    }
    return 0;
}
