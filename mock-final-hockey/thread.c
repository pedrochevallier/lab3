#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <global.h>
#include <unistd.h>
#include <cola.h>
#include <evento.h>
#include <memory.h>

void *funcionThreadE1(void *parametro)
{
    int num_jugador;
    int id_memoria_equipo;
    int id_memoria_puntaje;

    dato *puntaje = NULL;
    equipo *llevo_cuenta = NULL;

    num_jugador = *(int *)parametro;
    puntaje = (dato *)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria_puntaje, CLAVE_BASE);
    llevo_cuenta = (equipo *)creo_memoria(sizeof(equipo), &id_memoria_equipo, CLAVE_BASE + 80);

    pthread_mutex_lock(&mutex1);
    printf("soy el thread %d\n", num_jugador);
    puntaje[0].puntaje++;
    printf("%d\n", puntaje[0].puntaje);
    usleep(200*1000);
    pthread_mutex_unlock(&mutex1);
    

    return 0;
}
void *funcionThreadE2(void *parametro)
{
    int num_jugador;
    int id_memoria_equipo;
    int id_memoria_puntaje;

    dato *puntaje = NULL;
    equipo *llevo_cuenta = NULL;

    num_jugador = *(int *)parametro;
    puntaje = (dato *)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria_puntaje, CLAVE_BASE);
    llevo_cuenta = (equipo *)creo_memoria(sizeof(equipo), &id_memoria_equipo, CLAVE_BASE + 80);

    pthread_mutex_lock(&mutex2);
    printf("soy el thread %d\n", num_jugador);
    puntaje[1].puntaje++;
    printf("%d\n", puntaje[1].puntaje);
    pthread_mutex_unlock(&mutex2);
    usleep(200 * 1000);

    return 0;
}
