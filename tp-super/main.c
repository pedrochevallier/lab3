#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

/*Declare struct defined in gestionarch*/
struct orden orders[50];

int main(int arg, char *argv[])
{
    int semaphore_id;
    int i = 0;
    int j = 0;

    FILE *file = NULL;

    semaphore_id = create_semaphore();

    init_semaphore(semaphore_id, VERDE);

    file = inOpenFile(file, "w", "orders.csv");
    voCloseFile(file);

    while (1)
    {
        orders[i].id = i;
        printf("Ingrese el precio: ");
        scanf("%d", &orders[i].price);

        while (orders[i].price != 0)
        {
            /*catch new line left by scanf*/
            scanf("%*c");
            printf("Ingrese descripcion: ");
            /*IMPORTANT*/
            memset(orders[i].description, 0x00, sizeof(orders[i].description));
            scanf("%[^\n]", orders[i].description);

            i++;

            orders[i].id = i;
            printf("Ingrese precio: ");
            scanf("%d", &orders[i].price);
        }

        semaphore_wait(semaphore_id);
        file = inOpenFile(file, "w", "orders.csv");
        for (j = 0; j < i; j++)
        {
            /*pass file and order struct to function*/
            voWriteFile(file, orders[j]);
        }
        /*reset i*/
        i = 0;
        /*Close file*/
        voCloseFile(file);
        semaphore_release(semaphore_id);
        usleep(100 * 1000);
    }
    return 0;
}
