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
    
    id_semaforo = creo_semaforo();

    while (1)
    {
        espera_semaforo(id_semaforo);

        if((archivo = inAbrirArchivo(archivo, "r", fileName)) == NULL){ /*if NULL el archivo fue renombrado, lo creo de nuevo.*/
            archivo = inAbrirArchivo(archivo, "w", fileName);
        }
        
        file_flag = inLeerArchivo(archivo);
        
        if(file_flag == 1)
        {
            printf("\nLos Datos Ingresados son: \n\n");
            sprintf(nuevo_archivo_nombre, "lote-%d.dat", i);
            voCerrarArchivo(archivo);
            voRenombrarArchivo(fileName, nuevo_archivo_nombre);
            i++;
        }else{
            voCerrarArchivo(archivo);
        }

        levanta_semaforo(id_semaforo);

        usleep(300 * 1000);
    }

    return 0;
}
