#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"



float utn_getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int utn_getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char utn_getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    utn_clearStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}

char utn_getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int utn_esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int utn_esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

int utn_esSoloLetras(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

char* utn_getValidName()
{
    char *retorno=NULL;
    char auxName[25];
    utn_getValidString("ingrese el Nombre","ERROR, Nombre no valido","ERROR, son demaciados caracteres para un nombre",auxName,25,2);
        if(utn_esSoloLetras(auxName)==1)
        {
            retorno= auxName;
        }
        else
        printf("El nombre solo puede contener letras.");

    return retorno;
}



int utn_esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
int utn_esCuitConGuiones(char* str)
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones<=2) // debe tener un guion
        return 1;

    return 0;
}


int utn_esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


void utn_getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    utn_clearStdin();
    scanf ("%[^\n]s", input);
}


int utn_getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    utn_getString(mensaje,aux);
    if(utn_esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int utn_getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    utn_getString(mensaje,aux);
    if(utn_esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int utn_getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    utn_getString(mensaje,aux);
    if(utn_esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int utn_getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!utn_getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}



int utn_getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!utn_getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


int utn_getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps)
{
    char auxStr[256];
    int i, retorno = -1;
    float auxInt;

    for(i=0;i<attemps;i++)
    {
        if (!utn_getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}



void utn_clearStdin(void)
{
    setbuf(stdin,NULL);
}


void pause(void)
{
    utn_getChar("");
}


void utn_clearScreen(void)
{
    system("clear"); //system("cls");
}
int utn_menuDeOpciones(void)
{
    int menu;

       printf("1-CARGAR DESTINATARIOS \n");
       printf("----------------------------------\n");
       printf("2-CARGAR LISTA NEGRA \n");
       printf("----------------------------------\n");
       printf("3-DEPURAR \n");
       printf("----------------------------------\n");
       printf("4-LISTAR \n");
       printf("----------------------------------\n");
       printf("5-CARGAR DATOS AL ARCHIVO \n");
       printf("----------------------------------\n");
       printf("6-LEER DATOS DEL ARCHIVO! \n");
       printf("----------------------------------\n");
       printf("7-ELIMINAR ARCHIVO \n");
       printf("----------------------------------\n");
       printf("8-RENOMBRAR ARCHIVO! \n");
       printf("----------------------------------\n");
       printf("9-LIMPIAR CONSOLA! \n");
       printf("----------------------------------\n");
       utn_getValidInt("10-salir.","la opcion no exite\n",&menu,1,12,1);
   return menu;

}
int utn_getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    utn_getString(mensaje,aux);
    if(utn_esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int utn_getValidStringAlfaNumerico(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!utn_getStringAlfaNumerico(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

int utn_isValidDni(char*dni)
{
    int retorno=-1;
    if(dni!=NULL)
    {

        if(utn_esNumerico(dni)==1)
        {
            if(strlen(dni) > 8)
            {
            printf("un DNI valido no puede exeder los 8 caracteres");
            }
            else if(strlen(dni)<8)
            {
            printf("un DNI valido no puede tener menos de 8 caracteres");
            }
            else
            {
                retorno=0;
            }
        }
        else
        printf("el Dni debe ser solo Numeros");

    }
    else
    printf("ERROR, 'dni' es NULL");
    return retorno;
}
int utn_isValidName(char* name)
{
    char retorno=-1;
    if(name!=NULL)
    {
        if(utn_esSoloLetras(name)==1)
        {
            if(strlen(name)>3)
            {
            retorno= 0;
            }
            else
            printf("el nombre debe contener minimo 3 caracteres");
        }
        else
        printf("El nombre solo puede contener letras.");
    }
    else
    printf("name es NULL");

    return retorno;
}



int utn_isValidCuitSinGuiones(char* cuit)
{
    int retorno=-1;
    if(cuit!=NULL)
    {
        if(utn_esNumerico(cuit)==1)
        {
                if(strlen(cuit)>11)
                {
                    printf("un CUIT valido no puede exeder los 11 caracteres");
                }
                else if(strlen(cuit)<11)
                {
                    printf("un CUIT valido no puede tener menos de 11 caracteres");
                }
                else
                {
                retorno=0;
                }
        }

        else
        {
        printf("Cuit No Valido, solo puede contener Numeros (sin Guiones)");
        }
    }
    return retorno;

}
int utn_isValidCuitConGuiones(char* cuit)
{
    int retorno=-1;
    if(cuit!=NULL)
    {
        if(utn_esCuitConGuiones(cuit)==1)
        {
            if( (cuit[2]=='-') && (cuit[11]=='-') )
            {
                if(strlen(cuit)>13)
                {
                    printf("un CUIT valido con guiones no puede exeder los 13 caracteres");
                }
                else if(strlen(cuit)<13)
                {
                    printf("un CUIT valido con guiones no puede tener menos de 13 caracteres");
                }
                else
                {
                retorno=0;
                }
            }
            else
            printf("los guiones no estan en su lugar");
            printf("Ejemplo Cuit Valido: XX-XXXXXXXX-X");
        }
        else
        printf("ERROR, cuit no valido");
    }


    return retorno;

}
char* utn_agregarGuionesAlCuit(char* cuit)
{
    char auxCuit[13];
    char* retorno=NULL;
    int i;
    if(cuit!=NULL)
    {
        for(i=0;i<11;i++)
        {
            auxCuit[i]=cuit[i];
            if( ((i==2) && (cuit[2]!='-') )|| ((i==10) && (cuit[10]!='-')) )
            {
                auxCuit[i]= '-';
                auxCuit[i+1]=cuit[i];
            }
        }
        retorno=auxCuit;
    }
    return retorno;
}

int utn_IsValidSueldo(int sueldo)
{
    int retorno=-1;
    if(sueldo>0 && sueldo< 1000000)
    {
        retorno=0;
    }
    else
        printf("Sueldo Invalido");
    return retorno;
}

