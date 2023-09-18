#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <gestionarch.h>

FILE *inOpenFile(FILE *cfptr, const char *mode, const char *fileName)
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
    int i = 0;

    while (fgets(producto, sizeof(producto), cfptr))
    {
        /*Tokenize the line based on tabs*/
        token = strtok(producto, ",");
        while (token != NULL)
        {
            /* Process each token (data element)*/
            if(i == 0){
                i = atoi(token);
            }
            token = strtok(NULL, ",");
        }
    }
    
    return i;
}

void voWriteFile(FILE *cfptr, struct orden order)
{
    fprintf(cfptr, "%d,%s\n", order.price, order.description);
}
