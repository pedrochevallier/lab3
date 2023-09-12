#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    int id_semaforo;
    int vuelo;
    char destino[30 + 1];
    char nombre[30 + 1];
    char fileName[] = "lote.dat";

    FILE *file = NULL;
    FILE *newFile = NULL;

    file = inAbrirArchivo(file, "w", fileName);

    id_semaforo = creo_semaforo();
    
    inicia_semaforo(id_semaforo, VERDE);

    while (1)
    {
        espera_semaforo(id_semaforo);
        printf("Ingrese el numero de vuelo: ");
        scanf("%d", &vuelo);
        while (vuelo != 0)
        {
            /*inserto un scanf que atrapa el salto de linea dejado por el scanf anterior*/
            scanf("%*c");
            printf("Ingrese destino: ");
            scanf("%[^\n]", destino);
            
            /*inserto un scanf que atrapa el salto de linea dejado por el scanf anterior*/
            scanf("%*c");
            printf("Ingrese nombre pasajero: ");
            scanf("%[^\n]", nombre);

            printf("Se ingreso el vuelo %d", vuelo);

            voEscribirArchivo(file, vuelo, destino, nombre);
            printf("\nIngrese el numero de vuelo: ");
            scanf("%d", &vuelo);
        }
        voCerrarArchivo(file);

        levanta_semaforo(id_semaforo);
        sleep(10);
    }

    return 0;
}
