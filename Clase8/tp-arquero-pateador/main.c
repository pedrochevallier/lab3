#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>
#include <evento.h>

int main(int arg, char *argv[])
{
    pthread_attr_t atributos;

    mensaje msg;
    int id_cola_mensajes;

    int cant_tiros = 0;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    borrar_mensajes(id_cola_mensajes);


    while(cant_tiros < 5){

        if(recibir_mensaje(id_cola_mensajes, MSG_ARQUERO, &msg) != -1){
            pthread_mutex_lock(&mutex);
            procesar_evento_arquero(id_cola_mensajes, msg);
            cant_tiros ++;
            pthread_mutex_unlock(&mutex);
        }
    usleep(1000);
    }
   
    
    return 0;
}
