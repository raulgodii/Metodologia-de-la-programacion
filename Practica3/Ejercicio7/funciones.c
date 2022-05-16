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

int comprobar_existencia(char* nombre, char* titulo){
    FILE* f;
    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }
    
    struct libro auxiliar;
    while(fread(&auxiliar, sizeof(struct libro), 1, f)==1){
        if(strcmp(auxiliar.titulo, titulo)==0){
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void anadir_libro(char* nombre){
    FILE* f;

    struct libro aux;

    printf("\n  -Introduce el titulo: ");
    scanf("%s", aux.titulo);
    if(comprobar_existencia(nombre, aux.titulo)==1){
        printf("\n  --> El libro ya existe\n");
        return;
    }

    printf("\n  -Introduce el autor: ");
    scanf("%s", aux.autor);

    printf("\n  -Introduce el precio: ");
    scanf("%f", &aux.precio);

    printf("\n  -Introduce : ");
    scanf("%d", &aux.unidades);

    f=fopen(nombre, "ab");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    fwrite(&aux, sizeof(struct libro), 1, f);

    fclose(f);
}

int contar_registros(char* nombre){

    long tam;
    FILE* f;

    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    if(fseek(f, 0L, SEEK_END)){
        printf("\n  --> Error, no se ha podido trabajar con el fichero\n");
        fclose(f);
        exit(-1);
    }

    tam=ftell(f);
    fclose(f);
    return tam/sizeof(struct libro);
}

struct libro* reservar_memoria(int nele){
    struct libro* aux;
    aux = (struct libro*)malloc(nele*sizeof(struct libro));
    
    if(aux==NULL){
        printf("\n  --> Error, la memoria no pudo ser reservada\n");
        exit(-1);
    }
}

void listar_libros(struct libro* vec, char* nombre, int nele){
    FILE* f;

    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    fread(vec, sizeof(struct libro), nele, f);

    for(int i=0; i<nele; i++){
        printf("\n  -LIBRO %d:", i);
        printf("\n  Titulo: %s", vec[i].titulo);
        printf("\n  Autor: %s", vec[i].autor);
        printf("\n  Precio: %f", vec[i].precio);
        printf("\n  Unidades: %d", vec[i].unidades);
        printf("\n");
    }
    fclose(f);
}

void vender_libros(char* nombre){

    char titulo[100];
    int u;
    printf("\n  Introduce el titulo del libro que deseas vender: ");
    fscanf("%s", titulo);
    printf("\n  Introduce las unidades que deseas vender: ");
    fscanf("%d", &u);

    if(comprobar_existencia(nombre, titulo)==1){
        printf("\n  --> El libro ya existe\n");
        return;
    }

    FILE* f, a;
    struct libro aux;

    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    a=fopen("aux.txt", "wb");
    if(a==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse\n");
        fclose(f);
        exit(-1);
    }

    while(!feof(f)){
        fread(&aux, sizeof(struct libro), 1, f);

        if(strcmp(titulo, aux.titulo)==0){
            aux.unidades = aux.unidades - u;
            if(aux.unidades<0){
                aux.unidades = 0;
            }
        }

        fwrite(&aux, sizeof(struct libro), 1, a);
    }

    fclose(f);
    fclose(a);

}