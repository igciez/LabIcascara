#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EEmpleado* Empleado_new()
{
    EEmpleado* this;
    this=malloc(sizeof(EEmpleado));
    return this;
}

void Empleado_delete(EEmpleado* this)
{
    free(this);
}

int Empleado_setId(EEmpleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(EEmpleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(EEmpleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL&&utn_isValidName(nombre)==0)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(EEmpleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(EEmpleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL&&horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(EEmpleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(EEmpleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL&&sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(EEmpleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}




EEmpleado* Empleado_newParametros(char *strName,char* strId,char*strHsTrabajadas)
{
    EEmpleado* this;
    this = Empleado_new();
    int id;
    float hsTrabajadas;
    id=atoi(strId);
    hsTrabajadas=atoi(strHsTrabajadas);

    if( !Empleado_setId(this,id) &&
        !Empleado_setNombre(this,strName)&&
        !Empleado_setHorasTrabajadas(this,hsTrabajadas))
    {

        return this;
    }
    Empleado_delete(this);
    return NULL;
}
int imprimirDatos(ArrayList* this)
{
    int i;
    int retorno=-1;
    char auxName[50];
    int auxId;
    int auxHsTrabajadas;
    int auxSueldo;
    if(this!=NULL)
    {
        retorno=0;
        for(i=0; i<al_len(this)-800; i++)
        {
            Empleado_getNombre(al_get(this,i),auxName);
            Empleado_getId(al_get(this,i),&auxId);
            Empleado_getHorasTrabajadas(al_get(this,i),&auxHsTrabajadas);
            Empleado_getSueldo(al_get(this,i),&auxSueldo);

            printf("ID: %d  ",auxId);
            printf("Name: %s    ",auxName);
            printf("HsTrabajadas: %d    ",auxHsTrabajadas);
            printf("Sueldo : %d\n",auxSueldo);
        }
    }
    return retorno;
}

/*- Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/
int Empleado_calcularSueldo(void* item)
{
    int retorno=-1;
    int hsTrabajadas;
    int auxSueldo;
    int aux120hsTrabjadas=21600;
    int aux160hsTrabjadas=31200;
    if(item!=NULL)
    {

        if(Empleado_getHorasTrabajadas(item,&hsTrabajadas)==0)
        {

            if(hsTrabajadas<=120)
            {
                auxSueldo=hsTrabajadas*180;
            }
            else  if(hsTrabajadas>120&&hsTrabajadas<=160)
            {
                hsTrabajadas=hsTrabajadas-120;//le resto las 120hs de $180
                auxSueldo=hsTrabajadas*240;//a la cantidad de hs actual las multiplico por el pago/hs
                auxSueldo=auxSueldo+aux120hsTrabjadas;//al sueldo le sumo las 120hs trabajadas.
            }
            else  if(hsTrabajadas>160&&hsTrabajadas<=240)
            {
                hsTrabajadas=hsTrabajadas-160;//le resto las 120hs de $180
                auxSueldo=hsTrabajadas*350;//a la cantidad de hs actual las multiplico por el pago/hs
                auxSueldo=auxSueldo+aux160hsTrabjadas;//al sueldo le sumo las 120hs trabajadas.
            }
            retorno=0;
            Empleado_setSueldo(item,auxSueldo);
            //printf("Calcular Sueldo %d\n",auxSueldo);

        }

    }
    return retorno;
}
int generarArchivoSueldos(char* fileName,ArrayList* this)
{
    FILE* pFile;
    EEmpleado* AuxEmpleado;
    int i;

    int auxId;
    int auxHs;
    int auxSueldo;
    char auxName[50];

    if(fileName!=NULL && this!=NULL)
    {
        pFile=fopen(fileName,"w");
        if(pFile!=NULL)
        {
            for(i=0; i<al_len(this); i++)
            {
                AuxEmpleado=al_get(this,i);
                Empleado_getId(AuxEmpleado,&auxId);
                Empleado_getHorasTrabajadas(AuxEmpleado,&auxHs);
                Empleado_getNombre(AuxEmpleado,auxName);
                Empleado_getSueldo(AuxEmpleado,&auxSueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxName,auxHs,auxSueldo);
            }

        }
        fclose(pFile);

    }


    return 1;
}
int Empleado_sueldoMayorA(void* item)
{
    int retorno=-1;
    int sueldo;
    EEmpleado* aux=item;
    if(item!=NULL)
    {
        sueldo=aux->sueldo;
        if(sueldo>25000)
        {
            //printf("%d\n",sueldo);
            retorno=0;
        }
        else
        retorno=1;
    }

 return retorno;
}
