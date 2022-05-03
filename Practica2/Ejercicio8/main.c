/* 8. Escribe una solución recursiva que calcule el algoritmo de Euclides, usado para calcular el
máximo común divisor de dos enteros.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){

    printf("Dime dos numeros para calcular su mcd: \n");
    int num1, num2;
    printf("Num 1: ");
    scanf("%d", &num1);
    printf("\nNum 2: ");
    scanf("%d", &num2);

    printf("\n  MCD(%d, %d) = %d\n", num1, num2, mcd (num1, num2));

    return 0;
}