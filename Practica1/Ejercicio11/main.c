/*
11. Implementa una programa que permita determinar si una cadena es prefijo o sufijo de otra.
Utiliza la función strstr de la biblioteca <string.h> para implementar:
• Una función que responda al siguiente prototipo: int es_prefijo(char *cadena, char
*prefijo), que compruebe si una cadena es prefijo de otra. La función devolverá 1 si es
prefijo y 0 en otro caso.
• Una función que responda al siguiente prototipo: int es_sufijo(char *cadena, char *sufijo),
que compruebe si una cadena es sufijo de otra. La función devolverá 1 si es sufijo y 0 en
otro caso.
*/

/**
 * @file main.c
 * @author raulgodii
 * @brief funcion main del programa
 * @version 1.0
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prototipos.h"

int main(){
    printf("Dime una cadena: ");
    char cad[100];
    fgets(cad, 100, stdin);
    
    printf("\n Dime un prefijo: ");
    char prefijo[100];
    scanf("%s", prefijo);

    es_prefijo(cad, prefijo);

    printf("\n Dime un sufijo: ");
    char sufijo[100];
    scanf("%s", sufijo);

    es_sufijo(cad, sufijo);
    return 0;
}