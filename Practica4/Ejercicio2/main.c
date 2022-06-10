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
#include <stdlib.h>
#include <string.h>

void main(int argc, char** argv){


    if(argc!=3){
        printf("\n Error, sintaxis: entero nombre.fichero");
        exit(-1);
    }

    char nombre_fichero [50];
    int sentido;

    strcpy(nombre_fichero, argv[2]);
    sentido = atoi(argv[1]);
    printf("\n %d", sentido);

    if(sentido!=1 && sentido!=2){
        printf("\n Error, el sentido tiene que ser 1(ascendente) o 2 (descendente)");
        exit(-1);
    }

    //Comprobamos existencia fichero
    existe_fichero(nombre_fichero);

    //Rellenamos el fichero
    rellenar_fichero(nombre_fichero);

    //Creamos el vector dinamico
    int nele = contar_registros(nombre_fichero);
    struct alumno* vec = reservar_vector(nele);
    
    //Rellenamos el vector
    rellenar_vector(vec, nele, nombre_fichero);

    //Ordenamos el vector
    if(sentido == 1){ //ascendente
        ordenar_vector(vec, nele, &ascendente);
    }

    if(sentido == 2){ //descendente
        ordenar_vector(vec, nele, &descendente);
    }
    

    //Imprimimos el vector
    imprimir_vector(vec, nele);

    free(vec);
}