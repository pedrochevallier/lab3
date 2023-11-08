#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>
#include <evento.h>
#include <semaforo.h>

void *funcionThread(void *parametro)
{
    int id_cola_mensajes;

    int i = 0;
    int id_semaforo;
    int presidente;
    int vice;

    srand(time(NULL));

    // creo la cola de mensajes
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    id_semaforo = create_semaphore();

    while (i < CANT_VOTOS)
    {
        semaphore_wait(id_semaforo);

        // elijo presidente y vicepresidente al azar
        presidente = (rand() % (2));
        vice = (rand() % (2));

        // envio el voto
        enviar_mensaje(id_cola_mensajes, MSG_PANEL, MSG_VOTANTE, EVT_VOTO, presidente, vice);
        printf("Vote por ");
        if(presidente == 0){
            printf("señor MS y ");
        }
        else if (presidente == 1)
        {
            printf("señor MI y ");
        }

        if(vice == 0){
            printf("señor A\n");
        }
        else if (vice == 1)
        {
            printf("señora V\n");
        }
        semaphore_release(id_semaforo);

        usleep(1000 * 100);

        i++;
    }

    return 0;
}
