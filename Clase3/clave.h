#ifndef _CLAVE
#define _CLAVE
#include <sys/ipc.h>

#define ROJO 0
#define VERDE 1
#define CLAVE_BASE 33


key_t creo_clave();
int creo_semaforo();
void inicia_semaforo(int, int);
void levanta_semaforo(int);
void espera_semaforo(int);


#endif