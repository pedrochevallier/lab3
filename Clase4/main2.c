#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <clave.h>
#include <semaforo.h>
#include <gestionarch.h>

typedef struct medicamento medicamento;

struct medicamento
{
    int tipo1;
    int cant1;
    int tipo2;
    int cant2;
    int tipo3;
    int cant3;
};

int main(int arg, char *argv[])
{
    int i;
    int id_semaforo;
    int cant = 0;
    int tipo;
    char fileName[20] = "lote.dat";

    FILE *archivo = NULL;

    medicamento meds;

    meds.tipo1 = 1;
    meds.tipo2 = 2;
    meds.tipo3 = 3;
    meds.cant1 = 0;
    meds.cant2 = 0;
    meds.cant3 = 0;

    id_semaforo = create_semaphore();

    printf("Indique que proceso es (5, 10 o 20): ");
    scanf("%d", &cant);
    while ((cant != 5 && cant != 10) && cant != 20)
    {
        printf("ERROR - Ingrese la cantidad de medicamentos a realizar (5, 10 o 20): ");
        scanf("%d", &cant);
    }

    sprintf(fileName, "lote%d.dat", cant);

    while (1)
    {
        semaphore_wait(id_semaforo);
        if ((archivo = inOpenFile(archivo, "r", fileName)) != NULL)
        {
            tipo = inReadFile(archivo);
            if (tipo == 1)
            {
                meds.cant1++;
            }
            else if (tipo == 2)
            {
                meds.cant2++;
            }
            else if (tipo == 3)
            {
                meds.cant3++;
            }
            if (tipo != 0)
            {
                printf("Medicamento A: %d, Medicamento B: %d, Medicamento C: %d\n", meds.cant1, meds.cant2, meds.cant3);
            }

            truncate(fileName, 0);
            voCloseFile(archivo);
        }
        else
        {
            archivo = inOpenFile(archivo, "w", fileName);
        }

        semaphore_release(id_semaforo);
        usleep(100 * 1000);
    }

    return 0;
}
