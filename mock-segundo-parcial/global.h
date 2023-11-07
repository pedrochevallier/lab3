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

insumos insumo[4];
int finalizar;

typedef struct tipo_mensajes mensaje_hormiga;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    int insumo;
    char char_mensaje[LARGO_TMENSAJE]; // mensaje
};

typedef enum
{
    MSG_NADIE,
    MSG_HORMIGA_REINA,
    MSG_HORMIGA
} Destinos;

typedef enum
{
    // eventos reina
    EVT_NINGUNO,
    EVT_JUNTAR,
    EVT_PARAR,
    EVT_FIN,
    //eventos hormiga
    EVT_RTA_JUNTAR
} Eventos;

#endif
