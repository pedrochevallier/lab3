#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>

// la hormiga debe recibir 
// - el puntero al array con los insumos
// - el numero de hormiga que es

void *funcionThread(void *parametro)
{
    int id_cola_mensajes;
    mensaje msg;
    int i = 0;
    int num_hormiga;    
    num_hormiga = *(int *)parametro;

    printf("Soy la hormiga numero: %d\n", num_hormiga);

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    pthread_mutex_lock(&mutex);
    
    recibir_mensaje(id_cola_mensajes,MSG_HORMIGA+i, &msg);
    
    pthread_mutex_unlock(&mutex);
    usleep(1000 * 100);
    
    pthread_exit((void *)"Listo");
}
