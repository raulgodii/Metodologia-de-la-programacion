/*
2. Explica el significado de cada una de las siguientes declaraciones, así como el valor inicial que
toman las variables en cada caso:
a) int *px;
b) float a, b;
c) float *pa, *pb;
d) float a=-0.167;
e) float *pa =&a;
f) char c1, c2, c3;
g) char *pcl, *pc2, *pc3 =&cl;
*/

#include <stdio.h>


int main(){

    printf("\n a) int *px;			Crea un puntero con valor inicial basura");
    printf("\n b) float a, b;			Crea 2 variables float con valor inicial basura");
    printf("\n c) float *pa, *pb;		Crea 2 punteros a flotantes con valor inicial basura");
    printf("\n d) float a=-0.167;		Crea un flotante con valor inicial -0.167");
    printf("\n e) float *pa =&a;		Crea un puntero float apuntando a a");
    printf("\n f) char c1, c2, c3;		Crea 3 caracteres de tipo char con valor inicial basura");
    printf("\n g) char *pcl, *pc2, *pc3 =&cl;	Crea 3 punteros a caracteres, con los 2 primeros valor basura, tercero apuntando a c\n");

}