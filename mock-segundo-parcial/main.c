#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>

int main(int arg, char *argv[])
{
    pthread_t* idHilo;
    pthread_attr_t atributos;
    int seleccion;
    int cant;
    int i;
    int id_cola_mensajes;
    int id_semaforo;
    insumos insumo[4];

    
    if (arg != 2)
    {
        printf("ERROR - Ingrese cantidad de lineas.");
        return 1;
    }
    
    cant = atoi(argv[1]);
    
    idHilo = (pthread_t* ) malloc(sizeof(pthread_t)*cant);

    strcpy(insumo[0].tipo_insumo, "Madera");
    strcpy(insumo[1].tipo_insumo, "Hojas");
    strcpy(insumo[2].tipo_insumo, "Comida");
    strcpy(insumo[3].tipo_insumo, "Semillas");
    
    for (i = 0; i < 4; i++)
    {
        insumo[i].cant_de_insumo = 0;
        //printf("%s: %d\n",insumo[i].tipo_insumo, insumo[i].cant_de_insumo);
    }

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    id_semaforo = create_semaphore();


    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < cant; i++)
    {
        if (pthread_create(&idHilo[i], &atributos, funcionThread, NULL) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    while (1)
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
            return 0;
        }
    }
}
