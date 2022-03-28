/*
4. Un programa de C contiene las siguientes sentencias
float a = 0.001;
float b = 0.003;
float c, *pa, *pb;
pa = &a;
*pa = 2 * a;
pb = &b;
c = 3 * (*pb + *pa );
Si el valor asignado a la variable a empieza en la dirección 1130 (hexadecimal) , el valor asignado a
la variable b empieza en 1134, y el valor asignado a la variable c empieza en 1138, entonces, tras
ejecutar todas las sentencias:
a) ¿Qué valor es representado por &a?
b) ¿Qué valor es representado por &b?
c) ¿Qué valor es representado por &c?
d) ¿Qué valor es asignado a pa?
e) ¿Qué valor es representado por *pa?
f) ¿Qué valor es representado por &(*pa)?
g) ¿Qué valor es asignado a pb?
h) ¿Qué valor es representado por *pb?
i) ¿Qué valor es asignado a c?
*/

#include <stdio.h>

int main(){

    float a = 0.001;
    float b = 0.003;
    float c, *pa, *pb;
    pa = &a;
    *pa = 2 * a;
    pb = &b;
    c = 3 * (*pb + *pa );

    printf("\n a) Que valor es representado por &a? La direccion de memoria de a (1130)");
    printf("\n b) Que valor es representado por &b? La direccion de memoria de b (1134)");
    printf("\n c) Que valor es representado por &c? La direccion de memoria de c (1138)");
    printf("\n d) Que valor es asignado a pa? &a (1130)");
    printf("\n e) Que valor es representado por *pa? a (0,002)");
    printf("\n f) Que valor es representado por &(*pa)? La direccion de memoria de a (1130)");
    printf("\n g) Que valor es asignado a pb? &b (1134)");
    printf("\n h) Que valor es representado por *pb? b (0,003)");
    printf("\n i) Que valor es asignado a c? 0,015 \n");

}