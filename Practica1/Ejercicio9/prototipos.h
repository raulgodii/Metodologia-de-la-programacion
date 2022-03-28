#ifndef funciones
#define funciones
#include <stdio.h>
struct monomio{
    int coeficiente, grado;
};
void leerMonomio(struct monomio polinomio[], int nm);
void imprimirMonomio(struct monomio polinomio[], int nm);
void MayorMenorGrado(struct monomio polinomio[], int nm);
int evaluaPolinomio(struct monomio polinomio[], int nm, int valor);

#endif