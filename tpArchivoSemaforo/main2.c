#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    int i;
    int id_semaforo;
    FILE *archivo = NULL;
    char fileName[] = "lote.dat";
    
    
    id_semaforo = creo_semaforo();

    while (1)
    {
        espera_semaforo(id_semaforo);

        archivo = inAbrirArchivo(archivo, "r", fileName);
        voLeerArchivo(archivo);
        
        voCerrarArchivo(archivo);
        levanta_semaforo(id_semaforo);
        sleep(10);
        i++;
    }

    return 0;
}
