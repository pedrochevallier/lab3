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
    int minimum_items;
    int maximum_items;

    char fileName[20] = "orders.csv";

    FILE *archivo = NULL;

    if (arg != 3)
    {
        printf("Ingrese dos parametros, uno de minimo de items y otro de maximo de items.");
        return 1;
    }

    minimum_items = atoi(argv[1]);
    maximum_items = atoi(argv[2]);

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

            /*If the numbers of items corresponds, process file. If not pass and release*/
            if (i >= minimum_items && i <= maximum_items)
            {
                /*rewind file pointer*/
                rewind(archivo);
                
                /*get the sum of column*/
                sum = inReadFile(archivo);
                
                printf("El total de la compra es: %d\n", sum);

                /*clean file*/
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
