#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED
typedef struct
{
    int id_mensaje;
    char mensaje[1000];
    int popularidad;
    int id_usuario;
}EPost;

EPost* post_new();
void post_delete();
EPost* post_newConParametros(int id_mensaje,char* mensaje,int popularidad,int id_usuario);

int post_setId_mensaje(EPost* this,int id_mensaje);
int post_getId_mensaje(EPost* this,int* id_mensaje);

int post_setMensaje(EPost* this,char* mensaje);
int post_getMensaje(EPost* this,char* mensaje);

int post_setPopularidad(EPost* this,int popularidad);
int post_getPopularidad(EPost* this,int* popularidad);

int post_setId_usuario(EPost* this,int id_usuario);
int post_getId_usuario(EPost* this,int* id_usuario);

#endif // POST_H_INCLUDED
