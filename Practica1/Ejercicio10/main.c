/*
10. Codifica un programa que usando funciones y aritmética de punteros:
• Lea un vector de elementos tipo double (leeVector).
• Imprima los datos del vector por pantalla (escribeVector).
• Sume los elementos mayores que cero del vector (sumaPositivos).
*/
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"


int main(){

    int n;
    printf("Dime que tamaño deseas que tenga el vector: ");
    scanf("%d", &n);

    double vector[n];

    leeVector (vector, n);

    escribeVector(vector, n);

    sumaPositivos(vector, n);
    return 0;
}