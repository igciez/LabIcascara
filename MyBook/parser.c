#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "usuario.h"
#include "post.h"
#include "feed.h"


int parserPost(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char id_mensaje[4000];
    char mensaje[4000];
    char popularidad[4000];
    char id_usuario[4000];
    int auxId_mensaje;
    int auxPopularidad;
    int auxId_usuario;
    EPost* auxPost;
    FILE* pFile;

    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
               id_mensaje, mensaje, popularidad, id_usuario);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
               id_mensaje, mensaje, popularidad, id_usuario);
            auxId_mensaje=atoi(id_mensaje);
            auxPopularidad=atoi(popularidad);
            auxId_usuario=atoi(id_usuario);
            auxPost = post_newConParametros(auxId_mensaje,mensaje,auxPopularidad,auxId_usuario);
            al_add(pArrayListEmployee, auxPost);
        }
        fclose(pFile);
    }
    return retorno;
}

int parserUsuarios(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char id_usuario[4000];
    char nick[4000];
    char popularidad[4000];
    int auxPopularidad;
    int auxId_usuario;
    EUsuario* auxUsuario;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n",
               id_usuario, nick, popularidad);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n",
               id_usuario, nick, popularidad);
            auxPopularidad=atoi(popularidad);
            auxId_usuario=atoi(id_usuario);
            auxUsuario = usuario_newConParametros(auxId_usuario,nick,auxPopularidad);
            al_add(pArrayListEmployee, auxUsuario);
        }
        fclose(pFile);
    }
    return retorno;
}


int parser_guardar(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    //----------------
    int id_mensaje;
    char mensaje[1000];
    int popularidad_mensaje;
    int id_usuario;
    char nick[1000];
    int popularidad_usuario;
    //-----------------------
    EFeed* this;
    int i;

    FILE* pFile;
    pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id_mensaje,mensaje,popularidad_mensaje,id_usuario,nick,popularidad_usuario\n");
        for(i=0; i<al_len(pArrayListEmployee);i++)
        {
            retorno = 0;
            this = al_get(pArrayListEmployee, i);
            feed_getId_mensaje(this,&id_mensaje);
            feed_getMensaje(this,mensaje);
            feed_getPopularidad_mensaje(this,&popularidad_mensaje);
            feed_getId_usuario(this,&id_usuario);
            feed_getNick(this, nick);
            feed_getPopularidad_usuario(this, &popularidad_usuario);
            fprintf(pFile, "%d,%s,%d,%d,%s,%d\n", id_mensaje, mensaje, popularidad_mensaje, id_usuario, nick, popularidad_usuario);
        }
        fclose(pFile);
    }
    return retorno;
}

