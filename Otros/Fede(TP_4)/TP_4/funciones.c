#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "funciones.h"
#include "parser.h"

/** \brief Devuelve un array con personas del sexo femenino
 * \param pArray lista original
 * \return
 *
 */
ArrayList* empleadosSoloMujeres(ArrayList* pArray)
{
    int i;
    int indice;
    char generoAux;
    ArrayList* arrayMujeres=NULL;
    Cliente* clienteAux;
    arrayMujeres = al_clone(pArray);
    if(arrayMujeres!=NULL)
    {
        for(i=0;i<al_len(pArray);i++)
        {
            clienteAux = al_get(pArray,i);
            cliente_getGenero(clienteAux, &generoAux);
            if(generoAux!='F')
            {
                indice = al_indexOf(arrayMujeres, clienteAux);
                al_remove(arrayMujeres, indice);
            }
        }
    }
    return arrayMujeres;
}

/** \brief  Busca una persona por id
 * \param pArray ArrayList*, id de la persona a buscar, indice donde devuelve
 * \return 0[OK] -1[ERROR]
 *
 */
int encontrarPersonaPorId(ArrayList* pArray, int id, int* indice)
{
    int i;
    int retorno=-1;
    int auxId;
    Cliente* clienteAux;
    if(pArray!=NULL)
    {
        for(i=0;i<al_len(pArray);i++)
        {
            clienteAux = al_get(pArray, i);
            cliente_getId(clienteAux, &auxId);
            if(auxId==id)
            {
                *indice=i;
                retorno =0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief  Imprime por pantalla los clientes en el array
 * \param
 * \return
 *
 */
void imprimirClientes(ArrayList* pArray)
{
    int i;
    for(i=0; i < al_len(pArray); i++)
    {
        cliente_print(al_get(pArray, i));
    }
}

/** \brief Realiza un delete de todos los elementos y del array
 * \param
 * \return
 *
 */
void limpiarArray(ArrayList* pArray)
{
    Cliente* auxCliente;
    while(al_len(pArray)>0)
    {
        auxCliente = al_pop(pArray,0);
        cliente_delete(auxCliente);
    }
    al_deleteArrayList(pArray);
}
