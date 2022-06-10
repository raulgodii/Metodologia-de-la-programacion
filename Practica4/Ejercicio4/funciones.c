#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprimir_menu(){

    printf("\nSeleccione una opcion: \n");
    printf("\n  1. Comprobar la existencia de un determinado monomio buscando por su exponente");
    printf("\n  2. Introducir un nuevo monomio en la lista (sin repetir exponente)");
    printf("\n  3. Evaluar el polinomio en un valor de x determinado");
    printf("\n  4. Eliminar un monomio buscando por su exponente");
    printf("\n  5. Imprimir polinomio");
    printf("\n  6. Salir");

}

int buscar_monomio(struct nodo* cabeza, int e){
    int res=0;
    struct nodo *aux = NULL;
    aux=cabeza;

    //Se recorre la lista hasta encontrar el elemento o hasta llegar al final
    while (aux != NULL && res == 0){
        if (aux->e == e){
            res = 1;
        } else{
        aux = aux->sig;
        }
    }
    
    return res;

}

struct nodo* nuevo_monomio(){
    return ((struct nodo*)malloc(sizeof(struct nodo)));
}

void insertar_monomio(struct nodo** cabeza, int e, int c){
    
    struct nodo* nuevo = nuevo_monomio();
    nuevo->c = c;
    nuevo->e = e;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
}

void evaluar_polinomio(struct nodo* cabeza, int x){
    int sum=0;
    struct nodo* aux = cabeza;

    while(aux!=NULL){
        sum=sum + ((aux->c)*(pow(x, aux->e)));
        aux=aux->sig;
    }

    printf("\n El valor del polinomio en %d es: %d", x, sum);
}