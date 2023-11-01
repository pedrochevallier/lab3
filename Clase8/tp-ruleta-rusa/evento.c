#include <stdio.h>
#include <global.h>

void procesar_evento_revolver(int id_cola_mensajes, mensaje msg)
{
    switch (msg.int_evento)
    {
    case EVT_DISPARO:
        printf("El jugador n disparo la bala m: \n");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}
