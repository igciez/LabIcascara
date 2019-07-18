#ifndef FUNCIONESPRODUCTOS_H_INCLUDED
#define FUNCIONESPRODUCTOS_H_INCLUDED

int productos_imprimirProductos();
int productos_pasarDeDep0AlDep1(ArrayList* pListaDep0,ArrayList* pListaDep1);
int productos_pasarDeDep1AlDep0(ArrayList* pListaDep0,ArrayList* pListaDep1);
int productos_cambiarDeDepositoUnProducto(ArrayList* pListaDep0,ArrayList* pListaDep1);
int productos_descontarStockDeDoposito(ArrayList*pListaDep0,ArrayList*pListaDep1);
int productos_verificarExistenciaEnDeposito0yDescontar(ArrayList* pListaDep,int codigoDeProducto);
int productos_verificarExistenciaEnDeposito1yDescontar(ArrayList* pListaDep,int codigoDeProducto);
int productos_descontarStock(ArrayList*pListaDep,int index);
int productos_verificarExistenciaEnDeposito1yAgregar(ArrayList* pListaDep,int codigoDeProducto);
int productos_verificarExistenciaEnDeposito0yAgregar(ArrayList* pListaDep,int codigoDeProducto);
int productos_agregarStockDeDeposito(ArrayList*pListaDep0,ArrayList*pListaDep1);
int productos_agregarStock(ArrayList*pListaDep,int index);
#endif // FUNCIONESPRODUCTOS_H_INCLUDED
