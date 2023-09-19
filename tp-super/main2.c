#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <clave.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    int id_semaforo;
    int i = 0;
    int sum = 0;

    char fileName[20] = "orders.csv";

    FILE *archivo = NULL;

    id_semaforo = create_semaphore();

    while (1)
    {
        semaphore_wait(id_semaforo);

        if ((archivo = inOpenFile(archivo, "r", fileName)) == NULL)
        {
            semaphore_release(id_semaforo);
        }
        else
        {
            i = getCant(archivo);
            if (i >= 1 && i <= 3)
            {
                printf("Cantidad de registros en el archivo: %d\n", i);
                rewind(archivo);
                sum = inReadFile(archivo);
                truncate(fileName, 0);
                voCloseFile(archivo);
                semaphore_release(id_semaforo);
            }
            else
            {
                voCloseFile(archivo);
                semaphore_release(id_semaforo);
            }
        }

        usleep(100 * 1000);
    }

    return 0;
}
