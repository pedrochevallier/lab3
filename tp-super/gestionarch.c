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

int getCant(FILE *file)
{
    char producto[100];
    int i = 0;

    while (fgets(producto, sizeof(producto), file))
    {
        i++;
    }

    return i;
}

const char *getfield(char *line, int num)
{
    const char *tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ","))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int inReadFile(FILE *file)
{
    char producto[100];
    char *token;
    int i = 0;

    char line[1024];
    while (fgets(line, 1024, file))
    {
        char *tmp = strdup(line);
        i += atoi(getfield(tmp, 2));
        free(tmp);
    }

    return i;
}

void voWriteFile(FILE *cfptr, struct orden order)
{
    fprintf(cfptr, "%d,%d,%s\n", order.id, order.price, order.description);
}
