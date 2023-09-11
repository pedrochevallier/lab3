#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <clave.h>
#include <semaforo.h>

int main(int arg, char *argv[])
{
    int i;
    int id_semaforo;

    id_semaforo = creo_semaforo();

    while (1)
    {
        espera_semaforo(id_semaforo);
        printf("Seccion critica2!\n");
        sleep(1);
        levanta_semaforo(id_semaforo);
        sleep(10);
    }

    return 0;
}
