#ifndef _COLA_H
#define _COLA_H
#include <global.h>
int creo_id_cola_mensajes(int);
int borrar_mensajes(int);
int recibir_mensaje(int, long, mensaje_hormiga *);
int enviar_mensaje(int, long, int, int, int, char *);
#endif
