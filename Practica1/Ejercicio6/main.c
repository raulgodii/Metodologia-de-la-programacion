/*
6. Se desea mostrar la equivalencia entre funciones que devuelven un resultado y funciones que utilizan parámetros por referencia.  

a) Primera versión: función denominada minimo
    1. Recibe dos números num1 y num2 de tipo int pasados por valor.
    2. Devuelve como resultado el mínimo de los números num1 y num2 pasados como parámetros.
b) Segunda versión: función denominada minimo_referencia
    1. Recibe dos números num1 y num2 de tipo int pasados por valor.
    2. Recibe otro parámetro denominado resultado de tipo int pero pasado por referencia.
    3. La función debe asignar a resultado el valor del mínimo de num1 y num2.
c) Codifica un programa que permita comprobar el funcionamiento de las dos funciones anteriores.
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int main(){
    int num1, num2,resultado;
    printf("\n Dime el valor del primer numero: ");
    scanf("%d", &num1);
    printf("\n Dime el valor del segundo numero: ");
    scanf("%d", &num2);
    
    resultado = minimo(num1, num2);
    printf("\n El minimo entre los dos numeros pasados por valor es: %d",resultado);
    
    minimo_referencia(num1, num2, &resultado);
    printf("\n El valor minimo de los dos numeros pasados como referencia es: %d \n", resultado);

    return 0;
}