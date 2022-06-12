#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

struct nomina* reservar_vector(int nele){
    struct nomina* aux;
    aux=(struct nomina*)malloc(nele*sizeof(struct nomina));
    return aux;
}

void rellena_vector(struct nomina* vec, int nele){
    for(int i=0; i<nele; i++){
        printf("\n Introduce el codigo del empleado %d: ", i);
        scanf("%d", &vec[i].codigo);
        printf("\n Introduce el nombre del empleado %d: ", i);
        fgetc(stdin);
        fgets(vec[i].nombre, 100, stdin);
        printf("\n Introduce las retenciones del empleado %d: ", i);
        scanf("%f", &vec[i].retenciones);
        printf("\n Introduce el salario bruto del empleado %d: ", i);
        scanf("%f", &vec[i].salarioBruto);
    }
}

int ordena_nombre(const void* x_void, const void* y_void){
    struct nomina* x = (struct nomina*)x_void;
    struct nomina* y = (struct nomina*)y_void;

    return strcmp(x->nombre, y->nombre);
}

int ordena_salario(const void* x_void, const void* y_void){
    struct nomina* x = (struct nomina*)x_void;
    struct nomina* y = (struct nomina*)y_void;

    int xx = x->salarioBruto - (x->salarioBruto*(x->retenciones/100));
    int yy = y->salarioBruto - (y->salarioBruto*(y->retenciones/100));

    return yy - xx;
}

void imprimir_vector_recursivo(struct nomina* vec, int nele, int i){
    if(i==nele){
        return;
    }
    printf("\n --> Empleado %d: ", i);
    printf("\n Nombre: %s", vec[i].nombre);
    printf("\n Codigo: %d", vec[i].codigo);
    printf("\n Retencioens: %f", vec[i].retenciones);
    printf("\n Salario bruto: %f", vec[i].salarioBruto);
    return imprimir_vector_recursivo(vec, nele, i+1);
}

void imprimir_vector_salarioNeto(struct nomina* vec, int nele){
    int salario_neto;
    for(int i=0; i<nele; i++){
        salario_neto=vec[i].salarioBruto - (vec[i].salarioBruto*(vec[i].retenciones/100));
        printf("\n --> Empleado %d: ", i);
        printf("\n Codigo: %d", vec[i].codigo);
        printf("\n Nombre: %s", vec[i].nombre);
        printf("\n Salario neto: %d", salario_neto);
    }
}

void imprimir_vector_nombre(struct nomina* vec, int nele){
    for(int i=0; i<nele; i++){
        printf("\n --> Empleado %d: ", i);
        printf("\n Nombre: %s", vec[i].nombre);
        printf("\n Codigo: %d", vec[i].codigo);
        printf("\n Retencioens: %f", vec[i].retenciones);
        printf("\n Salario bruto: %f", vec[i].salarioBruto);
    }
}