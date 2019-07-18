#ifndef DEPOSITOI_H_INCLUDED
#define DEPOSITOI_H_INCLUDED
typedef struct
{
    int producto;
    char descripcion[500];
    int cantidad;
}eDepositoI;

eDepositoI* depositoI_new();
void depositoI_delete();
eDepositoI* depositoI_newConParametros(int producto,char* descripcion,int cantidad);

int depositoI_setProducto(eDepositoI* this,int producto);
int depositoI_getProducto(eDepositoI* this,int* producto);

int depositoI_setDescripcion(eDepositoI* this,char* descripcion);
int depositoI_getDescripcion(eDepositoI* this,char* descripcion);

int depositoI_setCantidad(eDepositoI* this,int cantidad);
int depositoI_getCantidad(eDepositoI* this,int* cantidad);

#endif // DEPOSITOI_H_INCLUDED
