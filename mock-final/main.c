#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>
#include <evento.h>
#include <sys/msg.h>
#include <memory.h>

int main(int arg, char *argv[])
{
    pthread_t *idHilo;
    pthread_attr_t atributos;
    int i;

    int id_memoria;
    int id_memoria_test;
    int id_memoria_turnos;
    int id_cola_mensajes;
    comenzo *proceso_comenzo = NULL;
    puntaje *puntaje_equipo = NULL;
    turnos *turno = NULL;
    int id_semaforo;

    array_type *array = NULL;

    proceso_comenzo = (comenzo *)creo_memoria(sizeof(comenzo), &id_memoria, CLAVE);
    proceso_comenzo->thread1 = 1;

    puntaje_equipo = (puntaje *)creo_memoria(sizeof(puntaje) * 2, &id_memoria_test, CLAVE1);
    printf("Inicializo puntajes:\n");
    puntaje_equipo[0].puntos = 0;
    puntaje_equipo[1].puntos = 0;
    printf("Puntaje equipo 1: %d\nPuntaje equipo 2: %d\n", puntaje_equipo[0].puntos, puntaje_equipo[1].puntos);

    turno = (turnos *)creo_memoria(sizeof(turnos) * 2, &id_memoria_turnos, CLAVE2);
    printf("Inicializando turnos:\n");
    turno[0].equipo = 1;
    turno[0].jugador = 1;
    turno[1].equipo = 0;
    turno[1].jugador = 1;
    printf("Listo\n");

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    borrar_mensajes(id_cola_mensajes);

    id_semaforo = create_semaphore();

    init_semaphore(id_semaforo, VERDE);

    idHilo = (pthread_t *)malloc(sizeof(pthread_t) * CANT);
    array = (array_type *)malloc(sizeof(array_type) * CANT);

    while (proceso_comenzo->thread2 != 1)
    {
        usleep(100 * 1000);
    }

    pthread_mutex_init(&mutex1, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < CANT; i++)
    {
        array[i].num_equipo = 0;
        array[i].num_jugador = i + 1;
        if (pthread_create(&idHilo[i], &atributos, funcionThread1, &array[i]) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    for (i = 0; i < CANT; i++)
    {
        pthread_join(idHilo[i], NULL);
    }

    proceso_comenzo->thread1 = 0;
    while (proceso_comenzo->thread2 != 0)
    {
        usleep(100 * 1000);
    }

    pthread_mutex_destroy(&mutex1);
    shmdt((char *)proceso_comenzo);
    shmdt((char *)puntaje_equipo);
    shmdt((char *)turno);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
    shmctl(id_memoria_test, IPC_RMID, (struct shmid_ds *)NULL);
    shmctl(id_memoria_turnos, IPC_RMID, (struct shmid_ds *)NULL);

    free(idHilo);
    free(array);

    return 0;
}
