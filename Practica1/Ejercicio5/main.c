/*
5. Un programa en C contiene la siguiente declaración:
int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};
a) ¿Cuál es el significado de x?
b) ¿Cuál es el significado de (x + 2) ?
c) ¿Cuál es el valor de *x?
d) ¿Cuál es el valor de (*x+2) ?
e) ¿Cuál es el valor de *(x+2)?
*/

#include <stdio.h>


int main(){

    printf("\n 5. Un programa en C contiene la siguiente declaracion: int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};");
    printf("\n a Cual es el significado de x? La primera posicion del vector &(x[0])");
    printf("\n b Cual es el significado de (x + 2)? la tercera posicion del vector &(x[2])");
    printf("\n c Cual es el valor de *x? 10");
    printf("\n d Cual es el valor de (*x+2)? 12");
    printf("\n e Cual es el valor de *(x+2)? 30\n");

}