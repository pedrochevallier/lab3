#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

/*Declare struct defined in gestionarch*/
struct alumno alumnos[SIZE];

int main(int arg, char *argv[])
{
    int semaphore_id;
    int i = 0;

    FILE *fileInicial = NULL;
    FILE *fileTransfer = NULL;

    char fileNameInicial[SIZE] = "alumnos1.dat";
    char fileNameTransfer[SIZE] = "alumnos2.dat";

    semaphore_id = create_semaphore();

    init_semaphore(semaphore_id, VERDE);

    fileInicial = inOpenFile(fileInicial, "w", fileNameInicial);
    voCloseFile(fileInicial);

    fileTransfer = inOpenFile(fileTransfer, "w", fileNameTransfer);
    voCloseFile(fileTransfer);

    while (1)
    {
        printf("Ingrese el tipo de alumno (1 para inicial, 2 para transferencia): ");
        scanf("%d", &alumnos[i].tipoAlumno);

        while (alumnos[i].tipoAlumno != 0)
        {
            /*catch new line left by scanf*/
            scanf("%*c");
            if (alumnos[i].tipoAlumno == 2)
            {
                printf("Ingrese cantida de materias a validar: ");
                scanf("%d", &alumnos[i].cantMaterias);
                /*catch new line left by scanf*/
                scanf("%*c");
            }
            else
            {
                alumnos[i].cantMaterias = 0;
            }
            printf("Ingrese el nombre y apellido del alumno: ");

            /*limpio variable*/
            memset(alumnos[i].NombreApellido, 0x00, sizeof(alumnos[i].NombreApellido));

            scanf("%[^\n]", alumnos[i].NombreApellido);

            semaphore_wait(semaphore_id);

            if (alumnos[i].tipoAlumno == 1)
            {
                fileInicial = inOpenFile(fileInicial, "a", fileNameInicial);
                voWriteFile1(fileInicial, alumnos[i]);

                /*Close file*/
                voCloseFile(fileInicial);
            }
            else if (alumnos[i].tipoAlumno == 2)
            {

                fileTransfer = inOpenFile(fileTransfer, "a", fileNameTransfer);
                voWriteFile2(fileTransfer, alumnos[i]);
                /*Close file*/
                voCloseFile(fileTransfer);
            }

            semaphore_release(semaphore_id);

            i++;

            printf("Ingrese el tipo de alumno (1 para inicial, 2 para transferencia): ");
            scanf("%d", &alumnos[i].tipoAlumno);
        }

        usleep(100 * 1000);
    }
    return 0;
}
