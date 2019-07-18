#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "funciones.h"
#include "parser.h"

int main()
{
    ArrayList* pArrayEmpleados;
    ArrayList* pArrayMujeres;
    ArrayList* pArrayAux;
    pArrayEmpleados = al_newArrayList();
    char seguir='s';
    int opcion=0;
    int indice;
    int id;

    while(seguir=='s')
    {
        fflush(stdin);
        printf("1. Cargar datos desde data.csv\n");
        printf("2. Listar Clientes\n");
        printf("3. Ordenar por nombre y apellido\n");
        printf("4. Ordenar por mail\n");
        printf("5. Imprimir primeros n clientes\n");
        printf("6. Elimina un Cliente\n");
        printf("8. Guardar datos mujeres en mujeres.csv(modo texto)\n");
        printf("9. Guardar datos en data.csv (modo texto)\n");
        printf("10. Limpiar lista\n");
        printf("11.Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                parserEmployee("data.csv", pArrayEmpleados);
                break;
            case 2:
                imprimirClientes(pArrayEmpleados);
                break;
            case 3:
                al_sort(pArrayEmpleados, &cliente_compareNombreApellido, 1);
               break;
            case 4:
                al_sort(pArrayEmpleados, &cliente_compareMail, 1);
                break;
            case 5:
                printf("\nIngrese la cantidad a mostrar\n");
                scanf("%d", &indice);
                pArrayAux = al_subList(pArrayEmpleados,0,indice);
                imprimirClientes(pArrayAux);
                break;
            case 6:
                printf("\nINgrese id\n");
                scanf("%d", &id);
                if(!encontrarPersonaPorId(pArrayEmpleados, id, &indice))
                {
                    al_remove(pArrayEmpleados, indice);
                }
                break;
            case 8:
                pArrayMujeres = empleadosSoloMujeres(pArrayEmpleados);
                parser_guardar("mujeres.csv",pArrayMujeres);
                al_clear(pArrayMujeres);
                break;
            case 9:
                parser_guardar("data.csv",pArrayEmpleados);
                break;
            case 10:
                limpiarArray(pArrayEmpleados);
                pArrayEmpleados = al_newArrayList();
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
