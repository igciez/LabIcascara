#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        case 1://PARSEAR
            parserProducto("dep0.CSV",pListaProductosDep0);//parsea el deposito 0
            parserProducto("dep1.CSV",pListaProductosDep1);//parsea el deposito 1
            break;
        case 2://PRINTEAR
            utn_getValidInt("ingrese el numero del deposito\n","ERROR, deposito no Valido. solo hay deposito 1 y 2\n",&numDeDeposito,1,2,2);
            if(numDeDeposito==1)
            {
                al_map(pListaProductosDep0,productos_imprimirProductos);//imprime los datos del dep 0
            }
            else if(numDeDeposito==2)
            {
                al_map(pListaProductosDep1,productos_imprimirProductos);//imprime los datos del dep 1
            }
            break;
        case 3://MOVER DE DEPOSITO
            if(productos_cambiarDeDepositoUnProducto(pListaProductosDep0,pListaProductosDep1)==0)
            {
                al_sort(pListaProductosDep0,productos_compareName,1);
                productos_cargarDatosAlArchivo("dep0.CSV",pListaProductosDep0);
                productos_cargarDatosAlArchivo("dep1.CSV",pListaProductosDep1);
                printf("los archivos generados se guardan en una carpeta llamada 'files'\nLos originales permanecen en su lugar sin cambios.");
            }
            break;
        case 4://VERIFICAR Y DESCONTAR STOCK
            if(productos_descontarStockDeDoposito(pListaProductosDep0,pListaProductosDep1)==0)
            {
                al_sort(pListaProductosDep0,productos_compareName,1);
                al_sort(pListaProductosDep1,productos_compareName,1);
                productos_cargarDatosAlArchivo("dep0.CSV",pListaProductosDep0);
                productos_cargarDatosAlArchivo("dep1.CSV",pListaProductosDep1);
                printf("los archivos generados se guardan en una carpeta llamada 'files'\nLos originales permanecen en su lugar sin cambios.");
            }
            break;
        case 5:// VERIFICAR Y AGREGAR STOCK
            if(productos_agregarStockDeDeposito(pListaProductosDep0,pListaProductosDep1)==0)
            {
                al_sort(pListaProductosDep0,productos_compareName,1);
                al_sort(pListaProductosDep1,productos_compareName,1);
                productos_cargarDatosAlArchivo("dep0.CSV",pListaProductosDep0);
                productos_cargarDatosAlArchivo("dep1.CSV",pListaProductosDep1);
                printf("los archivos generados se guardan en una carpeta llamada 'files'\nLos originales permanecen en su lugar sin cambios.\n");
            }
            break;
        case 6://LEER ARCHIVOS GENERADOS DENTRO DE LA CARPETA FILE
            parserProducto("files//dep0.CSV",pListaProductosDep0);//parsea el deposito 0
            parserProducto("files//dep1.CSV",pListaProductosDep1);//parsea el deposito 1
            al_sort(pListaProductosDep0,productos_compareName,1);
            al_sort(pListaProductosDep1,productos_compareName,1);

            break;
        }
        system("pause");
        system("cls");
    }
    while(menu!=7);
    return 0;
}
