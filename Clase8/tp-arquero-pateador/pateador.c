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

    int i;

    data *thread_data;

    idHilo = (pthread_t *)malloc(sizeof(pthread_t) * CANT_JUGADORES);
    thread_data = (data *)malloc(sizeof(data) * CANT_JUGADORES);


    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < CANT_JUGADORES; i++)
    {
        thread_data[i].num_jugador = i;
        if (pthread_create(&idHilo[i], &atributos, funcionThread, &thread_data[i]) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        pthread_join(idHilo[i], NULL);
    }
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        printf("El jugador %d: %s\n", thread_data[i].num_jugador + 1, thread_data[i].evento);
    }
    return 0;
}
