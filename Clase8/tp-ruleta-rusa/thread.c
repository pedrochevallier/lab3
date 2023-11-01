#include <global.h>
#include <unistd.h>
#include <pthread.h>
#include <cola.h>

void *funcionThread(void *parametro)
{
    int id_cola_mensajes;
    mensaje msg;
    
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    
    printf("Hijo\n");
    recibir_mensaje(id_cola_mensajes, MSG_REVOLVER, &msg);
    printf("Soy el hijo y espero 10seg\n");
    sleep(10);
    printf("Hijo : Termino\n");
    pthread_exit((void *)"Listo");
}
