#include <clave.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <unistd.h>

int main()
{
    int i;
    int id_semaforo;

    id_semaforo = creo_semaforo();

    inicia_semaforo(id_semaforo, VERDE);

    while(1)
    {
        espera_semaforo(id_semaforo);
            printf("Seccion critica!");
            sleep(1);
        levanta_semaforo(id_semaforo);
        sleep(10);
    }

    return 0;
}
