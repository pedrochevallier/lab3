#include <definiciones.h>
#include <global.h>
#include <cola.h>
#include <semaforo.h>
#include <unistd.h>
#define INTERVALO_PEDIDOS 100
void procesar_evento(int id_cola_mensajes, mensaje msg)
{
    switch (msg.int_evento)
    {
    case EVT_RTA_SALDO:
        printf("Saldo de la cuenta: %d\n", atoi(msg.char_mensaje));
        break;
    case EVT_RTA_SALDO_NOK:
        printf("No se pudo realizar la consulta\n");
        printf("ERROR: %s\n", msg.char_mensaje);
        break;
    case EVT_RTA_DEPOSITO:
        printf("Nuevo saldo: %d\n", atoi(msg.char_mensaje));
        break;
    case EVT_RTA_DEPOSITO_NOK:
        printf("Hubo un error al realizar el deposito\n");
        printf("ERROR: %s\n", msg.char_mensaje);
        break;
    case EVT_RTA_EXTRACCION:
        printf("Saldo restante: %d\n", atoi(msg.char_mensaje));
        break;
    case EVT_RTA_EXTRACCION_NOK:
        printf("Hubo un error al realizar la extraccion\n");
        printf("ERROR: %s\n", msg.char_mensaje);
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
    int seleccion;
    int nro_cuenta;

    char numero_cuenta[20];

    mensaje msg;
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    id_semaforo = create_semaphore();
    while (1)
    {
        printf("Ingrese: \n1. Consulta\n2. Deposito\n3. Extraccion\n0. Salir\n");
        scanf("%d", &seleccion);
        while (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 0)
        {
            printf("ERROR\n");
            printf("Ingrese: \n1. Consulta\n2. Deposito\n3. Extraccion\n0. Salir\n");
            scanf("%d", &seleccion);
        }
        if (seleccion != 0)
        {
            printf("Ingrese numero de cuenta: ");
            scanf("%d", &nro_cuenta);
            sprintf(numero_cuenta, "%d", nro_cuenta);
        }
        semaphore_wait(id_semaforo);

        switch (seleccion)
        {
        case 1:
            printf("pedido de saldo\n");
            enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_CONSULTA_SALDO, numero_cuenta);
            break;
        case 2:
            printf("pedido de deposito\n");
            enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_DEPOSITO, numero_cuenta);
            break;
        case 3:
            printf("pedido de extraccion\n");
            enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_EXTRACCION, numero_cuenta);
            break;
        case 0:
            return 0;
        }
        semaphore_release(id_semaforo);
        usleep(1000 * 1000);

        semaphore_wait(id_semaforo);
        recibir_mensaje(id_cola_mensajes, MSG_CAJERO, &msg);
        procesar_evento(id_cola_mensajes, msg);
        semaphore_release(id_semaforo);

        usleep(INTERVALO_PEDIDOS * 1000);
    };
    return 0;
}
