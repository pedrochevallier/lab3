#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>
#include <evento.h>

void *funcionThread(void *parametro)
{
    int id_cola_mensajes;
    int num_jugador;
    mensaje msg;
    int fin = 0;
    data *datos_thread = (data*) parametro;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    pthread_mutex_lock(&mutex);

    enviar_mensaje(id_cola_mensajes, MSG_ARQUERO, MSG_PATEADOR + datos_thread->num_jugador, EVT_TIRO, "");
    usleep(1000 * 1000);
    printf("soy el jugador %d y estoy esperando un mensaje\n", MSG_PATEADOR + datos_thread->num_jugador);
    while (fin == 0)
    {
        if (recibir_mensaje(id_cola_mensajes, MSG_PATEADOR + datos_thread->num_jugador, &msg) != -1)
        {
            procesar_evento_pateador(id_cola_mensajes, msg, &datos_thread);
            fin = 1;
        }
        usleep(1000);
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}
