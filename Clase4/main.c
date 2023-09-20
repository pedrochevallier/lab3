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
    int type;
    int color;
    int quantity=0;
    char fileName1[] = "lote5.dat";
    char fileName2[] = "lote10.dat";
    char fileName3[] = "lote20.dat";
    FILE *archivo = NULL;

    id_semaforo = create_semaphore();

    init_semaphore(id_semaforo, VERDE);

    while (1)
    {
        type = generarTipo();
        color = generarColor();
        printf("Cuantas pastillas desea realizar? (5, 10 o 20): ");
        scanf("%d",&quantity);
        if(quantity == 5){
            semaphore_wait(id_semaforo);
            archivo = inOpenFile(archivo, "w", fileName1);
            voWriteFile(archivo, type, color);
            voCloseFile(archivo);
            semaphore_release(id_semaforo);
        }
        else if (quantity == 10)
        {
            semaphore_wait(id_semaforo);
            archivo = inOpenFile(archivo, "w", fileName2);
            voWriteFile(archivo, type, color);
            voCloseFile(archivo);
            semaphore_release(id_semaforo);
        }
        else if (quantity == 20)
        {
            semaphore_wait(id_semaforo);
            archivo = inOpenFile(archivo, "w", fileName3);
            voWriteFile(archivo, type, color);
            voCloseFile(archivo);
            semaphore_release(id_semaforo);
        }
        else{
            printf("Numero invalido, ingrese nuevamente.\n");
        }
        
    }

    return 0;
}
