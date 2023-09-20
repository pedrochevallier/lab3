#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "global.h"
#include "funciones.h"
#include <time.h>

int main(int arg, char *argv[])
{
    char cadena[20];
    int entero[2];
    int desde=0, hasta=0;
    
    if (arg == 3){
        desde = atoi(argv[1]);
        hasta = atoi(argv[2]);
    }
    else
    {
        desde = 30;
        hasta = 100;
    }
    srand(time(NULL));
    memset(cadena, 0x00, sizeof(cadena)); /* set memoria */
    printf("primero HOLA\n");
    memcpy(cadena, "pepe2", 5);
    memcpy(cadena, "1234", 3);
    printf("%s\n", cadena);
    

    /* varEntero = 0;
    varEntero = 1230;*/

    printf("%d\n", devolverNumAleatorio(desde, hasta));

    return 0;
}
