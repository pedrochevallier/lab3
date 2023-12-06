#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <key.h>

key_t creo_clave(int r_clave)
{

	key_t clave;
	clave = ftok ("/bin/ls", r_clave);	
	if (clave == (key_t)-1)
	{
		printf("No puedo conseguir clave para memoria compartida\n");
		exit(0);
	}
	return clave;
}
