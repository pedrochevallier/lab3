#include <cola.h>
#include <key.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <global.h>

int creo_id_cola_mensajes(int clave)
{
    int id_cola_mensajes = msgget(creo_clave(clave), 0600 | IPC_CREAT);
    
    if (id_cola_mensajes == -1)
    {
        printf("Error al obtener identificador para cola mensajes\n");
        exit(-1);
    }
    return id_cola_mensajes;
}
int enviar_mensaje(int id_cola_mensajes, long rLongDest, int rIntRte, int rIntEvento, char *rpCharMsg)
{
    // id de la cola de mensaje
    // destinatario
    // remitente
    // evento
    // mensaje
    mensaje msg;
    msg.long_dest = rLongDest;
    msg.int_rte = rIntRte;
    msg.int_evento = rIntEvento;
    return msgsnd(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento), IPC_NOWAIT);
}
int recibir_mensaje(int id_cola_mensajes, long rLongDest, mensaje *rMsg)
{
    // id de la cola de mensaje
    // destinatario
    // mensaje
    mensaje msg;
    int res;
    res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento), rLongDest, 0);
    rMsg->long_dest = msg.long_dest;
    rMsg->int_rte = msg.int_rte;
    rMsg->int_evento = msg.int_evento;
    rMsg->presidente = msg.presidente;
    rMsg->vice_presidente = msg.vice_presidente;
    return res;
}
int borrar_mensajes(int id_cola_mensajes)
{
    mensaje msg;
    int res;
    do
    {
        res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento), 0, IPC_NOWAIT);
    } while (res > 0);
    return res;
}
