#include <stdlib.h>
#include <stdio.h>
#include <global.h>
#include <cola.h>
#include <string.h>

void procesar_evento_arquero(int id_cola_mensajes, mensaje msg)
{
    srand(time(NULL));
    switch (msg.int_evento)
    {
    case EVT_GOL:
        enviar_mensaje(id_cola_mensajes, msg.int_rte, msg.long_dest, 2, "");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}

void procesar_evento_pateador(int id_cola_mensajes, mensaje msg, void *thread_data)
{
    array_type *datos_thread = (array_type*) thread_data;
    switch (msg.int_evento)
    {
    case EVT_GOL:
        strncpy(datos_thread->evento, "GOL", sizeof(datos_thread->evento));
        datos_thread->evento[sizeof(datos_thread->evento) - 1] = '\0';
        printf("GOOOOOOOOOL\n");
        break;
    /*case EVT_PALO:
        sprintf(datos_thread->evento, "PALO");
        printf("UFFFFFFFF\n");
        break;
    case EVT_TRAVESANO:
        sprintf(datos_thread->evento, "TRAVESANO");
        printf("UFFFFF\n");
        break;
    case EVT_FUERA:
        sprintf(datos_thread->evento, "FUERA");
        printf("UF\n");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;*/
    }
    printf("------------------------------\n");
}
