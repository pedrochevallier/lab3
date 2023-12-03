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
	int id_memoria_puntaje;
	int id_memoria_com;
	dato *puntaje = NULL;
	arranca *com = NULL;

	int *jugador;

	int i = 0;
	int cant = 5;

	puntaje = (dato *)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria_puntaje, CLAVE_BASE);
	com = (arranca *)creo_memoria(sizeof(arranca), &id_memoria_com, CLAVE_BASE + 40);

	idHilo = (pthread_t *)malloc(sizeof(pthread_t) * 5);
	pthread_mutex_init(&mutex2, NULL);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	jugador = (int *)malloc(sizeof(int) * 5);

	puntaje[1].numero_equipo = 2;
	puntaje[1].puntaje = 0;
	// indico que este proceso comenzo
	com->equipo2 = 1;

	while (com->equipo1 != 1)
	{
		usleep(10000);
	}

	for (i = 0; i < cant; i++)
	{
		jugador[i] = i;
		if (pthread_create(&idHilo[i], &atributos, funcionThreadE2, &jugador[i]) != 0)
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
