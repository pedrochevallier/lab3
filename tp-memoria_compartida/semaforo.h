#ifndef _SEMAFORO
#define _SEMAFORO

#define ROJO 0
#define VERDE 1
#define CLAVE_BASE 33

int create_semaphore(void);
void init_semaphore(int, int);
void semaphore_release(int);
void semaphore_wait(int);

#endif
