/*10. Dada una cadena c, diseña una función recursiva que cuente la cantidad de veces que aparece un
carácter x en c.
Ejemplo: para c = “elementos de programacion” y x = 'e', el resultado es 4.
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int main(){
    char* cad;
    char cad2[1];

    reserva_cadena(&cad);

    printf("Introduce una cadena: ");
    scanf("%s", cad);

    printf("Introduce una letra a buscar en la cadena: ");
    scanf("%s", cad2);

    printf("El numero de veces que aparece la letra '%s' es: %d \n", cad2, veces(0, cad, cad2));
    return 0;
}