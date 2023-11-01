#ifndef _GLOBAL
#define _GLOBAL
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define CLAVE_BASE 33
#define LARGO_TMENSAJE 1024
#define CANTIDAD_JUGADORES 6

typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    char char_mensaje[LARGO_TMENSAJE]; // mensaje
};

typedef struct tipo_datos datos;
struct tipo_datos
{
    int dato;
};

typedef enum
{
    MSG_NADIE,
    MSG_REVOLVER,
    MSG_JUGADOR
} Destinos;

typedef enum
{
    EVT_NINGUNO,
    EVT_INICIO,
    EVT_DISPARO,
    EVT_SALVADO,
    EVT_FIN
} Eventos;

pthread_mutex_t mutex;

#endif
