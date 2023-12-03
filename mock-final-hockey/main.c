#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <global.h>
#include <thread.h>
#include <string.h>
#include <semaforo.h>
#include <cola.h>
#include <evento.h>
#include <sys/msg.h>
#include <memory.h>

#define CANTIDAD 2


int main(int arg, char *argv[])
{
	pthread_t *idHilo;
	pthread_attr_t atributos;

	dato *puntaje = NULL;
	arranca *com = NULL;
	equipo *llevo_cuenta = NULL;

	int id_memoria_puntaje;
	int id_memoria_com;
	int id_memoria_equipo;

	int *jugador;

	int i = 0;
	int cant = 5;

	puntaje = (dato *)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria_puntaje, CLAVE_BASE);
	com = (arranca *)creo_memoria(sizeof(arranca), &id_memoria_com, CLAVE_BASE + 40);
	llevo_cuenta = (equipo *)creo_memoria(sizeof(equipo), &id_memoria_equipo, CLAVE_BASE + 80);
	
	idHilo = (pthread_t *)malloc(sizeof(pthread_t) * 5);
	pthread_mutex_init(&mutex1, NULL);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	jugador = (int *)malloc(sizeof(int) * 5);

	// inicializacion de estructuras
	puntaje[0].numero_equipo = 1;
	puntaje[0].puntaje = 0;
	// indico quien debe comenzar el partido y que jugador le corresponde patear
	llevo_cuenta->equipo1 = 1; //empieza pateando el equipo 1
	llevo_cuenta->equipo2 = 0;
	llevo_cuenta->jugador_e_1 = 1;
	llevo_cuenta->jugador_e_2 = 1;
	// indico que este proceso comenzo
	com->equipo1 = 1;


	for (i = 0; i < cant; i++)
	{
		jugador[i] = i;
		if (pthread_create(&idHilo[i], &atributos, funcionThreadE1, &jugador[i]) != 0)
		{
			perror("No puedo crear thread");

			shmdt((char *)com);
			shmctl(id_memoria_com, IPC_RMID, (struct shmid_ds *)NULL);

			exit(-1);
		}
	}
	//printf("el equipo %d comenzo con %d\n", puntaje[0].numero_equipo, com->equipo1);

	for (i = 0; i < cant; i++)
    {
        pthread_join(idHilo[i], NULL);
    }

	shmdt((char *)com);
	shmctl(id_memoria_com, IPC_RMID, (struct shmid_ds *)NULL);

	return 0;
}
