/* 
1. Codifica un programa que utilice la sentencia printf para escribir el tamaño de los tipos de las siguientes variables:
int a, *b, **c;
double d, *e, **f;
char g, *h, **i; 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, *b, **c;
    double d, *e, **f;
    char g, *h, **i;

    printf("\n El tamaño de un entero es de: %lu bytes",sizeof(a));
    printf("\n El tamaño de un puntero a entero es de: %zu bytes",sizeof(b));
    printf("\n El tamaño de un doble puntero a entero es de: %zu bytes",sizeof(c));

    printf("\n El tamaño de un flotante es de: %lu bytes",sizeof(d));
    printf("\n El tamaño de un puntero a flotante es de: %zu bytes",sizeof(e));
    printf("\n El tamaño de un doble puntero a flotante es de: %zu bytes",sizeof(f));

    printf("\n El tamaño de un character es de: %zu bytes",sizeof(g));
    printf("\n El tamaño de un puntero a character es de: %zu bytes",sizeof(h));
    printf("\n El tamaño de un doble puntero a character es de: %zu bytes \n",sizeof(i));

}