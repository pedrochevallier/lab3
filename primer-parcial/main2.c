#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    int id_semaforo;
    int tipoAlumno;
    int cant = 0;
    int newCant = 0;

    char fileName[SIZE] = "alumnos.csv";

    FILE *archivo = NULL;

    if (arg != 2)
    {
        printf("ERROR - Ingrese que tipo de alumno desea procesar, 1 para inicial, 2 para transferencia.");
        return 1;
    }

    tipoAlumno = atoi(argv[1]);

    if (tipoAlumno != 1 && tipoAlumno != 2)
    {
        printf("ERROR - Ingrese que tipo de alumno desea procesar, 1 para inicial, 2 para transferencia.");
        return 1;
    }

    sprintf(fileName, "alumnos%d.dat", tipoAlumno);

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
            /*get amount of rows in file*/
            newCant = getCant(archivo);

            if (newCant > cant)
            {
                /*rewind file pointer*/
                rewind(archivo);

                /*clear terminal*/
                system("clear");

                /*read file*/
                voReadFile(archivo);
            }

            voCloseFile(archivo);
            semaphore_release(id_semaforo);
        }

        usleep(100 * 1000);
    }

    return 0;
}
