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
#include <memory.h>
#include <sys/msg.h>

int main(int arg, char *argv[])
{
    pthread_t *idHilo;
    pthread_attr_t atributos;

    int i;
    int id_memoria;
    

    array_type *array;

    comenzo *proceso_comenzo = NULL;
    proceso_comenzo = (comenzo *)creo_memoria(sizeof(comenzo), &id_memoria, CLAVE);
    proceso_comenzo->thread2 = 1;
        
    while (proceso_comenzo->thread1 != 1)
    {
        usleep(100 * 1000);
    }

    idHilo = (pthread_t *)malloc(sizeof(pthread_t) * CANT);
    array = (array_type *)malloc(sizeof(array_type) * CANT);

    pthread_mutex_init(&mutex2, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < CANT; i++)
    {
        array[i].num_equipo = 1;
        array[i].num_jugador = i + 1;
        if (pthread_create(&idHilo[i], &atributos, funcionThread2, &array[i]) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    for (i = 0; i < CANT; i++)
    {
        pthread_join(idHilo[i], NULL);
    }

    proceso_comenzo->thread2 = 0;
    while (proceso_comenzo->thread1 != 0)
    {
        usleep(100 * 1000);
    }

    pthread_mutex_destroy(&mutex2);
    shmdt((char *)proceso_comenzo);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	free(idHilo);
    free(array);
    return 0;
}
