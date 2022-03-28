/*
12. Un proyecto informático requiere trabajar con vectores de números enteros generados de
manera aleatoria. 
Para hacer más rápido el acceso, han decidido crear dos índices que les permitan recorrer solamente los divisibles por 3 o los elementos impares. 
Un índice, es un vector  de punteros, que almacena la dirección de los elementos que se quieren recorrer. 
Escribe un programa que:
• Rellene un vector de enteros con números aleatorios (en un rango fijado por el usuario).
• Imprima el vector completo.
• Cree un índice con las direcciones de los elementos impares del vector original.
• Cree un índice con las direcciones de los divisibles por 3 que hay en el vector original.
• Imprima, usando los índices, los elementos impares y los divisibles por 3.
Implementa, al menos, las funciones: rellenarVectorAleatorio, imprimirVector, crearndiceImpares,
crearIndicesDivisibles, imprimeIndice.
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int main(){
    int n, rango;

    printf("\n Indica los elementos del vector: ");
    scanf("%d", &n);

    int v[n];

    printf("\n Los numeros del vector se deben contener entre 0 y: ");
    scanf("%d", &rango);

    rellenaVector(v, n, rango);

    imprimeVector(v, n);

    int nimpares=0, ndivisibles=0;
    impares_divisibles(&nimpares, &ndivisibles, v, n);

    int* impares[nimpares];
    int* divisibles[ndivisibles];

    printf("\n");

    indices(v, n, impares, nimpares, divisibles, ndivisibles);

    imprime_indices(impares, nimpares, divisibles, ndivisibles);

    printf("\n");

    return 0;

}