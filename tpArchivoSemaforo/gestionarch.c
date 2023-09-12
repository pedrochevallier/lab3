#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <gestionarch.h>

FILE * inAbrirArchivo(FILE *cfptr, char mode[]){
    if((cfptr = fopen("lote.dat", mode))==NULL){
        printf("No se pudo abrir el archivo!\n");
        return NULL;
    }
    else{
        return cfptr;
    }
}

void voCerrarArchivo(FILE *cfptr){
    fclose(cfptr);
}

void voLeerArchivo(FILE *cfptr){
    char product[15];
    
    printf("\nLos Datos Ingresados son: \n\n");
        while (!feof(cfptr))
        {
            fscanf(cfptr, "%s\n", product);
            printf("%s\n", product);
        }
}

void voEscribirArchivo(FILE *cfptr, int vuelo, char *destino, char *nombre){
    
    fprintf(cfptr, "%d %s %s \n", vuelo, destino, nombre);
    
}