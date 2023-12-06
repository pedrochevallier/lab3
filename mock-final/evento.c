#include <stdlib.h>
#include <stdio.h>
#include <global.h>
#include <cola.h>
#include <string.h>

void procesar_evento_arquero(int id_cola_mensajes, mensaje msg)
{
    int rand_selection = 0;
    srand(time(NULL));
    switch (msg.int_evento)
    {
    case EVT_TIRO:
        rand_selection = (rand() % 2) + 1;
        enviar_mensaje(id_cola_mensajes, msg.int_rte, msg.long_dest, rand_selection, "");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
}

void procesar_evento_pateador(int id_cola_mensajes, mensaje msg, puntaje *thread_data, int num_equipo)
{
    switch (msg.int_evento)
    {
    case EVT_GOL:               
        printf("GOOOOOOOOOL\n");
        thread_data[num_equipo].puntos = thread_data[num_equipo].puntos + 1;
        break;
    default:
        printf("No fue gol\n");
        break;
    }
    printf("------------------------------\n");
}
