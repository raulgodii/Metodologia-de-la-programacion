/*
11. Codifica una función recursiva que permita sumar los dígitos de un número. Implementa un
programa para probarla. Ejemplo: Entrada: 124 Resultado: 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    int n;

    //Metemos el numero en un vector
    printf("Dime cuantos digitos quieres que tenga tu numero: ");
    scanf("%d", &n);
    int num[n];

    for(int i=0; i<n; i++){
    printf("\nDime el digito %d: ", i);
    scanf("%d", &num[i]);
    }
    
    printf("\n -Tu numero: ");
    for(int i=0; i<n; i++){
        printf("%d", num[i]);
    }
    
    //Hacemos la suma de digitos
    int i=0;
    int sum=0;

    printf("\n\nLa suma de digitos es igual a: %d \n", suma_digitos(num, n, i, sum));
    return 0;
}