#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <funciones.h>

/* int devolverNumAleatorio(int desde, int hasta)
{
    return 2;
}*/

int devolverNumAleatorio(int desde, int hasta)
{
    return(rand()%(hasta-desde+1))+desde;
}

int suma()
{
    return devolverNumAleatorio(6,8);
}
