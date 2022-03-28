/*
7. Codifica una función denominada estadisticasVector que reciba un vector de enteros y calcule,
devolviendo mediante paso de parámetros por referencia, la media, la varianza y la desviación
típica de los datos del vector. Implementa un programa que mediante funciones lea un vector de
enteros, lo imprima por pantalla, calcule las estadísticas y finalmente muestre los resultados.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    
    float media, varianza, dt;
    int n;

    printf ("\n Dime cuantos elementos deseas que tenga el vector: ");
    scanf ("%d", &n);

    float v[n];

    for(int i=0; i<n; i++){
        printf("\n Dime el elemento numero %i del vector: ", i);
        scanf ("%f", &v[i]);
    }
    
    estadisticasVector(v, n, &media, &varianza, &dt);

    printf("\n Media: %f", media);
    printf("\n Varianza: %f", varianza);
    printf("\n Desviacion tipica: %f \n", dt);

    return 0;
}