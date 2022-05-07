/*
1. Codifica un programa en C que, utilizando funciones, abra un fichero de texto, cuyo nombre se
pedirá al usuario, y genere un nuevo fichero llamado mayusculas-nombreFicheroDeEntrada.txt,
que tenga el mismo contenido que el fichero original pero en mayúsculas.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int main(){
    char fichero[30];
    char fichero_mayus [40];
    char txt[]=".txt";

    printf("Dime el nombre del fichero: ");
    scanf("%s", fichero);  
    strcpy (fichero_mayus, fichero); 
    strcat(fichero, txt);

    strcat(fichero_mayus, "mayus.txt");

    FILE* f;

    if((f=fopen(fichero, "w"))==NULL){
        printf("\nError, el fichero no pudo abrirse\n");
        exit(-1);
    } else {
        printf("\nEl fichero se abrio con exito");
    }

    printf("\nIntroduce el contenido del fichero: ");
    char cad[100];
    fgets(cad, 100, stdin);
    fgets(cad, 100, stdin);

    fprintf(f, "%s", cad);

    crear_fichero_mayus(fichero_mayus, cad);

    fclose(f);

    return 0;
}