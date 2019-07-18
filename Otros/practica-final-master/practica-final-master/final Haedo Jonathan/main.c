#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "reparto.h"
#include "parser.h"
#include "ArrayList.h"

int main()
{
    ArrayList* pListaRepartos=al_newArrayList();
    ArrayList* pListaLocalidades=al_newArrayList();
    ArrayList* pListaConLocalidadesFiltradas=al_newArrayList();
    char auxLocalidadUno[250];
    char auxLocalidadDos[250];
    char auxLocalidadTres[250];
    int menu;

    do
    {
        menu=utn_menuDeOpciones();
        switch(menu)
        {
        case 1:

            parserReparto("DATA_FINAL_V3.CSV",pListaRepartos);
            break;
        case 2:
            al_map(pListaRepartos,reparto_imprimirRepartos);
            break;
        case 3:
            al_sort(pListaRepartos,reparto_compareLocalidad,1);
            reparto_separarLocalidadesRepetidas(pListaRepartos,pListaLocalidades);
            break;
        case 4:
            if(!utn_getValidString("ingrese la primera localidad","ERROR localidad no valida","demaciados caracteres",auxLocalidadUno,25,2))
            {
                if(!utn_getValidString("ingrese la segunda localidad","ERROR localidad no valida","demaciados caracteres",auxLocalidadDos,25,2))
                {
                    if(!utn_getValidString("ingrese la tercera localidad","ERROR localidad no valida","demaciados caracteres",auxLocalidadTres,25,2))
                    {
                        reparto_agregarAlArraylistDeLocalidades(pListaRepartos,auxLocalidadUno,pListaConLocalidadesFiltradas);
                        reparto_agregarAlArraylistDeLocalidades(pListaRepartos,auxLocalidadDos,pListaConLocalidadesFiltradas);
                        reparto_agregarAlArraylistDeLocalidades(pListaRepartos,auxLocalidadTres,pListaConLocalidadesFiltradas);
                    }
                }
            }
            reparto_cargarDatosAlArchivo("DATA_FINAL_V3.CSV",pListaConLocalidadesFiltradas);

            break;
        case 5:
            break;
        }
    }
    while(menu!=5);
    return 0;
}
