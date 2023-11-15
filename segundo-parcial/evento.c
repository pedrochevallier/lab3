#include <stdlib.h>
#include <stdio.h>
#include <global.h>
#include <cola.h>

void procesar_evento_panel(int id_cola_mensajes, mensaje msg, void *event_data, int *cont)
{
    votos *dato = (votos*) event_data;

    switch (msg.int_evento)
    {
    case EVT_VOTO:
        
        printf("recibi un voto\n");
        (*cont) ++;
        if(msg.presidente == 0){
            dato->presidente1 ++;
        }
        else if (msg.presidente == 1)
        {
            dato->presidente2 ++;
        }

        if(msg.vice_presidente == 0){
            dato->vice1 ++;
        }
        else if (msg.vice_presidente == 1)
        {
            dato->vice2 ++;
        }
        
        break;
    default:
        break;
    }
}

int procesar_evento_votante(int id_cola_mensajes, mensaje msg)
{

    switch (msg.int_evento)
    {
    case EVT_INICIO:
        return 1;
        break;
    default:
        return 0;
    }
    printf("------------------------------\n");
}
