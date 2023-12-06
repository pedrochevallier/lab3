#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <pthread.h>

#define CLAVE 33

typedef struct tipo_dato dato;
struct tipo_dato
{
	int numero_equipo;
	int puntos;
};

pthread_mutex_t mutex;

// creo la clave para la memoria
key_t creo_clave(int r_clave)
{

	key_t clave;
	clave = ftok("/bin/ls", r_clave);
	if (clave == (key_t)-1)
	{
		printf("No puedo conseguir clave para memoria compartida\n");
		exit(0);
	}
	return clave;
}

// creo la memoria compartida
void *creo_memoria(int size, int *r_id_memoria, int clave_base)
{
	void *ptr_memoria;
	int id_memoria;
	id_memoria = shmget(creo_clave(clave_base), size, 0666 | IPC_CREAT);

	if (id_memoria == -1)
	{

		printf("No consigo id para memoria compartida\n");
		exit(0);
	}

	ptr_memoria = (void *)shmat(id_memoria, (char *)0, 0);

	if (ptr_memoria == NULL)
	{
		printf("No consigo memoria compartida\n");

		exit(0);
	}
	*r_id_memoria = id_memoria;
	return ptr_memoria;
}

// funcion del thread, aca es donde rompe
void *funcionThread(void *parametro)
{
	int id_memoria_puntaje;
	int num_thread;
	dato *puntaje = NULL;
	num_thread = *(int *)parametro;
	puntaje = (dato *)creo_memoria(sizeof(dato), &id_memoria_puntaje, CLAVE);
	printf("%d\n", &puntaje);

	pthread_mutex_lock(&mutex);

	printf("numero de thread: %d\n", num_thread);
	// aca rompe, cuando quiero leer o escribir en memoria compartida
	// siempre corre 7 veces y salta segmentation fault
	puntaje->puntos = puntaje->puntos + 1;
	printf("%d\n", puntaje->puntos);

	pthread_mutex_unlock(&mutex);
	usleep(100 * 1000);
	shmdt(puntaje);
	pthread_exit((void *)"Listo");
}

int main(int arg, char *argv[])
{
	pthread_t *idHilo;
	pthread_attr_t atributos;

	dato *puntaje = NULL;

	int id_memoria_puntaje;

	int i;
	int *thread;
	int cant = 20; // cantidad de threads

	idHilo = (pthread_t *)malloc(sizeof(pthread_t) * cant);
	thread = (int *)malloc(sizeof(int) * cant);

	puntaje = (dato *)creo_memoria(sizeof(dato), &id_memoria_puntaje, CLAVE);

	pthread_mutex_init(&mutex, NULL);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	// inicializacion de estructura
	puntaje->numero_equipo = 0;
	puntaje->puntos = 0;

	printf("Puntaje antes de crear thread: %d\n", puntaje->puntos);
	// creo los threads
	for (i = 0; i < cant; i++)
	{
		thread[i] = i;
		if (pthread_create(&idHilo[i], &atributos, funcionThread, &thread[i]) != 0)
		{
			perror("No puedo crear thread");
			exit(-1);
		}
		usleep(100 * 1000);
	}

	// espero a que los threads terminen
	for (i = 0; i < cant; i++)
	{
		if (pthread_join(idHilo[i], NULL) != 0)
		{
			fprintf(stderr, "Error joining thread %d\n", i);
			return 1;
		}
	}
	printf("Puntaje despues de crear thread: %d\n", puntaje->puntos);

	// limpio la memoria
	shmdt((char *)puntaje);
	shmctl(id_memoria_puntaje, IPC_RMID, (struct shmid_ds *)NULL);
	free(idHilo);

	return 0;
}
