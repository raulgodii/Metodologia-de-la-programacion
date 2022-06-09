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

    printf(" Introduce el nombre del fichero: ");
    scanf("%s", nombre_fichero);

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
    ordenar_vector(vec, nele);

    //Imprimimos el vector
    imprimir_vector(vec, nele);

    free(vec);

}