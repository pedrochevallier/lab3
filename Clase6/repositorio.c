#include <definiciones.h>
#include <global.h>
#include <cola.h>
#define INTERVALO_PEDIDOS 2
void procesar_evento(int id_cola_mensajes, mensaje msg)
{
    printf("Destino %d\n", (int)msg.long_dest);
    printf("Remitente %d\n", msg.int_rte);
    printf("Evento %d\n", msg.int_evento);
    printf("Mensaje %s\n", msg.char_mensaje);
    switch (msg.int_evento)
    {
    case EVT_RESPUESTA_STOCK:
        printf("Rta stock\n");
        printf("STOCK %d\n", atoi(msg.char_mensaje));
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
    mensaje msg;
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
    while (1)
    {
        printf("enviando mensaje\n");
        enviar_mensaje(id_cola_mensajes, MSG_SUPERMERCADO, MSG_REPOSITOR, EVT_SUMA_STOCK, "SUMA UNO");
        printf("enviando mensaje 2\n");
        enviar_mensaje(id_cola_mensajes, MSG_SUPERMERCADO, MSG_REPOSITOR, EVT_CONSULTA_STOCK, "DECIME EL STOCK POR FAVOR");
        printf("recibiendo mensaje\n");
        recibir_mensaje(id_cola_mensajes, MSG_REPOSITOR, &msg);
        printf("procesando evento\n");
        procesar_evento(id_cola_mensajes, msg);
        usleep(INTERVALO_PEDIDOS * 1000);
    };
    return 0;
}
