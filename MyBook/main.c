#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "funciones.h"
#include "utn.h"


int main()
{
    int menu;
    ArrayList* pUsuario= al_newArrayList();
    ArrayList* pPost=al_newArrayList();
    ArrayList* pFeed=al_newArrayList();

    do
    {
        menu=utn_menuDeOpciones();
        switch(menu)
        {
            case 1:
                parserPost("mensajes.csv",pPost);
                parserUsuarios("usuarios.csv",pUsuario);
                break;
            case 2:
                crearArchivosFeed(pUsuario,pPost,pFeed);
                break;
        }
    }while(menu!=6);
}
