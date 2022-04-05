#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prototipos.h"

void reservarmemoria(struct Ficha_jugador **jugador, int n){
    *jugador=(struct Ficha_jugador*)malloc(n*sizeof(struct Ficha_jugador));
    if(*jugador==NULL){
        printf("\n Error, la memoria no pudo reservarse\n");
        exit(-1);
    } else {
        printf("\n La memoria ha sido reservada con exito\n");
    }
}

struct Ficha_jugador rellena_jugador(){
    struct Ficha_jugador aux;

    printf("\n  Nombre: ");
    scanf("%s", aux.nombre);

    printf("\n  Dorsal: ");
    scanf("%d", &aux.dorsal);

    printf("\n  Peso (kg): ");
    scanf("%f", &aux.peso);

    printf("\n Estatura (cm): ");
    scanf("%d", &aux.estatura);

    return aux;
}

void introducir_jugadores(struct Ficha_jugador* jugador, int n){
    for(int i=0; i<n; i++){
        printf("\n-Introduce los datos del jugador numero %d: ", i);
        jugador[i]=rellena_jugador();
    }
}

void imprimir_jugadores(struct Ficha_jugador* jugador, int n){
    printf("\n  / / / LISTA DE JUGAGORES / / /");
    for(int i=0; i<n; i++){
        printf("\n-Jugador %d: ", i);
        printf("\n  Nombre: %s", jugador[i].nombre);
        printf("\n  Dorsal: %d", jugador[i].dorsal);
        printf("\n  Peso (kg): %f", jugador[i].peso);
        printf("\n  Estatura (cm): %d", jugador[i].estatura);
    }
}

void borra_jugadores(struct Ficha_jugador* jugador, int* n){
    char a []= "a";
    struct Ficha_jugador aux[*n];
    int j = 0;
    int cont=0;

    for(int i=0; i<(*n); i++){
        if(strstr(jugador[i].nombre, a)==NULL){
            aux[j]=jugador[i];
            j++;
        } else {
            cont++;
        }
    }

    *n=((*n)-cont);
    
    for(int i=0; i<(*n); i++){
        jugador[i]=aux[i];
    }

    jugador=(struct Ficha_jugador*)realloc(jugador, (*n)*sizeof(struct Ficha_jugador));
    if(jugador==NULL){
        printf("\n \nError, la memoria no pudo reservarse");
        exit(-1);
    } else {
        printf("\n \nLa memoria ha sido reservada con exito");
    }

    printf("\n ");
    printf("\n  / / / NUEVA LISTA DE JUGAGORES (sin la a) / / /");
    for(int i=0; i<(*n); i++){
        printf("\n-Jugador %i: ", i);
        printf("\n  Nombre: %s", jugador[i].nombre);
        printf("\n  Dorsal: %i", jugador[i].dorsal);
        printf("\n  Peso (kg): %f", jugador[i].peso);
        printf("\n  Estatura (cm): %i", jugador[i].estatura);
    }
    
}