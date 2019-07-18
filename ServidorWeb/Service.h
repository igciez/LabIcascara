#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
typedef struct
{
    int id;
    char name[33];
    char email[65];
}S_Service;

S_Service* Service_new();
void Service_delete();
S_Service* Service_newConParametros(int id,char* name,char* email);

int Service_setId(S_Service* this,int id);
int Service_getId(S_Service* this,int* id);

int Service_setName(S_Service* this,char* name);
int Service_getName(S_Service* this,char* name);

int Service_setEmail(S_Service* this,char* email);
int Service_getEmail(S_Service* this,char* email);

#endif // SERVICE_H_INCLUDED
