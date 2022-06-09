/**
1. Dada una función, se desea conocer su valor medio en un intervalo [0, N(. Para ello, se calculará
el valor de la función en todos los valores de x en el intervalo [0, N( con incremento de 0.2 y se obtendrá 
el valor medio.

Realiza un programa que:
a) Solicite al usuario el valor de N.
b) Solicite una función a evaluar: f (x), g(x) ó z(x).
    • f(x) = 3*ex – 2x
    • g(x) = -x * sin(x) +1.5
    • z(x) = x3 -2x +1
c) Muestre el valor medio de la función elegida en el intervalo indicado. Utiliza un puntero a
función para hacer la llamada a la función en el programa principal.
**/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void main(){
    int caso;
    float n;

    printf("-Introduzca el valor de N: ");
    scanf("%f", &n);
    printf("\n -Introduzca la funcion a evaluar: \n");
    printf("\n  1. f(x) = 3*ex – 2x");
    printf("\n  2. g(x) = -x * sin(x) +1.5");
    printf("\n  3. z(x) = x3 -2x +1");

    scanf("%d", &caso);

    float (*funcion) (float);

    do{

    switch (caso)
    {
    case 1:
        funcion = &f;
        break;
    
    case 2:
        funcion = &g;
        break;

    case 3:
        funcion = &z;
        break;
    
    default:
        printf("\n Error, introduce un numero del 1 al 3");
        printf("\n -Introduzca la funcion a evaluar: \n");
        printf("\n  1. f(x) = 3*ex – 2x");
        printf("\n  2. g(x) = -x * sin(x) +1.5");
        printf("\n  3. z(x) = x3 -2x +1");

    scanf("%d", &caso);
        break;
    }

    } while(funcion==NULL);

    printf(" La media de los valores de x del 0 al %f es igual a: %f", n, completa(n, funcion));
}