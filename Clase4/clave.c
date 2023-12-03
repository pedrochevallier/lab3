#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <clave.h>

key_t creo_clave(int clave_base)
{
    key_t clave;

    clave = ftok("/bin/ls", clave_base);
    if (clave == (key_t)-1)
    {
        printf("No puedo conseguir clave semaforo, mem compartida, etc.\n");
        exit(0);
    }
    return clave;
}
