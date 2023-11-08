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
    mensaje msg;
    int fin = 0;
    array_type *array = (array_type*) parametro;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    pthread_mutex_lock(&mutex);

    enviar_mensaje(id_cola_mensajes, MSG_ARQUERO, MSG_PATEADOR + array->num_jugador, EVT_TIRO, "");
    usleep(1000 * 1000);
    printf("soy el jugador %d y pateo al arco\n",array->num_jugador + 1);
    while (fin == 0)
    {
        if (recibir_mensaje(id_cola_mensajes, MSG_PATEADOR + array->num_jugador, &msg) != -1)
        {
            procesar_evento_pateador(id_cola_mensajes, msg, array);
            fin = 1;
        }
        usleep(1000);
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}
