#include <pthread.h>
#include <unistd.h>
#include <global.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 10

pthread_mutex_t mutex;

void *funcionThread(void *parametro)
{
    int random;
    struct thread_data *my_data;
    int i=0;
    my_data = (struct thread_data *)parametro;

    while (my_data->alguien_acerto == 0)
    {
        pthread_mutex_lock(&mutex);
        random = (rand() % 50) + 1;
        printf("%d ---- %d\n", random, my_data->numero_aleatorio);
        i++;
        if (random == my_data->numero_aleatorio)
        {
            my_data->alguien_acerto = 1;
            printf("acerte!\n");
        }
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
    printf("el proceso tomo %d interaciones antes de acertar\n",i);
    pthread_exit((void *)"Listo");
}
int main(int arg, char *argv[])
{

    pthread_t *idHilo;
    pthread_attr_t atributos;

    int i;
    int cantidad_jugadores = 0;
    int numero_aleatorio;
    char *valorDevuelto = NULL;
    idHilo = (pthread_t *)malloc(sizeof(pthread_t) * cantidad_jugadores);

    if (arg != 2)
    {
        printf("Uso: <Cantidad de jugadores> como parametro de entrada \n");
        return 1;
    }
    cantidad_jugadores = atoi(argv[1]);

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    srand(time(NULL));
    numero_aleatorio = (rand() % 50) + 1;

    data.numero_aleatorio = numero_aleatorio;
    data.alguien_acerto = 0;

    for (i = 0; i < cantidad_jugadores; i++)
    {

        if (pthread_create(&idHilo[i], &atributos, funcionThread, &data) != 0) // en lugar de null, pasar los parametros para el hilo
        {
            perror("No puedo crear thread\n");
            exit(-1);
        }
    }

    sleep(1);

    printf("Padre : Espero al thread\n");

    pthread_join(*idHilo, (void **)&valorDevuelto);
    printf("Padre : Ya ha terminado el thread\n");
    printf("Padre : devuelve \"%s\"\n", valorDevuelto);
    return 0;
}
