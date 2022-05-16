/*
Construye un programa que gestione, mediante ficheros binarios, el stock de libros de una
librería. Para cada libro se almacenará la siguiente estructura:
    struct libro {
        char titulo[100];
        char autor[50];
        float precio;
        int unidades;
    }
El programa contará con un menú que permitirá realizar las siguientes operaciones:
• Comprobar la existencia de un determinado libro buscando por su título.
• Introducir un nuevo libro en el stock.
• Contar el número de libros (títulos) diferentes que hay en el stock. Considera que no puede
haber títulos de libros repetidos en el fichero.
• Listar los libros en el stock almacenándolos previamente en un vector dinámico
• Vender n unidades de un libro buscándolo por su título. Si hay menos de n unidades en el
stock, se venderán solo las unidades disponibles.
• Borrar aquellos registros con 0 unidades disponibles.
• Salir.
El nombre del fichero se pasará como argumento en la línea de órdenes.
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(int argc, char** argv){
    
    if(argc!=2){
        printf("\n  --> Error, sintaxis debe ser: <nombre.ejecutable> <nombre.programa>\n");
        exit(-1);
    }

    existe_fichero(argv[1]);

    int opcion_menu;
    struct libro* vec;

    imprimir_menu();
    printf("\n---> ");
    scanf("%d", &opcion_menu);

    while(opcion_menu!=7){

        switch (opcion_menu)
        {
        case 1: //comprobar existencia

            printf("\n  Introduce el numero titulo que desea buscar: ");
            char titulo[100];
            scanf("%s", titulo);

            if(comprobar_existencia(argv[1], titulo)==1){
                printf("\n  --> El libro ya existe\n");
            } else {
                printf("\n  --> El libro no existe\n");
            }
            break;
        case 2: //crear libro nuevo
            anadir_libro(argv[1]);
            break;
        case 3: //contar libros
            printf("\n  --> Hay %d libros en stock\n", contar_registros(argv[1]));
            break;
        case 4:; //listar todos los elementos
            struct libro* vec;
            int nele = contar_registros(argv[1]);
            vec = reservar_memoria(nele);

            listar_libros(vec, argv[1], nele);

            free(vec);

            break;
        case 5: //vender libros
            vender_libros(argv[1]);
            break;
        case 6: //borrar libros con 0 unidades
            borrar_libros(argv[1]);
            break;
        case 7:

            break;        
        default:
            printf("\n  --> Error, debes de seleccionar una opcion del menu\n");
            break;
        }

        imprimir_menu();
        printf("\n---> ");
        scanf("%d", &opcion_menu);
    }

    printf("\n  --> Fin del programa\n\n");
    return 0;
}