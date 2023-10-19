#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>
#define CLAVE_BASE 33
#define SEMAFORO0 0
#define LARGO_TMENSAJE 1024
typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
    long long_dest;                    // Destinatario
    int int_rte;                       // Remitente
    int int_evento;                    // Numero de evento
    char char_mensaje[LARGO_TMENSAJE]; // mensaje
};

#endif
