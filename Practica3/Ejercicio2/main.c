/*
2. Codifica un programa en C que, utilizando funciones, cree un fichero texto con números enteros
generados aleatoriamente en un intervalo especificado por el usuario. El programa le preguntará
al usuario el nombre del fichero a crear, el número de elementos que contendrá el fichero y los
extremos superior e inferior del intervalo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){

    char fichero[30];   //creamos el fichero

    printf("Dime el nombre del fichero: ");
    scanf("%s", fichero);  
    strcat(fichero, ".txt");

    FILE* f;

    if((f=fopen(fichero, "w"))==NULL){
        printf("\nError, el fichero no pudo abrirse\n");
        exit(-1);
    } else {
        printf("\nEl fichero se abrio con exito");
    }

    int inferior, superior;
    printf("\nDime el extremo inferior: "); //extremo inferior
    scanf("%d", &inferior);

    printf("\nDime el extremo superior: "); //extremo superior
    scanf("%d", &superior);

    int nele;
    printf("\nDime el numero de elementos: ");  //numero de elementos
    scanf("%d", &nele);

    escribir_fichero(&f, inferior, superior, nele);

    fclose(f);

    return 0;
}