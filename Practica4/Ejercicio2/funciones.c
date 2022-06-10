#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void existe_fichero(char* nombre_fichero){
    FILE* f;
    f=fopen(nombre_fichero, "rb");

    if(f==NULL){
        f=fopen(nombre_fichero, "wb");
    }

    fclose(f);
}

void rellenar_fichero(char* nombre_fichero){
    FILE* f;

    struct alumno aux;

    int na;

    printf("\n Dime el numero de alumnos que deseas introducir: ");
    scanf("%d", &na);

    f=fopen(nombre_fichero, "ab");

    for(int i=0; i<na; i++){
        printf("\n Introduce el nombre del alumno %d: ", i+1);
        scanf("%s", aux.nombre);
        printf("\n Introduce el DNI del alumno (sin letra) %d: ", i+1);
        scanf("%d", &aux.DNI);
        printf("\n Introduce la nota del alumno %d: ", i+1);
        scanf("%f", &aux.nota);
        fwrite(&aux, sizeof(struct alumno), 1, f);
    }
    fclose(f);
}

int contar_registros(char* nombre_fichero){ 
    long tam;
    FILE* f;

    f=fopen(nombre_fichero, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    if(fseek(f, 0L, SEEK_END)){
        printf("\n  --> Error, no se ha podido trabajar con el fichero\n");
        fclose(f);
        exit(-1);
    }

    tam=ftell(f);
    fclose(f);
    return tam/sizeof(struct alumno);
}

struct alumno* reservar_vector(int nele){
    struct alumno* aux;

    aux = (struct alumno*) malloc(nele*sizeof(struct alumno));

    if(aux==NULL){
        printf(" \nError, la memoria no pudo ser reservada");
        exit(-1);
    }

    return aux;
}

void rellenar_vector(struct alumno vec[], int nele, char nombre_fichero[]){
    FILE* f;
    f=fopen(nombre_fichero, "rb");

    fread(vec, sizeof(struct alumno), nele, f);

    fclose(f);
}

int ascendente(int a, int b){
    return a<b;
}

int descendente(int a, int b){
    return a>b;
}

void ordenar_vector(struct alumno vec[], int nele, int (*fun)(int, int)){

    struct alumno aux;
    int pmin;

    for(int i=0; i<nele-1; i++){
        pmin=i;
        for(int j=i+1; j<nele; j++){
            if((*fun)(vec[j].DNI, vec[i].DNI)){
                pmin=j;
            }
        }
        strcpy(aux.nombre, vec[i].nombre);
        aux.DNI = vec[i].DNI;
        aux.nota = vec[i].nota;

        strcpy(vec[i].nombre, vec[pmin].nombre);
        vec[i].DNI = vec[pmin].DNI;
        vec[i].nota = vec[pmin].nota;

        strcpy(vec[pmin].nombre, aux.nombre);
        vec[pmin].DNI = aux.DNI;
        vec[pmin].nota = aux.nota;
    }
}

void imprimir_vector(struct alumno vec[], int nele){
    
    for(int i=0; i<nele; i++){

        printf("\n Alumno %d:", i);
        printf("\n Nombre: %s", vec[i].nombre);
        
        printf("\n DNI: %d", vec[i].DNI);
        
        printf("\n Nota: %f", vec[i].nota);
        
    }
}