#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <clave.h>

int main(int arg, char *argv[]){
    key_t clave;

    clave = creo_clave();

    return 0;
}