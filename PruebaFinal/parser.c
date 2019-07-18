#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parser.h"
#include "depositoI.h"
#include "depositoII.h"


int parserDepositoI(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char producto[4000];
    char descripcion[4000];
    char cantidad[4000];
    int auxProducto;
    int auxCantidad;

    eDepositoI* auxDepositoI;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n",producto, descripcion, cantidad);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n",producto, descripcion, cantidad);
            auxProducto=atoi(producto);
            auxCantidad=atoi(cantidad);
            auxDepositoI = depositoI_newConParametros(auxProducto, descripcion, auxCantidad);
            al_add(pArrayListEmployee, auxDepositoI);
        }
        fclose(pFile);
    }
    return retorno;
}

int parserDepositoII(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char producto[4000];
    char descripcion[4000];
    char cantidad[4000];
    int auxProducto;
    int auxCantidad;

    eDepositoII* auxDepositoII;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n",producto, descripcion, cantidad);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n",producto, descripcion, cantidad);
            auxProducto=atoi(producto);
            auxCantidad=atoi(cantidad);
            auxDepositoII = depositoII_newConParametros(auxProducto, descripcion, auxCantidad);
            al_add(pArrayListEmployee, auxDepositoII);
        }
        fclose(pFile);
    }
    return retorno;
}
/*
int parser_guardar(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    int id;
    char nombre[4000];
    char apellido[4000];
    char email[4000];
    char genero;
    char profesion[4000];
    char usuario[4000];
    char nacionalidad[4000];

    Cliente* this;
    int i;
    FILE* pFile;
    pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,apellido,email,genero,profesion,usuario,nacionalidad\n");
        for(i=0; i<al_len(pArrayListEmployee);i++)
        {
            retorno = 0;
            this = al_get(pArrayListEmployee, i);
            cliente_getId(this,&id);
            cliente_getNombre(this,nombre);
            cliente_getApellido(this,apellido);
            cliente_getEmail(this,email);
            cliente_getGenero(this, &genero);
            cliente_getProfesion(this, profesion);
            cliente_getUsuario(this, usuario);
            cliente_getNacionalidad(this, nacionalidad);
            fprintf(pFile, "%d,%s,%s,%s,%c,%s,%s,%s\n", id, nombre, apellido, email, genero, profesion, usuario, nacionalidad);
        }
        fclose(pFile);
    }
    return retorno;
}
*/
