#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "prototipos.h"


void leerMonomio(struct monomio polinomio[], int nm){
    for(int i=0; i<nm; i++){
        printf("\n-Monomio %d ", i);
        printf("\n Coeficiente: ");
        scanf("%d", &(polinomio[i].coeficiente));
        printf(" Grado: ");
        scanf("%d", &(polinomio[i].grado));
    }
}

void imprimirMonomio(struct monomio polinomio[], int nm){
    printf("Tu polinomio quedaria asi: ");
    for(int i=0; i<nm; i++){
        printf("+(%dx%d)", polinomio[i].coeficiente, polinomio[i].grado);
    }
    printf("\n");
}

void MayorMenorGrado(struct monomio polinomio[], int nm){
    int mayor = polinomio[0].grado;
    int menor = polinomio[0].grado;
    int contmayor = 0;
    int contmenor = 0;

    for(int i=0; i<nm; i++){
        if(polinomio[i].grado>mayor){
            mayor = polinomio[i].grado;
            contmayor = i;
        }
    }
    for(int j=0; j<nm; j++){
        if(polinomio[j].grado<menor){
            menor = polinomio[j].grado;
            contmenor = j;
        }
    }

    printf ("\n -El polinomio de mayor grado es: +(%dx%d)", polinomio[contmayor].coeficiente, polinomio[contmayor].grado);
    printf ("\n -El polinomio de menor grado es: +(%dx%d)", polinomio[contmenor].coeficiente, polinomio[contmenor].grado);
}

int evaluaPolinomio(struct monomio polinomio[], int nm, int valor){
    int res=0;
    for(int i=0; i<nm; i++){
        res=res+(polinomio[i].coeficiente)*pow(valor,polinomio[i].grado);
    }

    return res;
}

