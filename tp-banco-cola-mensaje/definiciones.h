#ifndef _DEFINICIONES_H
#define _DEFINICIONES_H

typedef struct tipo_datos datos;
struct tipo_datos
{
    int dato;
};

typedef enum
{
    MSG_NADIE,
    MSG_BANCO,
    MSG_CAJERO
} Destinos;

typedef enum
{
    // eventos banco
    EVT_NINGUNO,
    EVT_CONSULTA_SALDO,
    EVT_DEPOSITO,
    EVT_EXTRACCION,
    //eventos cajero
    EVT_RTA_SALDO,
    EVT_RTA_SALDO_NOK,
    EVT_RTA_DEPOSITO,
    EVT_RTA_DEPOSITO_NOK,
    EVT_RTA_EXTRACCION,
    EVT_RTA_EXTRACCION_NOK
} Eventos;
#endif
