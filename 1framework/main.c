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

int main(int arg, char *argv[])
{
    mensaje msg;
    array_type *array;
    int id_cola_mensajes;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    borrar_mensajes(id_cola_mensajes);
    
    array = (array_type *)malloc(sizeof(array_type) * CANT);

    if (recibir_mensaje(id_cola_mensajes, MSG_ARQUERO, &msg) != -1)
    {
        pthread_mutex_lock(&mutex);

        procesar_evento_arquero(id_cola_mensajes, msg);

        pthread_mutex_unlock(&mutex);
    }

    msgctl(id_cola_mensajes, IPC_RMID, NULL);
    
    return 0;
}
