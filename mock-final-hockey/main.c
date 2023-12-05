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

int main(int arg, char *argv[])
{
	pthread_t *idHilo;
	pthread_attr_t atributos;

	dato *punt = NULL;

	int id_memoria_puntaje;
	
	int i = 0;
	int cant = 20;

	idHilo = (pthread_t *)malloc(sizeof(pthread_t) * cant);

	punt = (dato *)creo_memoria(sizeof(dato), &id_memoria_puntaje, CLAVE_BASE);
	
	
	pthread_mutex_init(&mutex, NULL);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);


	// inicializacion de estructuras
	punt->numero_equipo = 1;
	punt->puntaje = 0;


	printf("Puntaje antes de crear thread: %d\n", punt->puntaje);
	for (i = 0; i < cant; i++)
	{
		if (pthread_create(&idHilo[i], &atributos, funcionThread, NULL) != 0)
		{
			perror("No puedo crear thread");
			exit(-1);
		}
	}

	for (i = 0; i < cant; i++)
	{
		if (pthread_join(idHilo[i], NULL) != 0)
		{
			fprintf(stderr, "Error joining thread %d\n", i);
			return 1;
		}
	}
	printf("Puntaje despues de crear thread: %d\n", punt->puntaje);

	shmdt((char *)punt);
	shmctl(id_memoria_puntaje, IPC_RMID, (struct shmid_ds *)NULL);
	free(idHilo);

	return 0;
}
