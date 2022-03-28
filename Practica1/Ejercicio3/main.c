/*
3. Un programa de C contiene las siguientes sentencias
int i, j = 25;
int *pi, *pj = &i;
*pj = j + 5;
i = *pj + 5;
pi = pj;
*pi = i + j;
Si el valor asignado a i empieza en la dirección F9C (hexadecimal) y el valor asignado a j empieza
en FE9 entonces, después de ejecutar todas las sentencias:
a) ¿Qué valor es representado por &i?
b) ¿Qué valor es representado por &j?
c) ¿Qué valor es asignado a pj?
d) ¿Qué valor es asignado a *pj?
e) ¿Qué valor es asignado a i?
f) ¿Qué valor es representado por pi?
g) ¿Qué valor es asignado a *pi?
h) ¿Qué valor es representado por la expresión (*pi + 2)?
*/


#include <stdio.h>


int main(){


    int i, j = 25;
    int *pi, *pj = &i;
    *pj = j + 5;
    i = *pj + 5;
    pi = pj;
    *pi = i + j;

    printf("\n a) Que valor es representado por &i? La direccion de memoria de i");		
    printf("\n b) Que valor es representado por &j? La direccion de memoria de j");		
    printf("\n c) Que valor es asignado a pj? &i");
    printf("\n d) Que valor es asignado a *pj?  i");
    printf("\n e) Que valor es asignado a i? 60");
    printf("\n f) Que valor es representado por pi?  &i");
    printf("\n g) Que valor es asignado a *pi?  i");
    printf("\n h) Que valor es representado por la expresión (*pi + 2)? i+2 = 62 \n");

}