/*
9. Un monomio (5x3) puede codificarse en C mediante una estructura con dos campos enteros
coeficiente y grado (ej. coeficiente=5, grado=3). Por su parte, un polinomio es una sucesión de
monomios de diferente grado (5x3 + 7x2 + 4x5).
a) Implementa una función denominada leerMonomio, que reciba una estructura pasada por
referencia y permita leer los datos de un monomio.
b) Implementa una función denominada imprimirMonomio, que reciba una estructura por
valor y muestre el coeficiente y el grado del monomio.
c) Utilizando las funciones anteriores, en el programa principal lee y escribe un polinomio
(vector de monomios).
d) Crea una función que, usando paso de parámetros por referencia, devuelva el monomio de
mayor grado y el de menor grado. Utilízala en tu programa.
e) Crea un función que evalúe un polinomio en un punto X. Utilízala en tu programa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){
    
    int nm;
    printf("\n Dime el numero de monomios que tendra tu polinomio: ");
    scanf("%d", &nm);

    printf("\n Perfecto, tu polinomio tendra %d monomios, a continuacion introduce los monomios: \n", nm);
    
    struct monomio polinomio[nm];

    leerMonomio(polinomio, nm);
    
    printf("\n");

    imprimirMonomio(polinomio, nm);

    MayorMenorGrado(polinomio, nm);

    printf("\n");

    int valor;
    printf("\nA continuacion, dime un valor para evaluar el polinomio: ");
    scanf("%d", &valor);

    int resultado = evaluaPolinomio(polinomio, nm, valor);
    printf("\n P(%d) = %d \n", valor, resultado);

    return 0;
}