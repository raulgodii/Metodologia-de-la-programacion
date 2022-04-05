/*
3. Escribe un programa que permita gestionar los jugadores de baloncesto del equipo de una ciudad.
Para ello se guardará la información de cada jugador en la siguiente estructura:

struct Ficha_jugador 

El programa realizará secuencialmente las siguientes operaciones:
a) Crear un vector dinámico de jugadores.
b) Listar los jugadores registrados en el equipo, con las características de cada uno de ellos
(dorsal, peso, estatura).
c) Borrar todos los jugadores con una 'a' en su nombre.
d) Listar de nuevo los jugadores.
e) Liberar memoria al terminar.

Deberás implementar al menos las siguientes funciones (también puede utilizar otras funciones
auxiliares que considere oportunas):
● Función para reservar memoria para un vector de estructuras de jugador.
● Función para leer un nuevo jugador. La función pedirá al usuario los datos de un jugador y
los devolverá en una estructura struct Ficha_jugador.
● Función para rellenar un vector de jugadores usando la función para leer un jugador.
● Función para listar los jugadores del equipo.
● Función para borrar jugadores cuyo nombre contenga un carácter que se pasará como
argumento.
◦ Al terminar la ejecución, el vector de jugadores habrá reducido su tamaño usando la
función realloc.
◦ La función devolverá el número de jugadores que quedan en el vector.
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int main(){
    struct Ficha_jugador* jugador;
    int n;

    printf("\nIntroduce el numero de jugadores: ");
    scanf("%d", &n);

    //Reservar memoria
    reservarmemoria(&jugador, n);

    //Introducir jugadores
    introducir_jugadores(jugador, n);

    //Imprimir jugadores
    imprimir_jugadores(jugador, n);

    //Borrar jugadores
    borra_jugadores(jugador, &n);

    //Liberar memoria
    free(jugador);

    return 0;
}
