#ifndef DEPOSITOII_H_INCLUDED
#define DEPOSITOII_H_INCLUDED
typedef struct
{
    int producto;
    char descripcion[500];
    int cantidad;
}eDepositoII;

eDepositoII* depositoII_new();
void depositoII_delete();
eDepositoII* depositoII_newConParametros(int producto,char* descripcion,int cantidad);

int depositoII_setProducto(eDepositoII* this,int producto);
int depositoII_getProducto(eDepositoII* this,int* producto);

int depositoII_setDescripcion(eDepositoII* this,char* descripcion);
int depositoII_getDescripcion(eDepositoII* this,char* descripcion);

int depositoII_setCantidad(eDepositoII* this,int cantidad);
int depositoII_getCantidad(eDepositoII* this,int* cantidad);

#endif // DEPOSITOII_H_INCLUDED
