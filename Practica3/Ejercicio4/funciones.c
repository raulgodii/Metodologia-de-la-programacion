#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir_menu(){
    printf("\n -Seleccione una opcion: \n \n 1. Comprobar la existencia de un determinado libro en el stock buscando por su título \n 2. Introducir un nuevo libro en el stock \n 3. Contar el número de libros (títulos) diferentes que hay en el stock. Considera que no puede haber títulos de libros repetidos en el fichero \n 4. Listar los libros en el stock almacenándolos previamente en un vector dinámico \n 5. Vender n unidades de un libro buscándolo por su título. Si hay menos de n unidades en el stock, se venderán solo las unidades disponibles \n 6. Borrar aquellos registros con 0 unidades disponibles \n 7. Salir \n");
    printf("--> ");
}

bool buscar_titulo(FILE** f, char* nombre){
    *f=fopen(nombre, "r");
    char nombre_libro[50];

    printf("\nDime el nombre del libro que deseas buscar: ");
    scanf("%s", nombre_libro);

    char nombre_leido [50];
    
    while(!feof(*f)){
        fscanf(*f, "%s", nombre_leido);
            if (strstr(nombre_libro, nombre_leido)!=NULL){
                return 1;
            }
    }

    return 0;
    fclose(*f);
}

void introducir_libro(FILE** f, char* nombre){
    *f=fopen(nombre, "a");
    char titulo[50];
    char autor[50];
    float precio;
    int unidades;

    printf("\nIntroduce el titulo del libro: ");
    fgets(titulo, 50, stdin);
    fgets(titulo, 50, stdin);
    
    printf("\nIntroduce el autor del libro: ");
    fgets(autor, 50, stdin);

    printf("\nIntroduce el precio del libro: ");
    scanf("%f", &precio);

    printf("\nIntroduce las unidades disponibles: ");
    scanf("%d", &unidades);

    fprintf(*f, "%s", titulo);
    fprintf(*f, "\n");

    fprintf(*f, "%s", autor);
    fprintf(*f, "\n");

    fprintf(*f, "%f", precio);
    fprintf(*f, "   ");

    fprintf(*f, "%d", unidades);
    fprintf(*f, "\n\n\n");

    printf("\n --> Libro guardado con exito\n");

    fclose(*f);
}