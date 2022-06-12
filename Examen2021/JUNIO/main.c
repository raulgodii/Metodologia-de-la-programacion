#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void main(){

    //Creamos un vector dinamico
    struct nomina* vec;
    int nele;
    printf("\n Introduce el numero de empleados: ");
    scanf("%d", &nele);
    vec = reservar_vector(nele);

    //Rellenamos el vector
    rellena_vector(vec, nele);

    //Imprimir de forma recursiva
    printf("\n El vector ordenado de forma recursiva queda tal que: ");
    imprimir_vector_recursivo(vec, nele, 0);
    printf("\n\n");

    //Ordenar
    printf("\n El vector ordenado de forma ascendente por salario neto queda tal que: ");
    qsort(vec, nele, sizeof(struct nomina), ordena_salario);
    imprimir_vector_salarioNeto(vec, nele);
    printf("\n\n");

    printf("\n El vector ordenado de forma descendente por nombre queda tal que: ");
    qsort(vec, nele, sizeof(struct nomina), ordena_nombre);
    imprimir_vector_nombre(vec, nele);
    printf("\n\n");
}