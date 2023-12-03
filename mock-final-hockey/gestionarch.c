#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <gestionarch.h>

FILE * inOpenFile(FILE *cfptr, const char *mode, const char *fileName)
{
    if ((cfptr = fopen(fileName, mode)) == NULL)
    {
        printf("No se pudo abrir el archivo!\n");
        return NULL;
    }
    else
    {
        return cfptr;
    }
}

void voCloseFile(FILE *cfptr)
{
    fclose(cfptr);
}

int inReadFile(FILE *cfptr)
{
    char producto[100];
    char *token;
    int content_found = 0;
    /*while (!feof(cfptr))
        {
            fscanf(cfptr, "%s\n", product);
            printf("%s", product);
        }
    */
    while (fgets(producto, sizeof(producto), cfptr))
    {
        /*Tokenize the line based on tabs*/
        token = strtok(producto, ",");
        while (token != NULL)
        {
            /* Process each token (data element)*/
            printf("%s\t", token);
            token = strtok(NULL, ",");
            content_found = 1;
        }
    }
    

    return content_found;
}

void voWriteFile(FILE *cfptr, int vuelo, char *destino, char *nombre)
{
    fprintf(cfptr, "%d,%s,%s\n", vuelo, destino, nombre);
}

void voRenombrarArchivo(char *nombre_archivo, char *nuevo_archivo_nombre)
{
    int result = rename(nombre_archivo, nuevo_archivo_nombre);
    if (result == 0) {
        printf("The file is renamed successfully.");
    } else {
        printf("The file could not be renamed.");
    }
}
