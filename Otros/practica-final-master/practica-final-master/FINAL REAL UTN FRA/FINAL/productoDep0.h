#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct
{
    int producto;
    char descripcion[250];
    int cantidad;
}EProducto;

EProducto* producto_new();
void producto_delete();
EProducto* producto_newConParametros(int producto,char* descripcion,int cantidad);

int producto_setProducto(EProducto* this,int producto);
int producto_getProducto(EProducto* this,int* producto);

int producto_setDescripcion(EProducto* this,char* descripcion);
int producto_getDescripcion(EProducto* this,char* descripcion);

int producto_setCantidad(EProducto* this,int cantidad);
int producto_getCantidad(EProducto* this,int* cantidad);

#endif // PRODUCTO_H_INCLUDED
