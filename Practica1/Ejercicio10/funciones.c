#include <stdio.h>
#include <stdlib.h>

void leeVector(double* vector, int n){
 
    printf("\n De acuerdo, el tamaño de tu vector sera: %d \n", n);

    printf("\n -A continuacion dime que valores deseas que tengan los elementos del vector: ");
    for(int i=0; i<n; i++){
        printf("\n Dime el elemento numero <%d>: ", i);
        scanf("%lf", vector+i);
    }
}

void escribeVector(double* vector, int n){
    printf("\n Tu vector quedaria asi: \n");
    for(int i=0; i<n; i++){
        printf("\n Vector[%i]=%lf", i, *(vector+i));
    }
}

void sumaPositivos(double* vector, int n){
    double suma=0;

    for(int i=0; i<n; i++){
        if(vector[i]>0){
            suma+=*(vector+i);
        }
    }
    
    printf("\n La suma de los positivos mayores de cero de tu vector es: %lf \n", suma);
}