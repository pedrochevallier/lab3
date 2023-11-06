#include <stdlib.h>
#include <stdio.h>
#include <global.h>
#include <cola.h>
#include <string.h>

void procesar_evento_arquero(int id_cola_mensajes, mensaje msg){
    int rand_selection;
    srand(time(NULL));
    switch (msg.int_evento)
    {
    case EVT_TIRO:
        printf("registre un tiro\n");
        rand_selection = (rand()%(4))+2;
        printf("%d al jugador %d\n",rand_selection,msg.int_rte);
        enviar_mensaje(id_cola_mensajes, msg.int_rte, msg.long_dest, rand_selection, "");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}

void procesar_evento_pateador(int id_cola_mensajes, mensaje msg, char *evento){
    printf("%d\n",msg.int_evento);
    switch (msg.int_evento)
    {
    case EVT_GOL:
    sprintf(evento, "GOL");
        printf("GOOOOOOOOOL\n");
        break;
    case EVT_PALO:
        printf("UFFFFFFFF\n");
        break;
    case EVT_TRAVESANO:
        printf("UFFFFF\n");
        break;
    case EVT_FUERA:
        printf("UF\n");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}
