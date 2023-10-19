#include <key.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <semaforo.h>
#include <sys/ipc.h>
#include <sys/sem.h>

/*funcion que crea el semaforo*/
int create_semaphore(void)
{
    key_t clave = creo_clave(CLAVE_BASE);
    int id_semaforo = semget(clave, 1, 0600 | IPC_CREAT);
    /*PRIMER PARAMETRO ES LA CLAVE, EL SEGUNDO CANT SEMAFORO, EL TERCERO 0600LO UTILIZA CUALQUIERA, IPC ES CONSTANTE (VEA SEMAFORO)*/
    if (id_semaforo == -1)
    {
        printf("Error: no puedo crear semaforo\n");
        exit(0);
    }
    return id_semaforo;
} /*inicia el semaforo*/
void init_semaphore(int id_semaforo, int valor)
{
    semctl(id_semaforo, 0, SETVAL, valor);
}
/*levanta el semaforo*/
void semaphore_release(int id_semaforo)
{
    struct sembuf operacion;
    
    operacion.sem_num = 0;
    operacion.sem_op = 1;
    /* incrementa el semaforo en 1*/
    operacion.sem_flg = 0;
    semop(id_semaforo, &operacion, 1);
}
/* espera semaforo*/
void semaphore_wait(int id_semaforo)
{
    struct sembuf operacion;

    operacion.sem_num = 0;
    operacion.sem_op = -1;
    /* decrementa el semaforo en 1*/
    operacion.sem_flg = 0;
    semop(id_semaforo, &operacion, 1);
}

