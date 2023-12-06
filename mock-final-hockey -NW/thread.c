#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>
#include <evento.h>
#include <memory.h>
#include <semaforo.h>

void *funcionThread(void *parametro)
{
    int id_memoria_puntaje;

    dato *punt = NULL;

    punt = (dato *)creo_memoria(sizeof(dato), &id_memoria_puntaje, CLAVE_BASE);

    pthread_mutex_lock(&mutex);


    punt->puntaje = punt->puntaje + 1;
    printf("%d\n", punt->puntaje);

    pthread_mutex_unlock(&mutex);
    usleep(100 * 1000);
    shmdt(punt);

    pthread_exit((void *)"Listo");
}
