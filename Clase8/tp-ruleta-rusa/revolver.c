#include <unistd.h>
#include <global.h>
#include <stdio.h>
#include <stdlib.h>
#include <evento.h>
#include <cola.h>
#include <semaforo.h>
#include <time.h>

int main(int arg, char *argv[])
{
    int i;
    int cant_jugadores = CANTIDAD_JUGADORES;
    int random_num;
    int id_cola_mensajes;
    int id_semaforo;
    mensaje msg;

    srand(time(NULL));
    random_num = (rand() % 6) + 1;
    printf("numero elegido: %d\n", random_num);

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    id_semaforo = create_semaphore();

    borrar_mensajes(id_cola_mensajes);
    
    init_semaphore(id_semaforo, VERDE);

    for(i=0;i<cant_jugadores;i++){
        enviar_mensaje(id_cola_mensajes, MSG_JUGADOR, MSG_REVOLVER+i, EVT_INICIO, "");
    }
    
    while (1)
    {
        recibir_mensaje(id_cola_mensajes, MSG_REVOLVER, &msg);
        procesar_evento_revolver(id_cola_mensajes, msg);
    };
    
    return 0;
}
