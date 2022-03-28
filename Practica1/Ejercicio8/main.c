/*
8. Una cadena de caracteres en C es un vector de caracteres terminado en un carácter especial ('\0').
Este carácter marca la terminación de la cadena y es utilizado por las funciones de cadenas.
Teniendo esto en cuenta, codifica una función denominada estadisticasCadena que reciba una
cadena de caracteres y calcule, devolviendo mediante paso de parámetros por referencia, el
número de dígitos, mayúsculas, minúsculas y espacios que hay en la cadena. Implementa un
programa para probar la función anterior. Utiliza funciones de la librería <ctype.h> para
determinar si un carácter es dígito, mayúscula, etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){

    int na, ndig, nmay, nmin, nesp;
    char cad[100]; //="Hola Ma n1gga";
    ndig=0;
    nmay=0;
    nmin=0;
    nesp=0;

    
    printf("\n Dime la cadena que deseas analizar: ");
    fgets(cad, 100, stdin);
    

    na = strlen (cad);

    estadisticasCadena(cad, na, &ndig, &nmay, &nmin, &nesp);

    printf("\n El numero de digitos en la cadena es: %d", ndig);
    printf("\n El numero de mayusculas en la cadena es: %d", nmay);
    printf("\n El numero de minusculas en la cadena es: %d", nmin);
    printf("\n El numero de espacios en la cadena es: %d \n", nesp);

    return 0;

}