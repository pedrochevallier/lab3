#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <cola.h>
#include <evento.h>

int main(int arg, char *argv[])
{
    pthread_t idHilo;
    pthread_attr_t atributos;

    mensaje msg;

    int inicio = 0;
    int no_inicio = 0;
    int id_cola_mensajes;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    // inicializo el mutex
    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    printf("Inicializando\n");

    // espero a recibir confirmacion de que el proceso que cuenta los votos inicio
    while (inicio == 0)
    {
        if (recibir_mensaje(id_cola_mensajes, MSG_VOTANTE, &msg) != -1)
        {
            inicio = procesar_evento_votante(id_cola_mensajes, msg);
            usleep(1000 * 100);
        }
        // si no recibio mensaje entonces aumento el contador en 1
        no_inicio ++;

        usleep(1000 * 100);

        // si pasados 3 segundos no recibe el mensaje el proceso informa que se debe correr main primero
        if(no_inicio == 30){
            printf("debe iniciar el proceso MAIN antes que este\n");
            return 0;
        }
    }
    printf("\n");
    if (pthread_create(&idHilo, &atributos, funcionThread, NULL) != 0)
    {
        perror("No puedo crear thread");
        exit(-1);
    }

    pthread_join(idHilo, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}
