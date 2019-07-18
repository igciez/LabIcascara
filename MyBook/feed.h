#ifndef FEED_H_INCLUDED
#define FEED_H_INCLUDED
typedef struct
{
    int id_mensaje;
    char mensaje[1000];
    int popularidad_mensaje;
    int id_usuario;
    char nick[1000];
    int popularidad_usuario;
}EFeed;

EFeed* feed_new();
void feed_delete();
EFeed* feed_newConParametros(int id_mensaje,char* mensaje,int popularidad_mensaje,int id_usuario,char* nick,int popularidad_usuario);

int feed_setId_mensaje(EFeed* this,int id_mensaje);
int feed_getId_mensaje(EFeed* this,int* id_mensaje);

int feed_setMensaje(EFeed* this,char* mensaje);
int feed_getMensaje(EFeed* this,char* mensaje);

int feed_setPopularidad_mensaje(EFeed* this,int popularidad_mensaje);
int feed_getPopularidad_mensaje(EFeed* this,int* popularidad_mensaje);

int feed_setId_usuario(EFeed* this,int id_usuario);
int feed_getId_usuario(EFeed* this,int* id_usuario);

int feed_setNick(EFeed* this,char* nick);
int feed_getNick(EFeed* this,char* nick);

int feed_setPopularidad_usuario(EFeed* this,int popularidad_usuario);
int feed_getPopularidad_usuario(EFeed* this,int* popularidad_usuario);

#endif // FEED_H_INCLUDED
