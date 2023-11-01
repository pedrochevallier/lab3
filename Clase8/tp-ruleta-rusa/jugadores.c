#include <pthread.h>
#include <unistd.h>
#include <global.h>
#include <thread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 10

int main(int arg, char *argv[])
{
    pthread_t idHilo;
    pthread_attr_t atributos;
    int i;
    char *valorDevuelto = NULL;
    int vector_tambor[6] = {0};

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < CANTIDAD_JUGADORES; i++)
    {
        if (pthread_create(&idHilo, &atributos, funcionThread, &vector_tambor) != 0)
        {
            perror("No puedo crear thread");
            exit(-1);
        }
    }
    sleep(1);
    
    printf("Padre : Espero a que terminen los threads\n");

    pthread_join(idHilo, (void **)&valorDevuelto);
    printf("Padre : Ya han terminado los thread\n");
    printf("Padre : devuelve \"%s\"\n", valorDevuelto);
    return 0;
}
