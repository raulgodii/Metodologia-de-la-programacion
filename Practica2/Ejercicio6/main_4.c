/*
4. Escribe un programa que implemente las siguientes funciones sobre matrices dinámicas y las
llame de manera secuencial mostrando, de manera adecuada, la salida por pantalla.
● int ** reservarMemoria (int nFil, int nCol). Reserva memoria para una matriz de nFil filas
y nCol columnas.
● void rellenaMatriz (int **matriz, int nFil, int nCol). Rellena una matriz con valores
aleatorios en el intervalo [1,20].
● void imprimeMatriz (int **matriz, int nFil, int nCol). Imprime una matriz por pantalla. Usa
la notación de aritmética de punteros para recorrer la matriz.
● int * minCol (int **matriz, int nFil, int nCol). Devuelve un vector dinámico con los
mínimos de cada columna.
● void liberarMemoria(int ***matriz, int nFil). Libera la memoria de una matriz reservada
dinámicamente. La función pondrá el puntero matriz a NULL antes de terminar.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos_4.h"


int main(){

    int nFil, nCol;

    int** matriz;

    printf("\n Dime el numero de filas de la matriz: ");
    scanf("%d", &nFil);

    printf("\n Dime el numero de columnas de la matriz: ");
    scanf("%d", &nCol);

    matriz = reservarMemoria (nFil, nCol);

    rellenaMatriz (matriz, nFil, nCol);

    imprimeMatriz (matriz, nFil, nCol);

    int* vector;
    vector = minCol (matriz, nFil, nCol);

    printf("\n MinCol quedaria tal que asi: \n");
        for(int i=0; i<nCol; i++){
            printf("Vector[%d] = %d \n", i, vector[i]);
        }

    liberarMemoria(&matriz, nFil);

    free(vector);

    return 0;
}