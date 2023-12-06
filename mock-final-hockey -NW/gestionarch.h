#ifndef _GESTIONARCH
#define _GESTIONARCH

FILE * inOpenFile(FILE *, const char *, const char *);
void voCloseFile(FILE *);
int inReadFile(FILE *);
void voWriteFile(FILE *, int , char *, char *);
void voRenombrarArchivo(char *, char *);

#endif
