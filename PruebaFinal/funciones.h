#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
#include "depositoI.h"

void imprimirDepositos (ArrayList* pDepositoI,ArrayList* pDepositoII);
int imprimeDepositoI (void* this);
int imprimeDepositoII (void* this);
int moverProductosAdeposito(ArrayList* pDepositoI,ArrayList* pDepositoII);
int descontarProductoDeDeposito(ArrayList* pDepositoI,ArrayList* pDepositoII);
int agregarProductoAdeposito(ArrayList* pDepositoI,ArrayList* pDepositoII);


#endif // FUNCIONES_H_INCLUDED
