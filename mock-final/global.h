#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>
#define LARGO_TMENSAJE 1024
#define CLAVE_BASE 11
#define CLAVE 22
#define CLAVE1 33
#define CLAVE2 44
#define CANT 7

pthread_mutex_t mutex;


typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    int presidente;
    int vice_presidente;
};

int proceso_comenzo;

typedef struct thread_data array_type;
struct thread_data
{
    int num_jugador;
    char evento[20];
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
