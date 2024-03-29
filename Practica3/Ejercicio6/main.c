/*
6. Codifica un programa en C que, utilizando funciones, lea números enteros desde un fichero
binario generado en el ejercicio anterior, almacene sus valores en un vector dinámico y calcule la
media de los números pares. El nombre del fichero se le preguntará al usuario.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(int argc, char** argv){
    if(argc!=2){
        printf("\n Error, sintaxis: nombre.fichero\n");
        exit(-1);
    }

    int* vec;
    int nele;
    char* nombre = argv[1];

    nele = contar_registros(nombre);

    vec = reservar_vector(nele);

    rellenar_vector(nombre, nele, vec);

    float media =  media_pares(vec, nele);

    printf("\n La media de los pares es igual a: %f \n", media);

    free(vec);

    return 0;
}