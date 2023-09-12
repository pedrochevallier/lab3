#ifndef _GESTIONARCH
#define _GESTIONARCH

FILE * inAbrirArchivo(FILE *, const char *, const char *);
void voCerrarArchivo(FILE *);
void voLeerArchivo(FILE *);
void voEscribirArchivo(FILE *, int , char *, char *);

#endif