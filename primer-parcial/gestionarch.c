#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    char producto[SIZE];
    int i = 0;

    while (fgets(producto, sizeof(producto), file))
    {
        i++;
    }

    return i;
}

void voReadFile(FILE *file)
{
    char line[SIZE];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s",line);   
    }
}

void voWriteFile1(FILE *cfptr, struct alumno alumnos)
{
    fprintf(cfptr, "Alumno: %s, se incribe sin materias.\n", alumnos.NombreApellido);
}

void voWriteFile2(FILE *cfptr, struct alumno alumnos)
{
    fprintf(cfptr, "Alumno: %s, es necesario validar %d materias.\n", alumnos.NombreApellido, alumnos.cantMaterias);
}
