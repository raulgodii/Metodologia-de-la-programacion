/*
5. Codifica un programa en C que, utilizando funciones, cree un fichero binario con números
enteros generados aleatoriamente en un intervalo especificado por el usuario. El programa
guardará los números en un vector dinámico antes de volcarlo a disco. El programa recibirá 4
parámetros como argumentos en la línea de órdenes: nombre del fichero a crear, número de
elementos que contendrá el fichero y los extremos superior e inferior del intervalo.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(int argc, char** argv){
    char* nombre;
    int nele, superior, inferior;
    int* vec;

    if(argc!=5){
        printf("\n Error, sintaxis: nombre.fichero numero.elementos superior inferior\n");
        exit(-1);
    }

    nombre = argv[1];
    nele = atoi(argv[2]);
    superior = atoi(argv[3]);
    inferior = atoi(argv[4]);

    vec = reservar_vector(nele);

    rellenar_vector(vec, nele, superior, inferior);

    escribir_fichero(nombre, nele, vec);

    visualizar_fichero(nombre, nele);

    free(vec);
    return 0;
}