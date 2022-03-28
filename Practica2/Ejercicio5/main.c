/**
5. Escribe un programa que lea una frase y, a partir de ella, cree un vector dinámico de cadenas con
las diferentes palabras de la frase. A partir de este vector, el programa deberá:
● Calcular la longitud media de las palabras de la frase, así como la longitud mayor y menor
(usando paso de parámetros por referencia).
● Construir un vector dinámico con la frecuencia de aparición de cada longitud.
Realiza una adecuada modularización, implementando todas las funciones que sean necesarias.
Suponer que las palabras de la frase están separadas por un único espacio en blanco.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int na=100;
    char cad[na];

    printf("\n Dime la cadena: ");
    fgets(cad, na, stdin);

    printf("\n %s", cad);
}