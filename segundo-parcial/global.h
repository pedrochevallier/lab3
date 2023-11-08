#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>
#define LARGO_TMENSAJE 1024
#define CLAVE_BASE 124
#define CANT 5
#define ROJO 0
#define VERDE 1
#define CANT_VOTOS 100

pthread_mutex_t mutex;

typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;      // Destinatario
    int int_rte;         // Remitente
    int int_evento;      // Numero de evento
    int presidente;      // Presidente
    int vice_presidente; // Vicepresidente
};

typedef struct votos_data votos;
struct votos_data
{
    int presidente1;
    int vice1;
    int presidente2;
    int vice2;
};

typedef enum
{
    MSG_NADIE,
    MSG_PANEL,
    MSG_VOTANTE
} Destinos;

typedef enum
{
    EVT_NINGUNO,
    EVT_INICIO,
    EVT_VOTO
} Eventos;

#endif
