#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct
{
    int id_usuario;
    char nick[1000];
    int popularidad;
}EUsuario;

EUsuario* usuario_new();
void usuario_delete();
EUsuario* usuario_newConParametros(int id_usuario,char* nick,int popularidad);

int usuario_setId_usuario(EUsuario* this,int id_usuario);
int usuario_getId_usuario(EUsuario* this,int* id_usuario);

int usuario_setNick(EUsuario* this,char* nick);
int usuario_getNick(EUsuario* this,char* nick);

int usuario_setPopularidad(EUsuario* this,int popularidad);
int usuario_getPopularidad(EUsuario* this,int* popularidad);

#endif // USUARIO_H_INCLUDED
