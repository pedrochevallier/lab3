#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <clave.h>

int main()
{
    int i;
    int id_semaforo;

    id_semaforo = creo_semaforo();

    inicia_semaforo(id_semaforo, VERDE);

    while (1)
    {
        espera_semaforo(id_semaforo);
        printf("Seccion critica!\n");
        sleep(1);
        levanta_semaforo(id_semaforo);
        sleep(2);
    }

    return 0;
}
