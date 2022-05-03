/* 9. Construye una función recursiva que calcule la división entera de dos números mediante el
métodos de restas sucesivas. Implementa un pequeño programa para probarla. */

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    printf("Dime dos numeros para dividirlos: ");
    int a, b;
    printf("\n Numero 1: ");
    scanf("%d", &a);
    printf("\n Numero 2: ");
    scanf("%d", &b);

    printf("\n  %d/%d = %d \n", a, b, division(a, b));

    return 0;
}