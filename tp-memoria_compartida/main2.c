#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <key.h>
#include <memory.h>
#include <time.h>
#include <global.h>
#include <semaforo.h>

#define DESDE 40000
#define HASTA 60000

int main(int arg, char *argv[])
{

	int id_memoria;
	int id_semaforo;
	dato *memoria = NULL;
	int i, aleatorio;
	int cant = 0;
	int min_cant = 0;
	int via;

	if (arg != 2)
	{
		printf("ERROR - Ingrese cantidad de lineas.");
		return 1;
	}

	cant = atoi(argv[1]);

	id_semaforo = create_semaphore();

	memoria = (dato *)creo_memoria(sizeof(dato) * cant, &id_memoria);

	while (1)
	{
		semaphore_wait(id_semaforo);

		min_cant = memoria[0].vehiculos_en_cola;
		via = 0;

		for (i = 0; i < cant; i++)
		{
			if (memoria[i].vehiculos_en_cola < min_cant)
			{
				min_cant = memoria[i].vehiculos_en_cola;
				via = i;
			}
		}
		memoria[via].vehiculos_en_cola++;

		semaphore_release(id_semaforo);

		aleatorio = rand() % (HASTA - DESDE) + DESDE;
		usleep(aleatorio);
	}

	shmdt((char *)memoria);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}
