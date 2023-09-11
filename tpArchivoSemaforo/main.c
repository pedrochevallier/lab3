#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>

int main(int arg, char *argv[])
{
    int id_semaforo;
    int vuelo;
    char destino[30+1];
    char nombre[30+1];

    id_semaforo = creo_semaforo();

    inicia_semaforo(id_semaforo, VERDE);

    while (1)
    {
        espera_semaforo(id_semaforo);
        printf("Ingrese el numero de vuelo: ");
        scanf("%d", &vuelo);
        while (vuelo!=0){
            /*inserto un scanf que atrapa el salto de linea dejado por el scanf anterior*/
            scanf("%*c");
            printf("Ingrese destino: ");
            fgets(destino, sizeof(destino), stdin);
            
            printf("Ingrese nombre pasajero: ");
            fgets(nombre, sizeof(nombre), stdin);

            printf("Se ingreso el vuelo %d",vuelo);

            printf("\nIngrese el numero de vuelo: ");
            scanf("%d", &vuelo);
            
        }
        sleep(1);
        levanta_semaforo(id_semaforo);
        sleep(10);
    }

    return 0;
}
