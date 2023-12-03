#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>
#define LARGO_TMENSAJE 1024
#define CLAVE_BASE 33
#define CANT 5
#define CANTIDAD 2

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

typedef struct tipo_dato dato;
struct tipo_dato
{
	int numero_equipo;
	int puntaje;
};

typedef struct tipo_arranca arranca;
struct tipo_arranca
{
	int equipo1;
	int equipo2;
};

typedef struct tipo_equipos equipo;
struct tipo_equipos
{
	int equipo1;
	int jugador_e_1;
	int equipo2;
	int jugador_e_2;
};

typedef struct thread_data array_type;
struct thread_data
{
    int num_jugador;
    char evento[20];
};

typedef enum
{
    MSG_EQUIPO1_JUGADOR = 0,
    MSG_EQUIPO2_JUGADOR = 5
} Destinos;

typedef enum
{
    EVT_NINGUNO,
    EVT_INICIO,
    EVT_VOTO
} Eventos;

#endif
