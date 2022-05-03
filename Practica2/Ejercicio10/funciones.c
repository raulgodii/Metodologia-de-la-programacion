#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reserva_cadena(char** cad){
    if((*cad = (char*)malloc(50*sizeof(char)))==NULL){
        printf("Error, la memoria no pudo reservarse\n");
    } else {
        printf("La memoria ha sido reservada con exito\n");
    }
}
int veces(int n, char* cad, char* cad2){
    int r=0;
    if(n>strlen(cad)){
        return r;
    } else {
        if(cad2[0]==cad[n]){
            r=1+veces(n+1, cad, cad2);
        } else {
            veces(n+1, cad, cad2);
        }
    }
}