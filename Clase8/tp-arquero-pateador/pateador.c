#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>
#include <evento.h>

int main(int arg, char *argv[])
{
    pthread_t *idHilo;
    pthread_attr_t atributos;

    int id_cola_mensajes;
    int *pateador;
    int i;
    char *valorDevuelto = NULL;


    printf("llegue hasta aca\n");
    pateador = (int *)malloc(sizeof(int) * CANT_JUGADORES);
    idHilo = (pthread_t *)malloc(sizeof(pthread_t) * CANT_JUGADORES);

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < CANT_JUGADORES; i++)
    {
        pateador[i] = i;
        if (pthread_create(&idHilo[i], &atributos, funcionThread, &pateador[i]) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        pthread_join(idHilo[i], (void **)&valorDevuelto);
        printf("%s\n",valorDevuelto);
    }

    return 0;
}
