#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "cliente.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidEmail(char* email);
static int isValidGenero(char genero);
static int isValidUsuario(char* usuario);
static int isValidProfesion(char* profesion);
static int isValidNacionalidad(char* nacionalidad);

Cliente* cliente_new(void)
{
    Cliente* auxCliente = (Cliente*) malloc(sizeof(Cliente));
    return auxCliente;
}

Cliente* cliente_newParametros(char* strId, char* nombre, char* apellido
                               , char* email, char genero, char* profesion, char* usuario, char* nacionalidad)
{
    int id;
    Cliente* this;
    id = atoi(strId);
    this = cliente_new();
    if(!cliente_setId(this, id) &&
       !cliente_setNombre(this, nombre) &&
       !cliente_setApellido(this, apellido) &&
       !cliente_setEmail(this, email) &&
       !cliente_setGenero(this, genero) &&
       !cliente_setProfesion(this, profesion) &&
       !cliente_setUsuario(this, usuario) &&
       !cliente_setNacionalidad(this, nacionalidad))
    {
        return this;
    }
    cliente_delete(this);
    return NULL;
}

int cliente_setId(Cliente* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    else if(this != NULL && id > ultimoId)
    {
        retorno = 0;
        ultimoId = id;
        this->id = ultimoId;
    }
    return retorno;
}

void cliente_delete(Cliente* this)
{
    if(this != NULL)
        free(this);
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && isValidApellido(apellido))
    {
        retorno = 0;
        strcpy(this->apellido,apellido);
    }
    return retorno;
}

int cliente_setEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
        retorno = 0;
        strcpy(this->email,email);
    }
    return retorno;
}

int cliente_setGenero(Cliente* this, char genero)
{
    int retorno = -1;
    if(this != NULL && isValidGenero(genero))
    {
        retorno = 0;
        this->genero = genero;
    }
    return retorno;
}

int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL && isValidUsuario(usuario))
    {
        retorno = 0;
        strcpy(this->usuario,usuario);
    }
    return retorno;
}

int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL && isValidProfesion(profesion))
    {
        retorno = 0;
        strcpy(this->profesion,profesion);
    }
    return retorno;
}

int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL && isValidNacionalidad(nacionalidad))
    {
        retorno = 0;
        strcpy(this->nacionalidad,nacionalidad);
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido,this->apellido);
    }
    return retorno;
}

int cliente_getEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        retorno = 0;
        strcpy(email,this->email);
    }
    return retorno;
}

int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        *genero = this->genero;
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL)
    {
        retorno = 0;
        strcpy(usuario,this->usuario);
    }
    return retorno;
}

int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL)
    {
        retorno = 0;
        strcpy(profesion,this->profesion);
    }
    return retorno;
}

int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL)
    {
        retorno = 0;
        strcpy(nacionalidad,this->nacionalidad);
    }
    return retorno;
}

void cliente_print(Cliente* this)
{
    char nombre[64];
    char apellido[64];
    char email[256];
    int id;
    if(this != NULL)
    {
        cliente_getId(this,&id);
        cliente_getNombre(this,nombre);
        cliente_getApellido(this,apellido);
        cliente_getEmail(this,email);
        fprintf(stdout,"Id: %d - Nombre: %s - Apellido: %s - Email: %s\n", id,nombre,apellido,email);
    }

}

int cliente_compareNombreApellido(void* pClienteA,void* pClienteB)
{
    int retorno;
    char nombreClienteA[64];
    char apellidoClienteA[64];
    char nombreClienteB[64];
    char apellidoClienteB[64];
    if(pClienteA!=NULL && pClienteB != NULL)
    {
        cliente_getNombre(pClienteA,nombreClienteA);
        cliente_getApellido(pClienteA,apellidoClienteA);
        cliente_getNombre(pClienteB,nombreClienteB);
        cliente_getApellido(pClienteB,apellidoClienteB);

        if(strcmp(nombreClienteA, nombreClienteB)<0)
        {
            retorno = -1;
        }
        else if(strcmp(nombreClienteA, nombreClienteB)>0)
        {
            retorno = 1;
        }
        else if(!strcmp(nombreClienteA,nombreClienteB))
        {
            if(strcmp(apellidoClienteA, apellidoClienteB)<0)
            {
                retorno = -1;
            }
            else if(strcmp(apellidoClienteA, apellidoClienteB)>0)
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int cliente_compareMail(void* pClienteA,void* pClienteB)
{
    int retorno=0;
    char mailClienteA[64];
    char mailClienteB[64];
    if(pClienteA!=NULL && pClienteB != NULL)
    {
        cliente_getNombre(pClienteA,mailClienteA);
        cliente_getNombre(pClienteB,mailClienteB);
        if(strcmp(mailClienteA, mailClienteB)<0)
        {
            retorno = -1;
        }
        else if(strcmp(mailClienteA, mailClienteB)>0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

static int isValidEmail(char* email)
{
    return 1;
}

static int isValidGenero(char genero)
{
    return 1;
}

static int isValidUsuario(char* usuario)
{
    return 1;
}

static int isValidProfesion(char* profesion)
{
    return 1;
}

static int isValidNacionalidad(char* nacionalidad)
{
    return 1;
}
