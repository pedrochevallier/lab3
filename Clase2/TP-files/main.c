#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <gestionarch.h>

int main(int arg, char *argv[])
{
    char mode[1];
    
    FILE *cfptr = NULL;
    
    cfptr = inOpenFile(cfptr, "w");

    if(cfptr!= NULL){
        voWriteFile(cfptr);
        voCloseFile(cfptr);
    }

    cfptr = inOpenFile(cfptr, "r");

    if(cfptr != NULL){
        inReadFile(cfptr);
        voCloseFile(cfptr);
    }

    return 0;
}
