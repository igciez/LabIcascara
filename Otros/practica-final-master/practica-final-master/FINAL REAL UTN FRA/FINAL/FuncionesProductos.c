#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "productoDep0.h"
#include "productoDep1.h"
#include "parser.h"
#include "utn.h"
#include "FuncionesProductos.h"
int productos_agregarStockDeDeposito(ArrayList*pListaDep0,ArrayList*pListaDep1)
{
    int retorno=-1;
    int codigoDeProducto;
    if(pListaDep0!=NULL && pListaDep1 !=NULL)
    {
        if(!utn_getValidInt("ingrese el codigo de producto.\n","ERROR, codigo de producto no valido\n",&codigoDeProducto,1,100,2))
        {
            if(productos_verificarExistenciaEnDeposito0yAgregar(pListaDep0,codigoDeProducto)==1)
            {
                if(productos_verificarExistenciaEnDeposito1yAgregar(pListaDep1,codigoDeProducto)==0)
                {
                    retorno=0;
                }
                else if(productos_verificarExistenciaEnDeposito1yAgregar(pListaDep1,codigoDeProducto)==1)
                {
                    printf("no existe el codigo de producto ingresado en ninguno de los depositos");
                }
            }
        }
    }
    return retorno;
}
int productos_agregarStock(ArrayList*pListaDep,int index)
{
    int cantidadParaAgregar;
    int cantidadActual;
    int retorno=-1;
    if(pListaDep!=NULL&&index>=0)
    {
        if(!utn_getValidInt("Cuantos Agregamos?.\n","ERROR, numero Invalido\n",&cantidadParaAgregar,1,10000,2))
        {
            producto_getCantidad(al_get(pListaDep,index),&cantidadActual);//obtengo la cantidad actual disponible
            if(!producto_setCantidad(al_get(pListaDep,index),cantidadActual+cantidadParaAgregar))//si se pudo setear printea y dice la cantidad actual
            {
                printf("Se Agrego El Stock.\n el stock Actual es: %d\n",cantidadActual+cantidadParaAgregar);
                retorno=0;
            }
        }

    }
    return retorno;
}
int productos_verificarExistenciaEnDeposito1yAgregar(ArrayList* pListaDep,int codigoDeProducto)
{
    int i;
    int retorno=-1;
    int auxCodigoProducto;
    if(pListaDep!=NULL&&codigoDeProducto>=0)
    {
        for(i=0; i<al_len(pListaDep); i++)
        {
            productoDep1_getProducto(al_get(pListaDep,i),&auxCodigoProducto);//obtengo el codigo del producto en la posicion i
            if(codigoDeProducto==auxCodigoProducto)//verifico
            {
                printf("esta el producto en deposito 2\n");
                productos_agregarStock(pListaDep,i);//Agrega el stock indicado por el usuario
                retorno=0;
                break;
            }
            else
                retorno=1;//no lo encontro
        }
    }
    return retorno;
}
int productos_verificarExistenciaEnDeposito0yAgregar(ArrayList* pListaDep,int codigoDeProducto)
{
    int i;
    int retorno=-1;
    int auxCodigoProducto;
    if(pListaDep!=NULL&& codigoDeProducto>=0)
    {
        for(i=0; i<al_len(pListaDep); i++)
        {
            producto_getProducto(al_get(pListaDep,i),&auxCodigoProducto);//obtengo el codigo del producto en la posicion i
            if(codigoDeProducto==auxCodigoProducto)//comparo
            {
                printf("esta el producto en deposito 1\n");
                productos_agregarStock(pListaDep,i);//descuenta el stock indicado por el usuario
                break;

            }
            else
                retorno=1;//no lo encontro
        }
    }
    return retorno;
}
int productos_descontarStockDeDoposito(ArrayList*pListaDep0,ArrayList*pListaDep1)
{
    int retorno=-1;
    int codigoDeProducto;
    if(pListaDep0!=NULL && pListaDep1 !=NULL)
    {
        if(!utn_getValidInt("ingrese el codigo de producto.\n","ERROR, codigo de producto no valido\n",&codigoDeProducto,1,100,2))
        {
            if(productos_verificarExistenciaEnDeposito0yDescontar(pListaDep0,codigoDeProducto)==1)
            {
                if(productos_verificarExistenciaEnDeposito1yDescontar(pListaDep1,codigoDeProducto)==0)
                {
                    retorno=0;
                }
                else if(productos_verificarExistenciaEnDeposito1yDescontar(pListaDep1,codigoDeProducto)==1)
                {
                    printf("no existe el codigo de producto ingresado en ninguno de los depositos");
                }
            }
        }
    }
    return retorno;
}
int productos_verificarExistenciaEnDeposito0yDescontar(ArrayList* pListaDep,int codigoDeProducto)
{
    int i;
    int retorno=-1;
    int auxCodigoProducto;
    if(pListaDep!=NULL&& codigoDeProducto>=0)
    {
        for(i=0; i<al_len(pListaDep); i++)
        {
            producto_getProducto(al_get(pListaDep,i),&auxCodigoProducto);//obtengo el codigo del producto en la posicion i
            if(codigoDeProducto==auxCodigoProducto)//comparo
            {
                printf("esta el producto en deposito 1\n");
                productos_descontarStock(pListaDep,i);//descuenta el stock indicado por el usuario
                break;

            }
            else
                retorno=1;//no lo encontro
        }
    }
    return retorno;
}
int productos_descontarStock(ArrayList*pListaDep,int index)
{
    int cantidadADescontar;
    int cantidadActual;
    int retorno=-1;
    if(pListaDep!=NULL&&index>=0)
    {
        if(!utn_getValidInt("Cuantos Descontamos?.\n","ERROR, numero Invalido\n",&cantidadADescontar,1,10000,2))
        {
            producto_getCantidad(al_get(pListaDep,index),&cantidadActual);//obtengo la cantidad actual disponible
            if(cantidadActual>=cantidadADescontar)
            {
                if(!producto_setCantidad(al_get(pListaDep,index),cantidadActual-cantidadADescontar))//si se pudo setear printea y dice la cantidad actual
                {
                    printf("Se Desconto El Stock.\n el stock Actual es: %d\n",cantidadActual-cantidadADescontar);
                    retorno=0;
                }
            }
            else
                printf("no se puede descontar un numero mayor al stock Actual que es: %d\n",cantidadActual);//printea la cantidad disponible
        }

    }
    return retorno;
}
int productos_verificarExistenciaEnDeposito1yDescontar(ArrayList* pListaDep,int codigoDeProducto)
{
    int i;
    int retorno=-1;
    int auxCodigoProducto;
    if(pListaDep!=NULL&&codigoDeProducto>=0)
    {
        for(i=0; i<al_len(pListaDep); i++)
        {
            productoDep1_getProducto(al_get(pListaDep,i),&auxCodigoProducto);//obtengo el codigo del producto en la posicion i
            if(codigoDeProducto==auxCodigoProducto)//verifico
            {
                printf("esta el producto en deposito 2\n");
                productos_descontarStock(pListaDep,i);//descuenta el stock indicado por el usuario
                break;
            }
            else
                retorno=1;//no lo encontro
        }
    }
    return retorno;
}


int productos_cambiarDeDepositoUnProducto(ArrayList* pListaDep0,ArrayList* pListaDep1)
{
    int retorno=-1;
    int numDeDepositoOrigen;
    int numDeDepositoDestino;
    if(pListaDep0!=NULL && pListaDep1!= NULL)
    {
        if(!utn_getValidInt("ingrese el numero del deposito de ORIGEN\n","ERROR, deposito no Valido. solo hay deposito 1 y 2\n",&numDeDepositoOrigen,1,2,2))
        {
            if(!utn_getValidInt("ingrese el numero del deposito de DESTINO\n","ERROR, deposito no Valido. solo hay deposito 1 y 2\n",&numDeDepositoDestino,1,2,2))
            {
                if(numDeDepositoOrigen==numDeDepositoDestino)
                {
                    printf("no puede seleccionar el mismo deposito como ORIGEN y DESTINO");
                }
                //del deposito 1 al deposito 2.
                else if(numDeDepositoOrigen==1)
                {
                    if(!productos_pasarDeDep0AlDep1(pListaDep0,pListaDep1))
                        retorno=0;
                }
                //del deposito 2 al deposito 1.
                else if(numDeDepositoOrigen==2)
                {
                    if(!productos_pasarDeDep1AlDep0(pListaDep0,pListaDep1))
                        retorno=0;
                }
            }
        }
    }
    return retorno;

}

int productos_pasarDeDep0AlDep1(ArrayList* pListaDep0,ArrayList* pListaDep1)
{
    int retorno=-1;
    int codigoDeProducto;
    int i;
    int auxProducto;
    if(pListaDep0!=NULL && pListaDep1!= NULL)
    {
        utn_getValidInt("ingrese el codigo de producto que desea mover.\n","ERROR, codigo de producto no valido\n",&codigoDeProducto,1,100,2);

        for(i=0; i<al_len(pListaDep0); i++)
        {
            producto_getProducto(al_get(pListaDep0,i),&auxProducto);
            if(auxProducto==codigoDeProducto)//cambiar
            {
                if(al_add(pListaDep1,al_pop(pListaDep0,i))==0)
                {
                    printf("Se paso de deposito del Deposito 1 al Deposito 2\n");
                    retorno=0;
                }
                break;
            }
        }
        if(auxProducto!=codigoDeProducto)
        {
            printf("el codigo de producto no se encontro\n");
        }
    }
    return retorno;
}
int productos_pasarDeDep1AlDep0(ArrayList* pListaDep0,ArrayList* pListaDep1)
{
    int retorno=-1;
    int codigoDeProducto;
    int i;
    int auxProducto;
    if(pListaDep0!=NULL && pListaDep1!= NULL)
    {
        utn_getValidInt("ingrese el codigo de producto que desea mover.\n","ERROR, codigo de producto no valido\n",&codigoDeProducto,1,100,2);

        for(i=0; i<al_len(pListaDep1); i++)
        {
            productoDep1_getProducto(al_get(pListaDep1,i),&auxProducto);
            if(auxProducto==codigoDeProducto)
            {
                if(al_add(pListaDep0,al_pop(pListaDep1,i))==0)//agrego en deposito 0 el elemento y lo elimino del deposito 1
                {
                    printf("Se paso de deposito del Deposito 2 al Deposito 1\n");
                    retorno=0;
                }
                break;
            }
        }
        if(auxProducto!=codigoDeProducto)
        {
            printf("el codigo de producto no se encontro\n");
        }
    }
    return retorno;
}
int productos_imprimirProductos(void* item)
{
    int producto;
    int cantidad;
    char descripcion[250];
    int retorno=-1;
    if(item!=NULL)
    {
        productoDep1_getProducto(item,&producto);
        productoDep1_getDescripcion(item,descripcion);
        productoDep1_getCantidad(item,&cantidad);

        printf("-------------------------\n");
        printf("Producto: %d\n",producto);
        printf("Descripcion: %s\n",descripcion);
        printf("Cantidad: %d\n",cantidad);
    }
    return retorno;
}
