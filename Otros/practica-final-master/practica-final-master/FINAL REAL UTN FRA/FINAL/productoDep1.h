#ifndef PRODUCTODEP1_H_INCLUDED
#define PRODUCTODEP1_H_INCLUDED
typedef struct
{
    int producto;
    char descripcion[250];
    int cantidad;
}EProductoDep1;

EProductoDep1* productoDep1_new();
void productoDep1_delete();
EProductoDep1* productoDep1_newConParametros(int producto,char* descripcion,int cantidad);

int productoDep1_setProducto(EProductoDep1* this,int producto);
int productoDep1_getProducto(EProductoDep1* this,int* producto);

int productoDep1_setDescripcion(EProductoDep1* this,char* descripcion);
int productoDep1_getDescripcion(EProductoDep1* this,char* descripcion);

int productoDep1_setCantidad(EProductoDep1* this,int cantidad);
int productoDep1_getCantidad(EProductoDep1* this,int* cantidad);

#endif // PRODUCTODEP1_H_INCLUDED
