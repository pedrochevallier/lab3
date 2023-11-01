#ifndef _GLOBAL
#define _GLOBAL
#include <pthread.h>

pthread_mutex_t mutex;


struct thread_data
{
    int numero_aleatorio;
    int alguien_acerto;
    int cantidad_threads;
};
struct thread_data data;

#endif
