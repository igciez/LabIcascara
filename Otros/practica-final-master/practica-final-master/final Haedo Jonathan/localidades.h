#ifndef LOCALIDADES_H_INCLUDED
#define LOCALIDADES_H_INCLUDED
typedef struct
{
    char localidad[250];
}ELocalidades;

ELocalidades* localidades_new();
void localidades_delete();
ELocalidades* localidades_newConParametros(char* localidad);

int localidades_setLocalidad(ELocalidades* this,char* localidad);
int localidades_getLocalidad(ELocalidades* this,char* localidad);

#endif // LOCALIDADES_H_INCLUDED
