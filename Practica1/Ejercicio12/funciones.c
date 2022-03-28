#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void rellenaVector(int* v, int n, int rango) {
    time_t t;
    srand(time(&t));

    for(int i=0; i<n; i++){
        v[i]=rand()%(rango+1);
    }
}

void imprimeVector(int* v, int n){
    for(int i=0; i<n; i++){
        printf("\n   Vector[%d]=%d", i, v[i]);
    }
}

void impares_divisibles(int* nimpares, int* ndivisibles, int* v, int n){
    for(int i=0; i<n; i++){
        if((v[i]%2)!=0){
            (*nimpares)++;
        }
    }
    for(int i=0; i<n; i++){
        if(v[i]!=0){
            if((v[i]%3)==0){
                (*ndivisibles)++;
            }
        }
    }
}

void indices(int* v, int n, int* impares[], int nimpares, int* divisibles[], int ndivisibles){
    int imp=0;
    for(int i=0; i<n; i++){
        if((v[i]%2)!=0){
            impares[imp]=(v+i);
            imp++;
        }
    }
    int div=0;
    for(int i=0; i<n; i++){
        if(v[i]!=0){
            if((v[i]%3)==0){
            divisibles[div]=(v+i);
            div++;
            }
        }
    }
}

void imprime_indices(int* impares[], int nimpares, int* divisibles[], int ndivisibles){
   printf("\n /// Imprimiendo indices.... ///\n");
    for(int i=0; i<nimpares; i++){
        printf("\n     IndiceImpares[%d]=%d", i, **(impares+i));
    }
    printf("\n");
    for(int i=0; i<ndivisibles; i++){
        printf("\n     IndiceDivisibles[%d]=%d", i, **(divisibles+i));
    }
}
