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
    int id_semaforo;
    int id_memoria;
    int *test = NULL;
    int num_proceso;
    
    num_proceso = *(int *)parametro;
    id_semaforo = create_semaphore();
    
    semaphore_wait(id_semaforo);


    test = (int *)creo_memoria(sizeof(int), &id_memoria, CLAVE1);
    
    *test = *test + 1;
    printf("Proceso: %d\n", num_proceso);
    
    usleep(100 * 1000);
    printf("Corriendo el hilo\n");
    printf("%d\n", *test);
    semaphore_release(id_semaforo);
    pthread_exit((void *)"Listo!");
}
