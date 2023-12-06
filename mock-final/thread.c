#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>
#include <evento.h>
#include <memory.h>
#include <semaforo.h>

void *funcionThread1(void *parametro)
{
    int id_semaforo;
    int id_memoria;
    int id_memoria_turnos;
    int id_cola_mensajes;
    puntaje *puntaje_equipo = NULL;
    turnos *turno = NULL;
    array_type array;
    mensaje msg;

    array = *(array_type *)parametro;
    id_semaforo = create_semaphore();

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    while (1)
    {
        pthread_mutex_lock(&mutex1);
        puntaje_equipo = (puntaje *)creo_memoria(sizeof(puntaje) * 2, &id_memoria, CLAVE1);
        turno = (turnos *)creo_memoria(sizeof(turnos), &id_memoria_turnos, CLAVE2);

        if (puntaje_equipo[0].puntos >= 5 || puntaje_equipo[1].puntos >= 5)
        {
            shmdt(puntaje_equipo);
            shmdt(turno);
            pthread_mutex_unlock(&mutex1);
            pthread_exit((void *)"Listo!");
        }

        if (turno[array.num_equipo].equipo == 1 && turno[array.num_equipo].jugador == array.num_jugador)
        {
            printf("Soy el jugador: %d y me toca patear\n", array.num_jugador);
            enviar_mensaje(id_cola_mensajes, MSG_ARQUERO2, array.num_equipo * 5 + array.num_jugador, EVT_TIRO, "");
            recibir_mensaje(id_cola_mensajes, array.num_equipo * 5 +array.num_jugador, &msg);
            procesar_evento_pateador(id_cola_mensajes, msg, puntaje_equipo, array.num_equipo);

            printf("PUNTAJE %d - %d\n\n",puntaje_equipo[0].puntos, puntaje_equipo[1].puntos);

            // si llegue al jugador maximo reseteo el contador
            if (turno[array.num_equipo].jugador == CANT)
            {
                turno[array.num_equipo].jugador = 1;
            }
            else // sino sumo uno para que le toque al siguiente
            {
                turno[array.num_equipo].jugador = array.num_jugador + 1;
            }

            // me pongo en 0 para saber que ya pateo mi equipo
            turno[array.num_equipo].equipo = 0;
            
        }
        // si no es el turno de mi equipo de patear entonces tengo que atajar
        else if (turno[array.num_equipo].equipo == 0 && array.num_jugador == 1)
        {
            recibir_mensaje(id_cola_mensajes, array.num_equipo * 5 + 1, &msg);
            procesar_evento_arquero(id_cola_mensajes, msg);
            
            turno[array.num_equipo].equipo = 1;
        }
        shmdt(puntaje_equipo);
        shmdt(turno);
        pthread_mutex_unlock(&mutex1);
        usleep(100 * 1000);
    }

    pthread_exit((void *)"Listo!");
}

void *funcionThread2(void *parametro)
{
    int id_semaforo;
    int id_memoria;
    int id_memoria_turnos;
    int id_cola_mensajes;
    puntaje *puntaje_equipo = NULL;
    turnos *turno = NULL;
    array_type array;
    mensaje msg;

    array = *(array_type *)parametro;
    id_semaforo = create_semaphore();

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    while (1)
    {
        //printf("soy el jugador %d\n", array.num_jugador);
        pthread_mutex_lock(&mutex2);
        puntaje_equipo = (puntaje *)creo_memoria(sizeof(puntaje) * 2, &id_memoria, CLAVE1);
        turno = (turnos *)creo_memoria(sizeof(turnos), &id_memoria_turnos, CLAVE2);

        if (puntaje_equipo[0].puntos >= 5 || puntaje_equipo[1].puntos >= 5)
        {
            shmdt(puntaje_equipo);
            shmdt(turno);
            pthread_mutex_unlock(&mutex2);
            pthread_exit((void *)"Listo!");
        }

        if (turno[array.num_equipo].equipo == 1 && turno[array.num_equipo].jugador == array.num_jugador)
        {
            printf("Soy el jugador: %d y me toca patear\n", array.num_jugador);
            // le sumo un punto a mi equipo
            enviar_mensaje(id_cola_mensajes, MSG_ARQUERO1, array.num_equipo * 5 + array.num_jugador, EVT_TIRO, "");
            recibir_mensaje(id_cola_mensajes, array.num_equipo * 5 +array.num_jugador, &msg);
            procesar_evento_pateador(id_cola_mensajes, msg, puntaje_equipo, array.num_equipo);
            printf("PUNTAJE %d - %d\n\n",puntaje_equipo[0].puntos, puntaje_equipo[1].puntos);

            // si se llego al ultimo jugador resetear el numero de jugador
            if (turno[array.num_equipo].jugador == CANT)
            {
                turno[array.num_equipo].jugador = 1;
            }
            else // sino sumar uno para que le toque al siguiente
            {
                turno[array.num_equipo].jugador = array.num_jugador + 1;
            }
            // me des-asigno el turno
            turno[array.num_equipo].equipo = 0;
        }
        else if (turno[array.num_equipo].equipo == 0 && array.num_jugador == 1)
        {
            recibir_mensaje(id_cola_mensajes, array.num_equipo * 5 + 1, &msg);
            procesar_evento_arquero(id_cola_mensajes, msg);
            // si soy el equipo 0 le doy el turno al equipo 1
            turno[array.num_equipo].equipo = 1;
        }
        shmdt(puntaje_equipo);
        shmdt(turno);
        pthread_mutex_unlock(&mutex2);
        usleep(100 * 1000);
    }

    pthread_exit((void *)"Listo!");
}
