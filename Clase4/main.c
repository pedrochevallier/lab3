#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaforo.h>
#include <realizarPastilla.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    int id_semaforo;
    int tipo;
    int color;
    int cant=0;
    char fileName1[] = "lote5.dat";
    char fileName2[] = "lote10.dat";
    char fileName3[] = "lote20.dat";
    FILE *archivo = NULL;

    id_semaforo = creo_semaforo();

    inicia_semaforo(id_semaforo, VERDE);

    while (1)
    {
        tipo = generarTipo();
        color = generarColor();
        printf("Cuantas pastillas desea realizar? (5, 10 o 20): ");
        scanf("%d",&cant);
        if(cant == 5){
            espera_semaforo(id_semaforo);
            archivo = inAbrirArchivo(archivo, "w", fileName1);
            voEscribirArchivo(archivo, tipo, color);
            voCerrarArchivo(archivo);
            levanta_semaforo(id_semaforo);
        }
        else if (cant == 10)
        {
            espera_semaforo(id_semaforo);
            archivo = inAbrirArchivo(archivo, "w", fileName2);
            voEscribirArchivo(archivo, tipo, color);
            voCerrarArchivo(archivo);
            levanta_semaforo(id_semaforo);
        }
        else if (cant == 20)
        {
            espera_semaforo(id_semaforo);
            archivo = inAbrirArchivo(archivo, "w", fileName3);
            voEscribirArchivo(archivo, tipo, color);
            voCerrarArchivo(archivo);
            levanta_semaforo(id_semaforo);
        }
        else{
            printf("Numero invalido, ingrese nuevamente.\n");
        }
        
    }

    return 0;
}
