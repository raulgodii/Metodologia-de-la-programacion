#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void main(){

    //Numero de alumnos
    int na = 1;
    contar_alumnos(&na);
    struct alumno* vec;
    vec = reservar_vector(na);
    printf("\n Numero de alumnos = %d", na);

    //Crear fichero
    FILE* f;
    f = fopen("fichero.txt", "w");
    fclose(f);
    crear_fichero("fichero.txt", vec);

}