#include <stdlib.h>
#include <stdio.h>
#include <global.h>

void procesar_evento_hormiga(int id_cola_mensajes, mensaje_hormiga msg, int *juntar, int *insumo_a_juntar){
    switch (msg.int_evento)
    {
    case EVT_JUNTAR:
        *juntar = 1;
        *insumo_a_juntar = msg.insumo;
        printf("Me mandaron a juntar\n");
        break;
    case EVT_PARAR:
        *juntar = 0;
        printf("Me ordenaron parar\n");
        break;
    case EVT_FIN:
        printf("Termino el dia\n");
        finalizar = 1;
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}

void procesar_evento_reina(int id_cola_mensajes, mensaje_hormiga msg){
    switch (msg.int_evento)
    {
    case EVT_RTA_JUNTAR:
        printf("Respondio la hormiga\n");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}
