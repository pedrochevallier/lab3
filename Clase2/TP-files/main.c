#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    char mode[1];
    
    FILE *cfptr = NULL;
    
    cfptr = inAbrirArchivo(cfptr, "w");

    if(cfptr!= NULL){
        voEscribirArchivo(cfptr);
        voCerrarArchivo(cfptr);
    }

    cfptr = inAbrirArchivo(cfptr, "r");

    if(cfptr != NULL){
        inLeerArchivo(cfptr);
        voCerrarArchivo(cfptr);
    }

    return 0;
}
