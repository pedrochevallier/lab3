#ifndef _SEMAFORO
#define _SEMAFORO


int create_semaphore(void);
void init_semaphore(int, int);
void semaphore_release(int);
void semaphore_wait(int);

#endif
