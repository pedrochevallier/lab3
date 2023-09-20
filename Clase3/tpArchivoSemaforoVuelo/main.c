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

    id_semaforo = create_semaphore();
    
    init_semaphore(id_semaforo, VERDE);

    while (1)
    {
        printf("\n Ingresando nuevo lote \n");
        printf("Ingrese el numero de vuelo: ");
        scanf("%d", &vuelo);
        while ((vuelo < 1000 || vuelo > 1010))
        {
            printf("Error - Ingrese el numero de vuelo: ");
            scanf("%d", &vuelo);
        }
        
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

            semaphore_wait(id_semaforo);

            file = inOpenFile(file, "w", fileName);
            voWriteFile(file, vuelo, destino, nombre);
            voCloseFile(file);

            printf("Se ingreso el vuelo %d \n", vuelo);
            
            semaphore_release(id_semaforo);
            
            printf("Ingrese el numero de vuelo: saraza");
            scanf("%d", &vuelo);
            while ((vuelo < 1000 || vuelo > 1010) && vuelo != 0)
            {
                printf("Error - Ingrese el numero de vuelo: adentro while");
                scanf("%d", &vuelo);
            }
        }
    }

    return 0;
}
