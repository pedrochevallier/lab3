#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <cola.h>
#include <evento.h>
#include <sys/msg.h>
#include <semaforo.h>

int main(int arg, char *argv[])
{
    mensaje msg;
    votos s_votos = {0};
    int id_cola_mensajes;
    int id_semaforo;
    int votos = 0;

    // inicializo la cola de mensajes
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    // borro los mensajes existentes
    borrar_mensajes(id_cola_mensajes);

    // creo el id de semaforo
    id_semaforo = create_semaphore();
    // inicializo el semaforo
    init_semaphore(id_semaforo, VERDE);

    // envio un mensaje para que el otro proceso sepa que ya se pueden mandar votos
    enviar_mensaje(id_cola_mensajes, MSG_VOTANTE, MSG_PANEL, EVT_INICIO, -1, -1);

    while (votos < CANT_VOTOS)
    {
        semaphore_wait(id_semaforo);

        if (recibir_mensaje(id_cola_mensajes, MSG_PANEL, &msg) != -1)
        {
            procesar_evento_panel(id_cola_mensajes, msg, &s_votos, &votos);
        }
        system("clear");
        printf("Votos para señor MS: %d\nVotos para señor MI: %d\n\nVotos para señor A: %d\nVotos para señora V: %d\n", s_votos.presidente1, s_votos.presidente2, s_votos.vice1, s_votos.vice2);
        
        semaphore_release(id_semaforo);
        usleep(1000 * 100);
    }

    // elimino la cola de mensajes
    msgctl(id_cola_mensajes, IPC_RMID, NULL);

    return 0;
}
