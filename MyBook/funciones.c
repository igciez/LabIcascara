#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "feed.h"
#include "parser.h"
#include "usuario.h"
#include "post.h"

int crearArchivosFeed(ArrayList* pUsuario,ArrayList* pPost,ArrayList* pFeed){

    int id_mensaje;
    int i;
    int j;
    char mensaje[1000];
    int popularidad_mensaje;
    int id_usuario;
    int id_usuarioPost;
    char nick[1000];
    int popularidad_usuario;
    EFeed* auxFeed= NULL;

    for(i=0;i<al_len(pUsuario);i++){

        usuario_getId_usuario(al_get(pUsuario,i),&id_usuario);
        usuario_getNick(al_get(pUsuario,i),nick);
        usuario_getPopularidad(al_get(pUsuario,i),&popularidad_usuario);

        for(j=0;j<al_len(pPost);j++){
           post_getId_usuario(al_get(pPost,j),&id_usuarioPost);
           if(id_usuario == id_usuarioPost){
                post_getPopularidad(al_get(pPost,j),&popularidad_mensaje);
                post_getMensaje(al_get(pPost,j),mensaje);
                post_getId_mensaje(al_get(pPost,j),&id_mensaje);
                //inicializo estructura
                auxFeed= feed_new();
                //Set
                feed_setId_mensaje(auxFeed,id_mensaje);
                feed_setMensaje(auxFeed,mensaje);
                feed_setPopularidad_mensaje(auxFeed,popularidad_mensaje);
                feed_setId_usuario(auxFeed,id_usuario);
                feed_setNick(auxFeed,nick);
                feed_setPopularidad_usuario(auxFeed,popularidad_usuario);
                //arrayList
                al_add(pFeed,auxFeed);
            }
        }
    }

    if(pFeed!=NULL){
        if(al_sort(pFeed,ordenarFeed,1) != -1){
            parser_guardar("feed.csv",pFeed);
        }
    }
    return 0;
}

int ordenarFeed(void* pFeedUno,void* pFeedDos){

    int auxpFeedUno;
    int auxpFeedDos;

    feed_getPopularidad_usuario(pFeedUno,&auxpFeedUno);
    feed_getPopularidad_usuario(pFeedDos,&auxpFeedDos);

    if(auxpFeedUno > auxpFeedDos ){
        return -1;
    }
    else if(auxpFeedUno < auxpFeedDos) {
        return 1;
    }
    else if(auxpFeedUno == auxpFeedDos){
       feed_getPopularidad_mensaje(pFeedUno,&auxpFeedUno);
       feed_getPopularidad_mensaje(pFeedDos,&auxpFeedDos);

        if(auxpFeedUno > auxpFeedDos ){
            return -1;
        }
        else if(auxpFeedUno < auxpFeedDos) {
            return 1;
        }
    }
    return 0;
}

