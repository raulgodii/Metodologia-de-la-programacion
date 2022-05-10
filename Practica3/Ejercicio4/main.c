/*
4. Construye un programa que gestione mediante ficheros de texto el stock de libros de una librería.
Para cada libro se almacenarán tres líneas en un fichero de texto (stock):
• en la primera línea el título,
• en la segunda línea el autor,
• y en la tercera línea el precio y las unidades disponibles del libro.
El programa contará con un menú que permitirá realizar las siguientes operaciones:
• Comprobar la existencia de un determinado libro en el stock buscando por su título.
• Introducir un nuevo libro en el stock.
• Contar el número de libros (títulos) diferentes que hay en el stock. Considera que no puede
haber títulos de libros repetidos en el fichero.
• Listar los libros en el stock almacenándolos previamente en un vector dinámico.
• Vender n unidades de un libro buscándolo por su título. Si hay menos de n unidades en el
stock, se venderán solo las unidades disponibles.
• Borrar aquellos registros con 0 unidades disponibles.
• Salir.
El nombre del fichero se pasará como argumento en la línea de órdenes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){

    FILE *f;
    char nombre[50];
    int opcion;

        printf("\nEspecifique el nombre del fichero con el que desea trabajar: ");
        scanf("%s", nombre);
        f=fopen(nombre, "r");

        if(f==NULL){
            printf("\nError, el fichero no existe, ¿Desea crear uno nuevo?");
            printf("\n(1) Si");
            printf("\n(2) No");
            printf("\n--> ");

            int si_no;
            scanf("%d", &si_no);

                if(si_no==1){
                    f=fopen(nombre, "w");
                    printf("\n -->Fichero creado \n");
                    fclose(f);
                } else {
                    printf("\n --> Fin del programa\n");
                    exit(-1);
                }
        } else{
            fclose(f);
        }

    do{
        imprimir_menu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:; //Comprobar la existencia de un determinado libro en el stock buscando por su título
            
            char nombre_libro[50];

            printf("\nDime el nombre del libro que deseas buscar: ");
            scanf("%s", nombre_libro);

            if(buscar_titulo(&f, nombre, nombre_libro)==1){
                printf("\n --> El libro ya existe\n");
            } else{
                printf("\n --> El libro no existe \n");
            }
            break;
        case 2: //Introducir un nuevo libro en el stock
            // Titulo
            // Autor
            // Precio   Unidades    
            
            introducir_libro(&f, nombre);
            break;
        case 3: //Contar el número de libros (títulos) diferentes que hay en el stock. Considera que no puede haber títulos de libros repetidos en el fichero
            
            printf("\n --> Existe %d libros diferentes\n", cont_libros(&f, nombre));
            break;
        case 4: //Listar los libros en el stock almacenándolos previamente en un vector dinámico

            
            break;
        case 5:; //Vender n unidades de un libro buscándolo por su título. Si hay menos de n unidades en el stock, se venderán solo las unidades disponibles
            char nombre2_libro[50];

            printf("\nDime el nombre del libro que deseas buscar: ");
            scanf("%s", nombre2_libro);

            if(buscar_titulo(&f, nombre, nombre2_libro)==1){
                vender_libro(&f, nombre, nombre2_libro);
            } else{
                printf("\n --> El libro no existe \n");
            }

            break;
        case 6: //Borrar aquellos registros con 0 unidades disponibles

            break;
        case 7: //Salir
            break;
        
        default:
        printf("\nError, debes de seleccionar una opcion del menu");

        } 
    } while (opcion!=7);
    return 0;
}