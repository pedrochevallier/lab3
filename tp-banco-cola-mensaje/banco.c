#include <definiciones.h>
#include <semaforo.h>
#include <global.h>
#include <cola.h>
#define INTERVALO_PEDIDOS 2000
void procesar_evento(int id_cola_mensajes, mensaje msg, cliente (*cli)[100])
{
    int saldo;
    int num_cliente;

    num_cliente = msg.nro_cuenta;

    switch (msg.int_evento)
    {
    case EVT_CONSULTA_SALDO:
        printf("Consulta saldo numero de cuenta: %d\n", msg.nro_cuenta);
        if (num_cliente >= 0 && num_cliente < 100)
        {
            saldo = (*cli)[num_cliente].saldo;
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO, num_cliente, saldo, "Consulta exitosa");
        }
        else
        {
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO_NOK, -1, -1, "El cliente solicitado no existe");
        }
        break;
    case EVT_DEPOSITO:
        printf("Pedido de deposito\n");
        if (num_cliente >= 0 && num_cliente < 100)
        {
            (*cli)[num_cliente].saldo = (*cli)[num_cliente].saldo + msg.monto;
            saldo = (*cli)[num_cliente].saldo;
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO, num_cliente, saldo, "Deposito exitoso");
        }
        else
        {
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO_NOK, -1, -1, "El cliente solicitado no existe");
        }

        break;
    case EVT_EXTRACCION:
        printf("Pedido de extraccion\n");
        if (num_cliente >= 0 && num_cliente < 100)
        {

            if ((*cli)[num_cliente].saldo < msg.monto)
            {
                enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_NOK, -1, -1, "El saldo de la cuenta es insuficiente");
            }
            else
            {
                (*cli)[num_cliente].saldo = (*cli)[num_cliente].saldo - msg.monto;
                saldo = (*cli)[num_cliente].saldo;
                enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO, num_cliente, saldo, "Extraccion exitosa");
            }
        }
        else
        {
            enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_NOK, -1, -1, "El cliente solicitado no existe");
        }
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
