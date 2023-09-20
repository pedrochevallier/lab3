#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include "gestionarch.h"

FILE * inOpenFile(FILE *cfptr, char mode[]){
    if((cfptr = fopen("producto.txt", mode))==NULL){
        printf("No se pudo abrir el archivo!\n");
        return NULL;
    }
    else{
        return cfptr;
    }
}

void voCloseFile(FILE *cfptr){
    fclose(cfptr);
}

void inReadFile(FILE *cfptr){
    char product[15];
    
    printf("\nLos Datos Ingresados son: \n\n");
        while (!feof(cfptr))
        {
            fscanf(cfptr, "%s\n", product);
            printf("%s\n", product);
        }
}

void voWriteFile(FILE *cfptr){
    int i=0, cant=9;
    for(i=0; i<= cant; i++)
        {
            fprintf(cfptr, "PRODUCTO-%0.2d\n",i+1);
        }
}