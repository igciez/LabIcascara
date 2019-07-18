#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "funciones.h"
#include "utn.h"

int main()
{
    int menu;

    ArrayList* alLogEntry= al_newArrayList();
    ArrayList* alService=al_newArrayList();

    do
    {
        menu=utn_menuDeOpciones();
        switch(menu)
        {
            case 1:
                parserLogEntry("log.txt" , alLogEntry);
                parserService("services.txt" , alService);
                break;
            case 2:
                procesarInformacion(alLogEntry,alService);
        }
    }while(menu!=3);

    return 0;
}
