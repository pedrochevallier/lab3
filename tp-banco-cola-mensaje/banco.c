#include <definiciones.h>
#include <semaforo.h>
#include <global.h>
#include <cola.h>
#define INTERVALO_PEDIDOS 2000
void procesar_evento(int id_cola_mensajes, mensaje msg, cliente (*cli)[100])
{
    int saldo;
    char char_saldo[20];
    int num_cliente;

    num_cliente = atoi(msg.char_mensaje);

    switch (msg.int_evento)
    {
    case EVT_CONSULTA_SALDO:
        printf("Consulta saldo numero de cuenta: %s\n", msg.char_mensaje);
        if (num_cliente >= 0 && num_cliente < 100)
        {
            saldo = (*cli)[num_cliente].saldo;
            sprintf(char_saldo, "%d", saldo);
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO, char_saldo);
        }
        else
        {
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO_NOK, "El cliente solicitado no existe");
        }
        break;
    case EVT_DEPOSITO:
        printf("Pedido de deposito\n");
        if (num_cliente >= 0 && num_cliente < 100)
        {
            break;
        }
        else
        {
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO_NOK, "El cliente solicitado no existe");
        }
        enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO, "cadena");
        break;
    case EVT_EXTRACCION:
        printf("Pedido de extraccion\n");
        enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION, "cadena");
        break;
    default:
        printf("\nEvento sin definir\n");
        break;
    }
    printf("------------------------------\n");
}

int main(int arg, char *argv[])
{
    int id_cola_mensajes;
    int id_semaforo;
    int i;
    mensaje msg;
    cliente cli[100];

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    id_semaforo = create_semaphore();

    init_semaphore(id_semaforo, VERDE);

    for (i = 0; i < 100; i++)
    {
        cli[i].numero_cliente = i + 1;
        cli[i].saldo = rand() % (5000 - 100) + 100;
    }

    while (1)
    {
        recibir_mensaje(id_cola_mensajes, MSG_BANCO, &msg);
        procesar_evento(id_cola_mensajes, msg, &cli);
    };
    return 0;
}
