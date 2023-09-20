#ifndef _GESTIONARCH
#define _GESTIONARCH

struct orden
{
    int id;
    int price;
    char description[50];
};

FILE * inOpenFile(FILE *, const char *, const char *);
void voCloseFile(FILE *);
int getCant(FILE *);
const char* getfield(char*, int);
int inReadFile(FILE *);
void voWriteFile(FILE *, struct orden);

#endif
