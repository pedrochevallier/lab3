#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>
#include <evento.h>

int main(int arg, char *argv[])
{
    mensaje msg;
    int gol;
    int goles = 0;
    int i;
    s_gol *j_gol;
    int id_cola_mensajes;
    int cant_tiros = 0;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    borrar_mensajes(id_cola_mensajes);
    j_gol = (s_gol *)malloc(sizeof(s_gol) * CANT_JUGADORES);

    while (cant_tiros < 5)
    {

        if (recibir_mensaje(id_cola_mensajes, MSG_ARQUERO, &msg) != -1)
        {
            pthread_mutex_lock(&mutex);
            gol = procesar_evento_arquero(id_cola_mensajes, msg, &j_gol[cant_tiros]);
            if(gol == 2){
                goles ++;
                j_gol[cant_tiros].gol = 1;
                j_gol[cant_tiros].jugador = cant_tiros + 1;
            }
            cant_tiros++;
            pthread_mutex_unlock(&mutex);
        }
        usleep(1000);
    }
    printf("Se hicieron %d goles\n", goles);
    for(i=0;i<CANT_JUGADORES;i++){
        if(j_gol[i].gol == 1){
            printf("Jugador %d hizo gol\n",j_gol[i].jugador);
        }
    }
    return 0;
}
