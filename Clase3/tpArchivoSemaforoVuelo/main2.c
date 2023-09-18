#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    int i = 0;
    int id_semaforo;
    int file_flag;
    FILE *archivo = NULL;
    char fileName[] = "lote.dat";
    char nuevo_archivo_nombre[20];
    
    id_semaforo = create_semaphore();

    while (1)
    {
        semaphore_wait(id_semaforo);

        if((archivo = inOpenFile(archivo, "r", fileName)) == NULL){ /*if NULL el archivo fue renombrado, lo creo de nuevo.*/
            archivo = inOpenFile(archivo, "w", fileName);
        }
        
        file_flag = inReadFile(archivo);
        
        if(file_flag == 1)
        {
            printf("\nLos Datos Ingresados son: \n\n");
            sprintf(nuevo_archivo_nombre, "lote-%d.dat", i);
            voCloseFile(archivo);
            voRenombrarArchivo(fileName, nuevo_archivo_nombre);
            i++;
        }else{
            voCloseFile(archivo);
        }

        semaphore_release(id_semaforo);

        usleep(300 * 1000);
    }

    return 0;
}
