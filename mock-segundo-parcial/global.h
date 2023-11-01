#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>
#define LARGO_TMENSAJE 1024
#define CLAVE_BASE 33

pthread_mutex_t mutex;

typedef struct cant_insumos insumos;
struct cant_insumos
{
     char tipo_insumo[20];
     int cant_de_insumo;
};


typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    char char_mensaje[LARGO_TMENSAJE]; // mensaje
};

typedef enum
{
    MSG_NADIE,
    MSG_HORMIGA_REINA,
    MSG_HORMIGA
} Destinos;

#endif
