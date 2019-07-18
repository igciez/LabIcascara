#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "depositoI.h"
#include "depositoII.h"
#include "utn.h"


void imprimirDepositos (ArrayList* pDepositoI,ArrayList* pDepositoII){

    if(pDepositoI != NULL && pDepositoII !=NULL){
        int deposito;

        printf("\nPara Deposito I: ingrese 1 \n");
        printf("\nPara Deposito II: ingrese 2 \n");
        scanf("%d",&deposito);

        switch(deposito){
            case 1:
                printf("-----Deposito 1-------");
                al_map(pDepositoI,imprimeDepositoI);
                break;
            case 2:
                printf("-----Deposito 2-------");
                al_map(pDepositoII,imprimeDepositoII);
                break;
            default:
                printf("\n!Dato ingresado invalido, reintente!\n");
        }
    }
}

int imprimeDepositoI (void* this){

        int producto;
        char descripcion[500];
        int cantidad;

        depositoI_getProducto(this, &producto);
        depositoI_getDescripcion(this,descripcion);
        depositoI_getCantidad(this, &cantidad);

        printf("\nProducto numero: %d \n", producto);
        printf("Descripcion del Producto: %s \n", descripcion );
        printf("Cantidad disponible: %d \n", cantidad  );
    return 0;
}

int imprimeDepositoII (void* this){

        int producto;
        char descripcion[500];
        int cantidad;

        depositoII_getProducto(this, &producto);
        depositoII_getDescripcion(this,descripcion);
        depositoII_getCantidad(this, &cantidad);

        printf("\n--------Depositos--------\n");
        printf("Producto numero: %d \n", producto);
        printf("Descripcion del Producto: %s \n", descripcion );
        printf("Cantidad disponible: %d \n", cantidad  );
    return 0;
}

int moverProductosAdeposito(ArrayList* pDepositoI,ArrayList* pDepositoII){

    int numeroDepOrigen;
    int numeroDepDestino;
    int codigoProducto;
    int auxProducto;

    utn_getValidInt("\nIngrese el numero de Deposito Origen: ","Error debe ingresar 1 o 2", &numeroDepOrigen,1, 2,2);
    utn_getValidInt("\nIngrese el numero de Deposito Destino: ","Error debe ingresar 1 o 2", &numeroDepDestino,1, 2,2);

    if(numeroDepOrigen != numeroDepDestino){

        if(numeroDepOrigen == 1){

            printf("Ingrese el codigo del Producto a mover: ");
            scanf("%d", &codigoProducto);

             for(int i=0;i<al_len(pDepositoI);i++){

                depositoI_getProducto(al_get(pDepositoI,i),&auxProducto);

                if(auxProducto == codigoProducto){

                    if(al_add(pDepositoII,al_pop(pDepositoI,i)) == 0){
                        printf("Se logro pasar\n");
                    }
                }
            }
        }
        else{
            printf("Ingrese el codigo del Producto a mover: ");
            scanf("%d", &codigoProducto);

             for(int i=0;i<al_len(pDepositoII);i++){

                depositoII_getProducto(al_get(pDepositoII,i),&auxProducto);

                if(auxProducto == codigoProducto){

                    if(al_add(pDepositoI,al_pop(pDepositoII,i)) == 0){
                        printf("Se logro pasar\n");
                    }
                }
            }
        }
    }
    return 0;
}

int descontarProductoDeDeposito(ArrayList* pDepositoI,ArrayList* pDepositoII){

    int auxProducto;
    int codigoProducto;
    int cantidadIngresada;
    int cantidadObtenidad;
    int resultadoCantidad;

    printf("\nIngrese el numero de producto a descontar: ");
    scanf("%d", &codigoProducto);

    for(int i=0; i< al_len(pDepositoI); i++){

        depositoI_getProducto(al_get(pDepositoI,i),&auxProducto);

        if(auxProducto == codigoProducto){
            printf("\nIngrese la cantidad de Productos a Descontar: ");
            scanf("%d",&cantidadIngresada);

            if(!(depositoI_getCantidad(al_get(pDepositoI,i),&cantidadObtenidad))){

               resultadoCantidad=cantidadObtenidad-cantidadIngresada;

               if(resultadoCantidad >= 0){
                    depositoI_setCantidad(al_get(pDepositoI,i), resultadoCantidad);
               }
               else{
                printf("\nLa cantidad Ingresada supera a la cantidad actual en deposito. Reintente!");
               }
            }
        }else{

            depositoII_getProducto(al_get(pDepositoII,i),&auxProducto);

            for(int i=0; i< al_len(pDepositoII); i++){

                if(auxProducto == codigoProducto){
                    printf("\nIngrese la cantidad de Productos a Descontar: ");
                    scanf("%d",&cantidadIngresada);

                    if(!(depositoII_getCantidad(al_get(pDepositoII,i),&cantidadObtenidad))){

                       resultadoCantidad=cantidadObtenidad-cantidadIngresada;

                       if(resultadoCantidad >= 0){
                            depositoII_setCantidad(al_get(pDepositoII,i), resultadoCantidad);
                       }
                       else{
                        printf("\nLa cantidad Ingresada supera a la cantidad actual en deposito. Reintente!");
                       }
                    }
                }
            }
        }
    }
    return 0;
}

int agregarProductoAdeposito(ArrayList* pDepositoI,ArrayList* pDepositoII){

    int auxProducto;
    int codigoProducto;
    int cantidadIngresada;
    int cantidadObtenidad;
    int resultadoCantidad;

    printf("\nIngrese el numero de producto a sumar: ");
    scanf("%d", &codigoProducto);

    for(int i=0; i< al_len(pDepositoI); i++){

        depositoI_getProducto(al_get(pDepositoI,i),&auxProducto);

        if(auxProducto == codigoProducto){

            printf("\nIngrese la cantidad de Productos a sumar: ");
            scanf("%d",&cantidadIngresada);

            if(!(depositoI_getCantidad(al_get(pDepositoI,i),&cantidadObtenidad))){

               if(cantidadIngresada>=0){
                    resultadoCantidad=cantidadObtenidad+cantidadIngresada;
               }
               if(resultadoCantidad >= 0){
                    depositoI_setCantidad(al_get(pDepositoI,i), resultadoCantidad);
               }
               else{
                printf("\nLa cantidad Ingresada supera a la cantidad actual en deposito. Reintente!");
               }
            }
        }else{

            depositoII_getProducto(al_get(pDepositoII,i),&auxProducto);

            for(int i=0; i< al_len(pDepositoII); i++){

                if(auxProducto == codigoProducto){
                    printf("\nIngrese la cantidad de Productos a Descontar: ");
                    scanf("%d",&cantidadIngresada);

                    if(!(depositoII_getCantidad(al_get(pDepositoII,i),&cantidadObtenidad))){
                        if(cantidadIngresada>=0){
                            resultadoCantidad=cantidadObtenidad+cantidadIngresada;
                        }
                       if(resultadoCantidad >= 0){
                            depositoII_setCantidad(al_get(pDepositoII,i), resultadoCantidad);
                       }
                       else{
                        printf("\nLa cantidad Ingresada supera a la cantidad actual en deposito. Reintente!");
                       }
                    }
                }
            }
        }
    }
    return 0;
}













