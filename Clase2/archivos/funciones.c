#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funciones.h"

int devolverNumAleatorio(int desde, int hasta)
{
    printf("PASE 3\n");
    return (rand() % (hasta - desde + 1)) + desde;
}

int suma()
{
    return devolverNumAleatorio(6, 8);
}

void voProbarArchivos()
{
}

