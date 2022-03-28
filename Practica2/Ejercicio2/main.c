/*
2. Escribe una función que, dado un vector dinámico, su longitud y un número entero (num),
devuelva dos vectores dinámicos. Uno contendrá los elementos mayores que num y otro los
elementos menores o iguales que num. Implementa un pequeño programa para probar la función.
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int main(){

    int cont, n, nmay, nmen, num;
    nmay=0;
    nmen=0;
    cont=0;
    
    /*
    printf("Dime el numero de elementos del vector");
    scanf("%d", n);

    for(int i=0; i<n; i++){
        printf("Dime el elemento numero %i del vector: ", i);
        scanf("%d", v[i])
    }
    */

    printf("\n Dime el numero a considerar: ");
    scanf("%d", &num);

    printf("\n Dime el numero de elementos del vector: ");
    scanf("%d", &n);

    int* vector, *mayores, *menores;
    reserva (&vector, n);

    rellenar(vector, n);

    imprimir(vector, n, &cont);

    comparar(num, n, vector, &nmay, &nmen);

    reserva (&mayores, nmay);
    reserva (&menores, nmen);

    rellena_vectores(vector, n, mayores, nmay, menores, nmen, num);

    imprimir (mayores, nmay, &cont);
    imprimir (menores, nmen, &cont);

    printf("\n");

    free (vector);
    free (mayores);
    free (menores);

    return 0;
    //vectordin(&vector, n, &mayores, &menores, num, n);
}