#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <memory.h>
#include <global.h>
#include <semaforo.h>

#define DESDE 40000
#define HASTA 300000

int main(int arg, char *argv[])
{
	int id_memoria;
	dato *memoria = NULL;
	int cant;
	int i, j, k;
	int id_semaforo;
	int aleatorio;

	if (arg != 2)
	{
		printf("ERROR - Ingrese cantidad de lineas.");
		return 1;
	}

	cant = atoi(argv[1]);

	id_semaforo = create_semaphore();

	init_semaphore(id_semaforo, VERDE);

	memoria = (dato *)creo_memoria(sizeof(dato) * cant, &id_memoria);

	for (i = 0; i < cant; i++)
	{
		memoria[i].vehiculos_en_cola = 0;
	}

	while (1)
	{

		for (i = 0; i < cant; i++)
		{
			semaphore_wait(id_semaforo);
			system("clear");
			for (j = 0; j < cant; j++)
			{
				printf("Fila %d: ", j);
				for (k = 0; k < memoria[j].vehiculos_en_cola; k++)
				{
					printf("| ");
				}
				printf("\n");
			}

			if (memoria[i].vehiculos_en_cola > 0 && memoria[i].vehiculos_en_cola < 10)
			{
				memoria[i].vehiculos_en_cola--;
			}
			else if (memoria[i].vehiculos_en_cola >= 10)
			{
				memoria[i].vehiculos_en_cola = 0;
			}
			semaphore_release(id_semaforo);
			aleatorio = rand() % (HASTA - DESDE) + DESDE;
			usleep(aleatorio);
		}
	}

	shmdt((char *)memoria);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}
