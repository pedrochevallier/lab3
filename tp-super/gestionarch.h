#ifndef _GESTIONARCH
#define _GESTIONARCH

struct orden
{
    int price;
    char description[50];
};

FILE * inAbrirArchivo(FILE *, const char *, const char *);
void voCerrarArchivo(FILE *);
int inLeerArchivo(FILE *);
void voEscribirArchivo(FILE *, struct orden);

#endif
