#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "reparto.h"

int parserReparto(char* path , ArrayList* this)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    int retorno = -1;
    char bId[4096];
    char bProducto[4096];
    char bDireccion[4096];
    char bLocalidad[4096];
    char bRecibe[4096];
    int id;
    int contador=0;
    EReparto* auxiliarCliente;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bId,bProducto,bDireccion,bLocalidad,bRecibe);
        retorno = 0;
       do
        {   //                                      id,producto,direccion,localidad,recibe
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bId,bProducto,bDireccion,bLocalidad,bRecibe)==5)
            {
                id=atoi(bId);
                auxiliarCliente = reparto_newConParametros(id,bProducto,bDireccion,bLocalidad,bRecibe);
                al_add(this,auxiliarCliente);
                contador++;
            }
            else
                printf("error al leer los datos en el parser");

        }while(!feof(pFile));
        printf("cantidad de datos leidos %d\n",contador);
    }
    else
        printf("no se pudo encontrar el archivo");

    return retorno;
}
