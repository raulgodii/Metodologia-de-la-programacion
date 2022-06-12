#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void contar_alumnos(int* na){
    FILE* f;
    char c;
    f = fopen("notas.txt", "r");

    while(!feof(f)){
        fscanf(f, "%c", &c);
        if(c=='\n'){
            (*na)++;
        }
    }

    fclose(f);
}

struct alumno* reservar_vector(int nele){
    struct alumno* aux;
    aux=(struct alumno*)malloc(nele*sizeof(struct alumno));
    return aux;
}

void clean(char* nombre){
    if(nombre[strlen(nombre)-1]=='\n'){
        nombre[strlen(nombre)-1]='\0';
    }
}

void crear_fichero(char* nombre, struct alumno* vec){
    FILE* f;
    FILE* alumnos;
    FILE* notas;

    f = fopen(nombre, "a");
    alumnos = fopen("alumnos.txt", "r");
    notas = fopen("notas.txt", "r");
    
    int tusmu = 14325;

    for(int i=0; !feof(alumnos); i++){
        fgets(vec[i].nombre, 100, alumnos);
        clean(vec[i].nombre);
        fscanf(alumnos, "%d\n", &vec[i].dni);
    }

    int dni;
    float nota1, nota2, nota3;
    for(int i=0; !feof(notas); i++){
        fscanf(notas, "%d%f%f%f", &dni, &nota1, &nota2, &nota3);
        float media = (nota1 + nota2 + nota3)/3;
        fprintf(f, "%d %s %f\n", vec[i].dni, vec[i].nombre, media);
    }

    fclose(f);
    fclose(alumnos);
    fclose(notas);
}