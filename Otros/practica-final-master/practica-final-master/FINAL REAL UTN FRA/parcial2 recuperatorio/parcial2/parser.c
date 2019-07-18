#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"

int parserECliente(char* path , ArrayList* this)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    int retorno = -1;
    char bId[4096];
    char bHsTrabajadas[4096];
    char bName[4096];
    EEmpleado* auxiliarCliente;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bName,bHsTrabajadas);
        retorno = 0;
       do
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bName,bHsTrabajadas);
            auxiliarCliente = Empleado_newParametros(bName,bId,bHsTrabajadas);
            al_add(this,auxiliarCliente);

        }while(!feof(pFile));
    }
    else
        printf("no se pudo encontrar el archivo");

    return retorno;
}
