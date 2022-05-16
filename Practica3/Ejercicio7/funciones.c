#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void existe_fichero(char* nombre){
    FILE* f;
    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no existe");
        printf("\n ¿Desea crear uno nuevo?\n");
        int respuesta;
        printf("\n Si (1)");
        printf("\n No (2)");
        printf("\n --> ");
        scanf("%d", &respuesta);  

        while(respuesta!=1 || respuesta!=2){
            if(respuesta == 1){
                f=fopen(nombre, "wb");
                if(f==NULL){
                    printf("\n  --> Error, el fichero no se pudo crear\n");
                    exit(-1);
                }
                printf("\n  --> Fichero creado\n");
                fclose(f);
                return;
            }

            if(respuesta == 2){
                printf("\n  --> Fin del programa\n");
                exit(-1);
            }

            printf("\n Especifique solo una de las opciones");
            printf("\n --> ");
            scanf("%d", &respuesta); 
            
        }

    }
    fclose(f);
}

void imprimir_menu(){
    printf("\nSeleccione una opción: \n");
    printf("\n  1. Comprobar la existencia de un determinado libro buscando por su título");
    printf("\n  2. Introducir un nuevo libro en el stock");
    printf("\n  3. Contar el número de libros (títulos) diferentes que hay en el stock");
    printf("\n  4. Listar los libros en el stock almacenándolos previamente en un vector dinámico");
    printf("\n  5. Vender n unidades de un libro buscándolo por su título");
    printf("\n  6. Borrar aquellos registros con 0 unidades disponibles");
    printf("\n  7. Salir");
}

int comprobar_existencia(char* nombre){
    FILE* f;
    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    printf("\n  Introduce el numero titulo que desea buscar: ");
    char titulo[100];
    scanf("%s", titulo);
    
    struct libro auxiliar;
    while(fread(&auxiliar, sizeof(struct libro), 1, f)==1){
        if(strcmp(auxiliar.titulo, titulo)==0){
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void anadir_libro(argv[1], libro){
    FILE* f;
    f=fopen(nombre, "ab");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    if(comprobar_existencia(argv[1])==1){
        printf("\n  --> El libro ya existe\n");
        return;
    }

    struct libro aux;

    printf("\n  -Introduce el titulo: ");
    scanf("%s", aux.titulo);
    if(comprobar_existencia(aux.titulo)==1){
        printf("\n  --> El libro ya existe\n");
        return;
    }

    printf("\n  -Introduce el autor: ");
    scanf("%s", aux.autor);

    printf("\n  -Introduce el precio: ");
    scanf("%f", aux.precio);

    printf("\n  -Introduce : ");
    scanf("%d", aux.unidades);
}