#ifndef _GESTIONARCH
#define _GESTIONARCH

struct alumno
{
    int tipoAlumno;
    int cantMaterias;
    char NombreApellido[50];
};

FILE * inOpenFile(FILE *, const char *, const char *);
void voCloseFile(FILE *);
int getCant(FILE *);
const char* getfield(char*, int);
void voReadFile(FILE *);
void voWriteFile(FILE *, struct alumno);

#endif
