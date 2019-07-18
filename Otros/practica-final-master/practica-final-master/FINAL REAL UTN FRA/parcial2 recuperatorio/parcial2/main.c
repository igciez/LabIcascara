#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "utn.h"
#include "parser.h"



int main()
{
    // Definir lista de empleados
    ArrayList* listaEmpleados;
    ArrayList* pListaEmpleadosClone;

    pListaEmpleadosClone=al_newArrayList();
    listaEmpleados=al_newArrayList();

    // Leer empleados de archivo data.csv
    if(parserECliente("data.csv",listaEmpleados)==0)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        if(al_map(listaEmpleados,Empleado_calcularSueldo)==0)
        {
            //imprimir sueldos
            al_filter(listaEmpleados,pListaEmpleadosClone,Empleado_sueldoMayorA);
            imprimirDatos(pListaEmpleadosClone);
        }
        // Generar archivo de salida
        if(generarArchivoSueldos("datos Calculados.csv",pListaEmpleadosClone)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");

    return 0;
}
int al_filter(ArrayList* this,ArrayList* this2,int(*pFunc)(void*))
 {
    int retorno=-1;
    int i;
    if(this!=NULL&& this2!=NULL&& pFunc!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            if(pFunc(this->pElements[i])==0)
            {
                al_add(this2,this->pElements[i]);
                retorno=0;
            }
        }

    }
    return retorno;
 }


