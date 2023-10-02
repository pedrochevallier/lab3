#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <key.h>
#include <memory.h>
#include <time.h>

#define CANTIDAD 10
#define CANTIDAD_TOTAL 10
#define DESDE 0
#define HASTA 25

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
	int i, aleatorio;

	memoria = (dato*)creo_memoria(sizeof(dato)*CANTIDAD, &id_memoria, CLAVE_BASE);

	srand(time(NULL));

	while(1)
	{
		printf("Escribimos en la memoria\n");
		for (i=0; i<CANTIDAD; i++)
		{
			aleatorio = rand()%(HASTA-DESDE)+DESDE;
			memoria[i].numero = aleatorio ;
			memoria[i].letra  = 0x41 + aleatorio ;
			printf("Escrito %d %c\n", memoria[i].numero, memoria[i].letra);
			sleep (1);
		}
		printf("Dejamos de escribir en la memoria\n");
		sleep (10);
	}
	
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}
