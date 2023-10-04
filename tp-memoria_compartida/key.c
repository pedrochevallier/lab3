#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <key.h>

#define CLAVE_BASE 33

key_t creo_clave(void)
{

	key_t clave;
	clave = ftok ("/bin/ls", CLAVE_BASE);	
	if (clave == (key_t)-1)
	{
		printf("No puedo conseguir clave para memoria compartida\n");
		exit(0);
	}
	return clave;
}
