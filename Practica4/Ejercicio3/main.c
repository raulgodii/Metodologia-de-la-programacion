/*
3. Escribe un programa en C que lea de un fichero binario un vector dinámico de elementos de tipo
struct alumno (definido en el ejercicio 2) y lo ordene ascendentemente por el campo nombre o
por el campo nota utilizando la función qsort de stdlib.h
*/

#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

void main(){

    char nombre_fichero [50];
    int orden;

    printf(" Introduce el nombre del fichero: ");
    scanf("%s", nombre_fichero);

    printf(" \nIntroduce con que deseas trabajar (1. Nombre    2.Nota): ");
    scanf("%d", &orden);

    if(orden!=1 && orden!=2){
        printf(" \n ERROR, debe ser 1 o 2");
        exit(-1);
    }

    //Comprobamos existencia fichero
    existe_fichero(nombre_fichero);

    //Rellenamos el fichero
    rellenar_fichero(nombre_fichero);

    //Creamos el vector dinamico
    int nele = contar_registros(nombre_fichero);
    struct alumno* vec = reservar_vector(nele);
    
    //Rellenamos el vector
    rellenar_vector(vec, nele, nombre_fichero);

    //Ordenamos el vector
    if(orden==1){ //Ordenamos por nombre
        qsort(vec, nele, sizeof(struct alumno), compara_nombre);           //<0 x antes que y
    }                                                              //>0 x despues que y
                                                                   
    if(orden==2){ //Ordenamos por nota
        qsort(vec, nele, sizeof(struct alumno), compara_nota);
    }

    //Imprimimos el vector
    imprimir_vector(vec, nele);

    free(vec);

}