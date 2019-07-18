#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "productoDep0.h"
#include "productoDep1.h"

int parserProducto(char* path , ArrayList* this)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    int retorno = -1;
    char bProducto[4096];
    char bDescripcion[4096];
    char bCantidad[4096];
    int producto;
    int cantidad;
    int contador=0;
    EProducto* auxiliarCliente;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bProducto,bDescripcion,bCantidad);
        retorno = 0;
       do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bProducto,bDescripcion,bCantidad)==3)
            {
                producto=atoi(bProducto);
                cantidad=atoi(bCantidad);
                auxiliarCliente = producto_newConParametros(producto,bDescripcion,cantidad);
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
