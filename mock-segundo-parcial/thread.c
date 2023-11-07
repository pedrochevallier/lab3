#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>
#include <evento.h>

void *funcionThread(void *parametro)
{
    int id_cola_mensajes;
    mensaje_hormiga msg;
    int num_hormiga;
    int juntar = 0;
    int insumo_a_juntar;
    int i = 0;
    int recepcion;
    num_hormiga = *(int *)parametro;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    printf("Soy la hormiga %d y tengo el numero %d\n", num_hormiga, MSG_HORMIGA + num_hormiga);
    while (finalizar == 0)
    {
        recepcion = recibir_mensaje(id_cola_mensajes, MSG_HORMIGA + num_hormiga, &msg);
        // printf("la respuesta de recibir_mensaje fue: %d\n", recepcion);
        if (recepcion != -1)
        {
            procesar_evento_hormiga(id_cola_mensajes, msg, &juntar, &insumo_a_juntar);
        }
        if (juntar == 1)
        {
            insumo[insumo_a_juntar].cant_de_insumo = insumo[insumo_a_juntar].cant_de_insumo + (rand() % (4 - 1) + 1);
            // enviar_mensaje(id_cola_mensajes, MSG_HORMIGA_REINA, MSG_HORMIGA + num_hormiga, EVT_RTA_JUNTAR, -1, "junte");
            for (i = 0; i < 4; i++)
            {
                if (insumo[i].cant_de_insumo > 90)
                {
                    finalizar = 1;
                }
            }
        }

        usleep(1000 * 1000);
    }

    pthread_exit((void *)"Listo");
}
