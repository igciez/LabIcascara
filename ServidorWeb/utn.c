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
int utn_esNombres(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int utn_getValidLastName(char* lastName)
{
    int retorno=-1;
    char auxLastName[25];
        if(!utn_getValidString("ingrese el LastName\n","ERROR, LastName no valido\n","ERROR, son demaciados caracteres para un LastName\n",auxLastName,25,2))
        {

            if(utn_esNombres(auxLastName)==1)
            {
                strcpy(lastName,auxLastName);
                retorno= 0;
            }
            else
            printf("El LastName solo puede contener letras\n");
        }

    return retorno;
}
int utn_getValidName(char* name)
{
    int retorno=-1;
    char auxName[25];
        if(!utn_getValidString("ingrese el Name\n","ERROR, Name no valido\n","ERROR, son demaciados caracteres para un Name\n",auxName,25,2))
        {

            if(utn_esNombres(auxName)==1)
            {
                strcpy(name,auxName);
                retorno= 0;
            }
            else
            printf("El name solo puede contener letras\n");
        }

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

int utn_getStringNumerico(char mensaje[],char input[])
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
int utn_getValidStringNumerico(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!utn_getStringNumerico(requestMessage,buffer))
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

int utn_getValidStringNumericoFloat(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!utn_getStringNumerosFlotantes(requestMessage,buffer))
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
       printf("\n------------MENU------------------\n");
       printf("1-Cargar Archivos \n");
       printf("----------------------------------\n");
       printf("2-Procesar Informacion. \n");
       printf("----------------------------------\n");
       printf("3-SALIR\n");
       utn_getValidInt("\nIngrese valor: ","la opcion no exite\n",&menu,1,3,1);
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
            retorno= 0;
        }
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
                    printf("un CUIT valido no puede exeder los 11 caracteres\n");
                }
                else if(strlen(cuit)<11)
                {
                    printf("un CUIT valido no puede tener menos de 11 caracteres\n");
                }
                else
                {
                retorno=0;
                }
        }

        else
        {
        printf("Cuit No Valido, solo puede contener Numeros (sin Guiones)\n");
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
                    printf("un CUIT valido con guiones no puede exeder los 13 caracteres\n");
                }
                else if(strlen(cuit)<13)
                {
                    printf("un CUIT valido con guiones no puede tener menos de 13 caracteres\n");
                }
                else
                {
                retorno=0;
                }
            }
            else
            printf("los guiones no estan en su lugar\n");
            printf("Ejemplo Cuit Valido: XX-XXXXXXXX-X\n");
        }
        else
        printf("ERROR, cuit no valido\n");
    }


    return retorno;

}
char* utn_agregarGuionesAlCuit(char* cuit)
{
    char auxCuit[13];
    char* retorno=NULL;
    int i,p=0;
    if(cuit!=NULL)
    {
        for(i=0;i<11;i++)
        {
            auxCuit[p]=cuit[i];
            if( ((i==2) && (cuit[2]!='-') )|| ((i==10) && (cuit[10]!='-')) )
            {
                auxCuit[p]= '-';
                p++;
                auxCuit[p]=cuit[i];
            }
            p++;
        }
        printf("%s",auxCuit);
        retorno=auxCuit;
    }
    return retorno;
}

int utn_IsValidSueldo(int sueldo)//sueldo en int.
{
    int retorno=-1;
    if(sueldo>0 && sueldo< 1000000)
    {
        retorno=0;
    }
    return retorno;
}



int utn_isValidMail(char* mail)
{
    int retorno=-1;
    if(mail!=NULL)
    {
        if(utn_esMail(mail)==1)
        {
            retorno=0;
        }
        else
            printf("el mail tiene  caracteres invalidos\n");

    }
    return retorno;
}

int utn_esMail(char str[])
{
   int i=0;
   int retorno=-1;
   int contadorArroba=0;
   while(str[i] != '\0')
   {
       if((str[i] != '@')&&(str[i] != '-')&&(str[i] != '_') &&(str[i] != '.')&& (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           retorno= 0;//si hay error
        if(str[i]=='@')
        {
            contadorArroba++;
        }
       i++;
   }
   if(contadorArroba==1)
   {
    retorno=1;//si esta todo ok
   }
   return retorno;
}

int utn_getValidDni(char*dni)
{
    int retorno=-1;
    char auxDni[25];
    if(utn_getStringNumeros("ingrese el Dni\n",auxDni)==1)
    {
        if(utn_isValidDni(auxDni)==0)
        {
            strcpy(dni,auxDni);
            retorno= 0;
        }
        else
        printf("El Dni solo puede contener solo numeros\n");

    }
    else printf("ERROR,solo numeros\n");


    return retorno;
}

int utn_getValidMail(char*mail)
{
    int retorno=-1;
    char auxMail[50];
    utn_getString("ingrese el Mail\n",auxMail);
    if(utn_esMail(auxMail)==1)
    {
        strcpy(mail,auxMail);
        retorno= 0;
    }
    else
        printf("error en los caracteres.\n");

return retorno;
}

int utn_getValidCuit(char*cuit)
{
    int retorno=-1;
    char auxCuit[25];
    if(utn_getStringNumeros("ingrese el Cuit\n",auxCuit)==1)
    {
        if(utn_isValidCuitSinGuiones(auxCuit)==0)
        {
            strcpy(auxCuit,utn_agregarGuionesAlCuit(auxCuit));
            strcpy(cuit,auxCuit);
            retorno= 0;
        }
        else
        printf("El Cuit solo puede contener solo numeros\n");

    }
    else printf("ERROR,solo numeros\n");


    return retorno;
}
