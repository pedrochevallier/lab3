#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>
#include <evento.h>

int main(int arg, char *argv[])
{
    pthread_t *idHilo;
    pthread_attr_t atributos;
    int seleccion;
    int cant;
    int i;
    int id_cola_mensajes;
    int id_semaforo;
    int insumo_a_juntar;
    int *hormiga;

    if (arg != 2)
    {
        printf("ERROR - Ingrese cantidad de lineas.");
        return 1;
    }

    cant = atoi(argv[1]);

    finalizar = 0;

    idHilo = (pthread_t *)malloc(sizeof(pthread_t) * cant);
    hormiga = (int *)malloc(sizeof(int) * cant);

    strcpy(insumo[0].tipo_insumo, "Madera");
    strcpy(insumo[1].tipo_insumo, "Hojas");
    strcpy(insumo[2].tipo_insumo, "Comida");
    strcpy(insumo[3].tipo_insumo, "Semillas");

    for (i = 0; i < 4; i++)
    {
        insumo[i].cant_de_insumo = 0;
    }

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < cant; i++)
    {
        hormiga[i] = i;
        if (pthread_create(&idHilo[i], &atributos, funcionThread, &hormiga[i]) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    while (finalizar == 0)
    {
        printf("\nIngrese un  numero:\n1.Madera\n2.Hojas\n3.Comida\n4.Semillas\n0.Salir\n");
        scanf("%d", &seleccion);
        while (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4 && seleccion != 0)
        {
            printf("Seleccion no valida!!\n");
            printf("Ingrese un  numero:\n1.Madera\n2.Hojas\n3.Comida\n4.Semillas\n");
            scanf("%d", &seleccion);
        }
        if (seleccion == 0)
        {
            printf("cerrando...\n");
            for (i = 0; i < cant; i++)
            {
                pthread_mutex_lock(&mutex);
                enviar_mensaje(id_cola_mensajes, MSG_HORMIGA + i, MSG_HORMIGA_REINA, EVT_FIN, -1, "Fin del dia");
                usleep(300 * 1000);
                pthread_mutex_unlock(&mutex);
            }
            usleep(5000000);
        }
        else
        {
            insumo_a_juntar = seleccion - 1;
            i = rand() % cant;
            pthread_mutex_lock(&mutex);
            enviar_mensaje(id_cola_mensajes, MSG_HORMIGA + i, MSG_HORMIGA_REINA, EVT_JUNTAR, insumo_a_juntar, "Juntar");
            pthread_mutex_unlock(&mutex);
        }
        usleep(1000 * 1000);
        for (i = 0; i < 4; i++)
        {
            printf("%s: %d\n", insumo[i].tipo_insumo, insumo[i].cant_de_insumo);
        }
    }
    borrar_mensajes(id_cola_mensajes);
    return 0;
}
