#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones.h"

int main(int arg, char *argv[])
{
    int desde = 0, hasta = 0;
    char cadena[30];
    char *szCadena1;
    char *szCadena2;
    char szCadena3[20 + 1];

    int entero;
    int *enteroDin;
    short shorts[2];

    entero = (int)malloc(5);
    szCadena1 = (char *)malloc(sizeof(char) * 5);
    szCadena2 = (char *)malloc(5);

    printf("Cantidad de argumentos: %d  %s  %s\n", arg, argv[1], argv[2]);
    printf("PASE 1\n");
    if (arg == 3)
    {
        desde = atoi(argv[1]);
        hasta = atoi(argv[2]);
    }
    else
    {
        desde = 30;
        hasta = 100;
    }
    memset(cadena, 0x00, sizeof(cadena));
    sprintf(cadena, "mi var en string: %d", desde);

    memset(cadena, 0x00, sizeof(szCadena1));
    memset(cadena, 0x00, sizeof(szCadena2));

    memcpy(&szCadena1[0], "FABIO", 5);
    memcpy(&szCadena2[0], "PABLO", 5);

    if (memcmp(&szCadena1[1], &szCadena2[1], 2) == 0)
    {
        printf("SE REPITEN DOS LETRAS: %c %c\n", szCadena1[1], szCadena2[2]);
        printf("SE REPITEN DOS LETRAS: %02x %02x\n", *(szCadena1 + 2), &szCadena2);
    }
    else
    {
        printf("NO SE REPITEN\n");
    }
    memcmp(szCadena1, szCadena2, strlen(szCadena2));
    /*strlen se corta cuando encuentra 0X00*/
    printf("PASE 2\n");

    printf("%d\n", devolverNumAleatorio(desde, hasta));
    printf("fin\n");
    free(szCadena1);
    free(szCadena2);

    return 0;
}
