#ifndef _SEMAFORO
#define _SEMAFORO

#define ROJO 0
#define VERDE 1
#define CLAVE_BASE 33

int creo_semaforo();
void inicia_semaforo(int, int);
void levanta_semaforo(int);
void espera_semaforo(int);

#endif