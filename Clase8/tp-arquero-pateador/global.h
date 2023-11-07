#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>
#define LARGO_TMENSAJE 1024
#define CLAVE_BASE 33
#define CANT_JUGADORES 5

pthread_mutex_t mutex;


typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    char char_mensaje[LARGO_TMENSAJE]; // mensaje
};

typedef struct goles s_gol;
struct goles
{
    int gol;
    int jugador;
};

typedef struct thread_data data;
struct thread_data
{
    int num_jugador;
    char evento[20];
};

typedef enum
{
    MSG_NADIE,
    MSG_ARQUERO,
    MSG_PATEADOR
} Destinos;

typedef enum
{
    EVT_NINGUNO,
    EVT_TIRO,
    EVT_GOL,
    EVT_PALO,
    EVT_TRAVESANO,
    EVT_FUERA
} Eventos;

#endif
