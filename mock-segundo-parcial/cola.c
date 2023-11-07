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
int enviar_mensaje(int id_cola_mensajes, long rLongDest, int rIntRte, int rIntEvento, int insumo, char *rpCharMsg)
{
    // id de la cola de mensaje
    // destinatario
    // remitente
    // evento
    // mensaje
    mensaje_hormiga msg;
    msg.long_dest = rLongDest;
    msg.int_rte = rIntRte;
    msg.int_evento = rIntEvento;
    msg.insumo = insumo;
    strcpy(msg.char_mensaje, rpCharMsg);
    return msgsnd(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.insumo) + sizeof(msg.char_mensaje), IPC_NOWAIT);
}
int recibir_mensaje(int id_cola_mensajes, long rLongDest, mensaje_hormiga *rMsg)
{
    // id de la cola de mensaje
    // destinatario
    // mensaje
    mensaje_hormiga msg;
    int res;
    res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.insumo) + sizeof(msg.char_mensaje), rLongDest, IPC_NOWAIT);
    rMsg->long_dest = msg.long_dest;
    rMsg->int_rte = msg.int_rte;
    rMsg->int_evento = msg.int_evento;
    rMsg->insumo = msg.insumo;
    strcpy(rMsg->char_mensaje, msg.char_mensaje);
    return res;
}
int borrar_mensajes(int id_cola_mensajes)
{
    mensaje_hormiga msg;
    int res;
    do
    {
        res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.insumo) + sizeof(msg.char_mensaje), 0, IPC_NOWAIT);
    } while (res > 0);
    return res;
}
