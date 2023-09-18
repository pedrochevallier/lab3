#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <clave.h>



int main(int arg, char *argv[])
{
    int id_semaforo;

    FILE *archivo = NULL;


    id_semaforo = create_semaphore();

    while (1)
    {
        semaphore_wait(id_semaforo);
        printf("Semaforo mio\n");
        semaphore_release(id_semaforo);
        usleep(100 * 1000);
    }

    return 0;
}
