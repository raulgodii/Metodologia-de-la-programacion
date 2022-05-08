/*
3. Codifica un programa en C que, utilizando funciones, calcule la media de los elementos pares
que hay en un fichero de texto generado por el ejercicio anterior. El nombre del fichero se pasará
como argumento en la línea de órdenes.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    FILE* f;
    if((f=fopen("prueba.txt", "r"))==NULL){
        printf("\nError, el fichero no pudo abrirse\n");
        exit(-1);
    } else {
        printf("\nEl fichero se abrio con exito\n");
    }

    printf("La media de los elementos pares es igual a: %f \n", media(&f));

    fclose(f);
    return 0;
}