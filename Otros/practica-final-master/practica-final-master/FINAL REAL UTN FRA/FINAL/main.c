#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "productoDep0.h"
#include "productoDep1.h"
#include "parser.h"
#include "utn.h"
#include "FuncionesProductos.h"
/***
* 1- Cargar depositos: Se deberan leer ambos archiuos y generar dos Arraylist con los datos.
* 2- Listar productos de deposito: Se le pedira al usuario el numero de deposito (1 o 2) y se imprimira la lista de productos en dicho deposito.
* 3- Mover productos a deposito: Se le pedira al usuario que ingrese el numero de deposito origen y luego el numero de deposito destino. Luego se le pedira al usuario que ingrese el
* codigo del producto a mover(debera existir en el deposito origen). Los productos deberan borrarse del deposito origen y agregarse al deposito destino.
* (Esta operacion se hace sobre la cantidad total de los productos, no puede quedar el mismo codigo de producto en ambos depositos).
* 4- Descontar productos de deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Se le pedira al usuario que ingrese
* la cantidad de productos a descontar y dicha cantidad se restara a la cantidad actual de productos de ese tipo en el deposito correspondiente,
* si es que existe esa cantidad disponible.
* 5- Agregar productos a deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Luego se le pedira al usuario que ingrese
* la camntidad de productos a sumar y dicha cantidad se sumara a la cantidad actual de productos de ese tipo en el deposito correspondiente.
* 6- Salir.
*
* NOTA: Cada vez que se haga una modificacion sobre un deposito, la misma se debe reflejarse en el archivo csv correspondiente a dicho deposito
* El cambio no puede realizarse solo en el ArrayList.
***/
int actualizarArchivos();
int main()
{
    ArrayList* pListaProductosDep0= al_newArrayList();
    ArrayList* pListaProductosDep1= al_newArrayList();
    int menu;
    int numDeDeposito;

    do
    {
        menu=utn_menuDeOpciones();
        switch(menu)
        {
        case 1:
            parserProducto("dep0.CSV",pListaProductosDep0);
            parserProducto("dep1.CSV",pListaProductosDep1);
            break;
        case 2:
            utn_getValidInt("ingrese el numero del deposito\n","ERROR, deposito no Valido. solo hay deposito 1 y 2\n",&numDeDeposito,1,2,2);
            if(numDeDeposito==1)
            {
                al_map(pListaProductosDep0,productos_imprimirProductos);
            }
            else if(numDeDeposito==2)
            {
                al_map(pListaProductosDep1,productos_imprimirProductos);
            }
            break;
        case 3:
            productos_cambiarDeDepositoUnProducto(pListaProductosDep0,pListaProductosDep1);
            break;
        case 4:
            productos_descontarStockDeDoposito(pListaProductosDep0,pListaProductosDep1);
            break;
        case 5:
            productos_agregarStockDeDeposito(pListaProductosDep0,pListaProductosDep1);
            break;
        }

    }
    while(menu!=6);
    return 0;
}

int actualizarArchivos(ArrayList* pListaDep0,ArrayList* pListaDep1)
{
    FILE* pFile;
    int i;
    pFile=fopen("dep1.CSV","w");
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(pListaDep0);i++)
        {
            fwrite(pListaDep0[i]->pElements,sizeof(EProducto),1,pFile);
        }
    }
    return 0;
}
