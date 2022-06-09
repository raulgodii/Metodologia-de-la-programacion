/*
2. Dada la siguiente estructura:
    struct alumno {
     char nombre[50];
     int DNI;
     float nota;
    };
• Escribe un programa que rellene un vector dinámico de tipo struct alumno y lo ordene
mediante el método de ordenación básico que prefieras (selección, inserción o burbuja).
• El vector dinámico se rellenará a partir de los datos de un fichero binario.
• La ordenación se hará usando como campo clave el DNI y podrá ser ascendente o
descendente.
• Para realizar la ordenación en uno u otro sentido, se implementará una única función de
ordenación que, además del vector y el número de elementos, recibirá como parámetro
un puntero a una función de comparación.
• El programa recibirá dos argumentos en la línea de órdenes:
◦ Un entero con el sentido de la ordenación (1=ascendente o 2=descendente).
◦ El nombre del fichero con los datos para rellenar el vector.
• Al terminar el programa, deberá liberar la memoria usada.
*/

#include "prototipos.h"
#include <stdio.h>

void main(int argc, char** argv){


    if(argc!=2){
        printf("\n Error, sintaxis: entero nombre.fichero");
        exit(-1);
    }
}