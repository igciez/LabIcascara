#ifndef LOGENTRY_H_INCLUDED
#define LOGENTRY_H_INCLUDED
typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];
}S_LogEntry;

S_LogEntry* LogEntry_new();
void LogEntry_delete();
S_LogEntry* LogEntry_newConParametros(char* date,char* time,int serviceId,int gravedad,char* msg);

int LogEntry_setDate(S_LogEntry* this,char* date);
int LogEntry_getDate(S_LogEntry* this,char* date);

int LogEntry_setTime(S_LogEntry* this,char* time);
int LogEntry_getTime(S_LogEntry* this,char* time);

int LogEntry_setServiceId(S_LogEntry* this,int serviceId);
int LogEntry_getServiceId(S_LogEntry* this,int* serviceId);

int LogEntry_setGravedad(S_LogEntry* this,int gravedad);
int LogEntry_getGravedad(S_LogEntry* this,int* gravedad);

int LogEntry_setMsg(S_LogEntry* this,char* msg);
int LogEntry_getMsg(S_LogEntry* this,char* msg);

#endif // LOGENTRY_H_INCLUDED
