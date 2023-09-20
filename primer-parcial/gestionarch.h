#ifndef _GESTIONARCH
#define _GESTIONARCH
#define SIZE 1024

struct alumno
{
    int tipoAlumno;
    int cantMaterias;
    char NombreApellido[50];
};

FILE * inOpenFile(FILE *, const char *, const char *);
void voCloseFile(FILE *);
int getCant(FILE *);
void voReadFile(FILE *);
void voWriteFile1(FILE *, struct alumno);
void voWriteFile2(FILE *, struct alumno);

#endif
