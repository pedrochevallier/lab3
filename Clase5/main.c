#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <memory.h>

#define CANTIDAD 10
#define CANTIDAD_TOTAL 10

#define CLAVE_BASE 33

typedef struct tipo_dato dato;

struct tipo_dato
{
	int numero;
	char letra;
};

int main(int arg, char *argv[])
{
	int id_memoria;
	dato *memoria = NULL;

	int i;

	memoria = (dato *)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria, CLAVE_BASE);

	while (1)
	{
		printf("leemos la memoria\n");
		for (i = 0; i < CANTIDAD; i++)
		{
			printf("Leido %d %c\n", memoria[i].numero, memoria[i].letra);
		}
		printf("Dejamos de leer la memoria\n");
		sleep(1);
	}

	shmdt((char *)memoria);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}
