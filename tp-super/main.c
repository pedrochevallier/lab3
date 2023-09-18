#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

struct orden ordenes[50];

int main(int arg, char *argv[])
{
    int id_semaforo;
    int i = 0;
    int j = 0;

    FILE *archivo = NULL;

    id_semaforo = creo_semaforo();

    inicia_semaforo(id_semaforo, VERDE);

    while (1)
    {
        printf("Ingrese el precio: ");
        scanf("%d", &ordenes[i].price);

        while (ordenes[i].price != 0)
        {
            /*catch new line left by scanf*/
            scanf("%*c");
            printf("Ingrese descripcion: ");
            scanf("%[^\n]", ordenes[i].description);

            i++;

            printf("Ingrese precio: ");
            scanf("%d", &ordenes[i].price);
        }

        espera_semaforo(id_semaforo);
        archivo = inAbrirArchivo(archivo, "w", "orders.csv");
        for (j = 0; j < i; j++)
        {
            voEscribirArchivo(archivo, ordenes[j]);
        }
        i = 0;
        voCerrarArchivo(archivo);
        levanta_semaforo(id_semaforo);
        usleep(100 * 1000);
    }
    return 0;
}
