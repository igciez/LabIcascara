#include "reparto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EReparto* reparto_new()
{
    EReparto* this;
    this=malloc(sizeof(EReparto));
    return this;
}

void reparto_delete(EReparto* this)
{
    free(this);
}

EReparto* reparto_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe)
{
    EReparto* this;
    this=reparto_new();

    if(
    !reparto_setId(this,id)&&
    !reparto_setProducto(this,producto)&&
    !reparto_setDireccion(this,direccion)&&
    !reparto_setLocalidad(this,localidad)&&
    !reparto_setRecibe(this,recibe))
        return this;

    reparto_delete(this);
    return NULL;
}

int reparto_setId(EReparto* this,int id)
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

int reparto_getId(EReparto* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int reparto_setProducto(EReparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int reparto_getProducto(EReparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int reparto_setDireccion(EReparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_getDireccion(EReparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_setLocalidad(EReparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_getLocalidad(EReparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_setRecibe(EReparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int reparto_getRecibe(EReparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}



int reparto_agregarAlArraylistDeLocalidades(ArrayList* this,char* localidadIngresada,ArrayList*arrayListLocalidades)
{
    int i;
    char localidad[250];
    int retorno=-1;
    int contador=0;
    if(this!=NULL && arrayListLocalidades!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            reparto_getLocalidad(al_get(this,i),localidad);
            if(strcmp(localidadIngresada,localidad)==0)
            {
                al_add(arrayListLocalidades,al_get(this,i));
                contador++;
            }
        retorno=0;
        }
        printf("\nse agregaron %d entregas de %s\n",contador,localidadIngresada);
        printf("---------------------------------------\n");
    }
    return retorno;
}
int reparto_cargarDatosAlArchivo(char *name,ArrayList* this)
{
    char buffer[100]="files//";
    int retorno=-1;
    int i;
    int contadorCargados=0;
    int id;
    char producto[250];
    char direccion[250];
    char localidad[250];
    char recibe[250];
    EReparto *auxElement;
    if(name!=NULL && this !=NULL)
    {
        strcat(buffer,name);
        FILE* pFile;
        pFile=fopen(buffer,"w");

        if(pFile!=NULL)
        {
            fprintf(pFile,"%s,%s,%s,%s,%s\n","id","producto","direccion","localidad","recibe");
            for(i=0; i<al_len(this); i++)
            {
                auxElement=al_get(this,i);
                if(auxElement!=NULL)
                {
                    reparto_getId(auxElement,&id);
                    reparto_getProducto(auxElement,producto);
                    reparto_getDireccion(auxElement,direccion);
                    reparto_getLocalidad(auxElement,localidad);
                    reparto_getRecibe(auxElement,recibe);
                    fprintf(pFile,"%d,%s,%s,%s,%s\n",id,producto,direccion,localidad,recibe);
                    contadorCargados++;
                }

            }
            retorno=0;
            printf("Cantidad De Cargados al archivo %s: %d\n",name,contadorCargados);
            printf("el archivo se guardo en una carpeta creada Llamada 'FILES'.\nEl original permanece sin cambios\n");
        }
        else
        {
            printf("No se pudo crear el archivo");
        }

        fclose(pFile);
    }
    return retorno;
}
int  reparto_separarLocalidadesRepetidas(ArrayList* this,ArrayList* this2)
{
    int i;
    int retorno=-1;
    if(this!=NULL)
    {
        retorno=0;
        for(i=0; i<al_len(this)-1; i++)//imprime lista por pantalla
        {
            EReparto* auxiliar=al_get(this,i);
            EReparto* auxiliar2=al_get(this,i+1);
            if((strcmp(auxiliar->localidad,auxiliar2->localidad)!=0))
            {
                printf("%s\n",auxiliar->localidad);
                al_add(this2,auxiliar);
            }
        }

    }
    return retorno;
}
int reparto_compareLocalidad(void* pClienteA,void* pClienteB)
{
    EReparto* repartoA=(EReparto*)pClienteA;
    EReparto* repartoB=(EReparto*)pClienteB;
    char localidadRepartoA[51];
    char localidadRepartoB[51];
    int retorno = 0;
    if(repartoA!=NULL && repartoB != NULL)
    {
        reparto_getLocalidad(repartoA,localidadRepartoA);
        reparto_getLocalidad(repartoB,localidadRepartoB);
        retorno = strcmp(localidadRepartoA,localidadRepartoB);
        if(retorno>0)
        {
            retorno=-1;
        }
        else if(retorno<0)
        {
            retorno=1;
        }
    }
    return retorno ;

}
int reparto_imprimirRepartos(void* item)
{

    int retorno=-1;
    int id;
    char producto[250];
    char direccion[250];
    char localidad[250];
    char recibe[250];

    if(item!=NULL)
    {
        if(!reparto_getId(item,&id)&&
                !reparto_getProducto(item,producto)&&
                !reparto_getDireccion(item,direccion)&&
                !reparto_getLocalidad(item,localidad)&&
                !reparto_getRecibe(item,recibe))
        {
            printf("-------------------------\n");
            printf("id: %d\n",id);
            printf("producto: %s\n",producto);
            printf("direccion: %s\n",direccion);
            printf("localidad: %s\n",localidad);
            printf("recibe: %s\n",recibe);
            retorno=0;
        }


    }
    return retorno;
}
