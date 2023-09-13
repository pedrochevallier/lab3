#ifndef _GESTIONARCH
#define _GESTIONARCH

FILE * inAbrirArchivo(FILE *, const char *, const char *);
void voCerrarArchivo(FILE *);
int inLeerArchivo(FILE *);
void voEscribirArchivo(FILE *, int , char *, char *);
void voRenombrarArchivo(char *, char *);

#endif
