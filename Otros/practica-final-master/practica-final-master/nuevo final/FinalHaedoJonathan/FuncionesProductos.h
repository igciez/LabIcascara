#ifndef FUNCIONESPRODUCTOS_H_INCLUDED
#define FUNCIONESPRODUCTOS_H_INCLUDED



/** \brief imprime los datos del item.
 *
 * \param item void* es el puntero a la estructura.
 * \return int 0 si esta ok, -1 si hay error.
 *
 */
int productos_imprimirProductos(void* item);
/** \brief mueve un elemento del deposito 0 al deposito 1
 *
 * \param pListaDep0 ArrayList* el puntero al deposito 0
 * \param pListaDep1 ArrayList* el puntero al deposito 1
 * \return int 0 si esta ok, -1 si hay error.
 *
 */
int productos_pasarDeDep0AlDep1(ArrayList* pListaDep0,ArrayList* pListaDep1);
/** \brief mueve un elemento del deposito 1 al deposito 0
 *
 * \param pListaDep0 ArrayList* el puntero al deposito 0
 * \param pListaDep1 ArrayList* el puntero al deposito 1
 * \return int 0 si esta ok, -1 si hay error.
 *
 */
int productos_pasarDeDep1AlDep0(ArrayList* pListaDep0,ArrayList* pListaDep1);
/** \brief verifica que exita el codigo del producto y descuenta la cantidad indicada por el usuario
 *
 * \param pListaDep ArrayList* es el puntero al deposito0
 * \param codigoDeProducto int es el codigo del producto a buscar
 * \return int retorna 0 si esta todo ok, 1 si no lo encuentra, -1 si hay error.
 *
 */
int productos_verificarExistenciaEnDeposito0yDescontar(ArrayList* pListaDep,int codigoDeProducto);
/** \brief verifica que exita el codigo del producto y descuenta la cantidad indicada por el usuario
 *
 * \param pListaDep ArrayList* es el puntero al deposito1
 * \param codigoDeProducto int es el codigo del producto a buscar
 * \return int retorna 0 si esta todo ok, 1 si no lo encuentra, -1 si hay error.
 *
 */
int productos_verificarExistenciaEnDeposito1yDescontar(ArrayList* pListaDep,int codigoDeProducto);
/** \brief verifica que exita el codigo del producto y Agrega la cantidad indicada por el usuario
 *
 * \param pListaDep ArrayList* es el puntero al deposito0
 * \param codigoDeProducto int es el codigo del producto a buscar
 * \return int retorna 0 si esta todo ok, 1 si no lo encuentra, -1 si hay error.
 *
 */
int productos_verificarExistenciaEnDeposito1yAgregar(ArrayList* pListaDep,int codigoDeProducto);
/** \brief verifica que exita el codigo del producto y Agrega la cantidad indicada por el usuario
 *
 * \param pListaDep ArrayList* es el puntero al deposito0
 * \param codigoDeProducto int es el codigo del producto a buscar
 * \return int retorna 0 si esta todo ok, 1 si no lo encuentra, -1 si hay error.
 *
 */
int productos_verificarExistenciaEnDeposito0yAgregar(ArrayList* pListaDep,int codigoDeProducto);
/** \brief usa dos funciones. las que verifica la exitencia de un codigo de producto y agrega el stock si lo encuentra pidiendo al usuario los datos necesarios
 *
 * \param ArrayList*pListaDep0 puntero al deposito 0
 * \param ArrayList*pListaDep1 puntero al deposito 1
 * \return int 0 si esta ok, -1 si hay error.
 *
 */
int productos_agregarStockDeDeposito(ArrayList*pListaDep0,ArrayList*pListaDep1);
/** \brief pide los datos al usuario y  verifica que no intente mover un producto al mismo deposito, verifica exitencia del codigo y si esta todo ok lo mueve
 *
 * \param pListaDep0 ArrayList* puntero al dep0
 * \param pListaDep1 ArrayList* puntero al dep1
 * \return int
 *
 */
int productos_cambiarDeDepositoUnProducto(ArrayList* pListaDep0,ArrayList* pListaDep1);
int productos_compareName(void* pClienteA,void* pClienteB);
int productos_descontarStockDeDoposito(ArrayList*pListaDep0,ArrayList*pListaDep1);
int productos_agregarStock(ArrayList*pListaDep,int index);
int productos_descontarStock(ArrayList*pListaDep,int index);
int productos_cargarDatosAlArchivo(char *name,ArrayList* this);
#endif // FUNCIONESPRODUCTOS_H_INCLUDED
