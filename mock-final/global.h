#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>
#define LARGO_TMENSAJE 1024
#define CLAVE_BASE 11
#define CLAVE 22
#define CLAVE1 33
#define CLAVE2 44
#define CANT 5

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;


typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    int presidente;
    int vice_presidente;
};

typedef struct thread_comenzo comenzo;
struct thread_comenzo
{
    int thread1;
    int thread2;
};

typedef struct tipo_turnos turnos;
struct tipo_turnos
{
    int equipo;
    int jugador;
};


typedef struct thread_data array_type;
struct thread_data
{
    int num_equipo;
    int num_jugador;
    char evento[20];
};

typedef struct tipo_puntaje puntaje;
struct tipo_puntaje
{
    int puntos;
};

typedef enum
{
    MSG_NADIE,
    MSG_ARQUERO1 = 1,
    MSG_ARQUERO2 = 6
} Destinos;

typedef enum
{
    EVT_NINGUNO,
    EVT_TIRO,
    EVT_GOL
} Eventos;

#endif
