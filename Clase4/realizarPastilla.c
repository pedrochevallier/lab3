#include <realizarPastilla.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generarTipo(void){
    int num;

    printf("Generando tipo de medicamento\n");
    num = (rand()%3+1);
    
    return num;

}


int generarColor(void){
    int num;

    printf("Generando color de medicamento\n");
    num = (rand()%3+1);
    
    return num;

}
