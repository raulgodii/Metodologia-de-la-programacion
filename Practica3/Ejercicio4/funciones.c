#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir_menu(){
    printf("\n -Seleccione una opcion: \n \n 1. Comprobar la existencia de un determinado libro en el stock buscando por su título \n 2. Introducir un nuevo libro en el stock \n 3. Contar el número de libros (títulos) diferentes que hay en el stock. Considera que no puede haber títulos de libros repetidos en el fichero \n 4. Listar los libros en el stock almacenándolos previamente en un vector dinámico \n 5. Vender n unidades de un libro buscándolo por su título. Si hay menos de n unidades en el stock, se venderán solo las unidades disponibles \n 6. Borrar aquellos registros con 0 unidades disponibles \n 7. Salir \n");
    printf("--> ");
}

bool buscar_titulo(FILE** f, char* nombre, char* nombre_libro){
    *f=fopen(nombre, "r");

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
    if((buscar_titulo(&(*f), nombre, titulo))==1){
        printf("\n --> Error, el libro ya existe \n");
        return;
    }
    
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

int cont_libros(FILE** f, char* nombre){
    int cont=0;
    int i=0;
    char titulo[50];

    while(!feof(*f)){
        if(fgetc(*f)=='\n'){
            i++;
        }
        if(i==7){
            i=0;
            cont++;
        }
    }
    return cont;
}

void vender_libro(&f, nombre, nombre_libro){
    int cont=0;

    while(!feof(*f)){
        int n = 0;
        *f=fopen(nombre, "r");
        fscanf(*f, "%s", nombre_leido);
            if (strstr(nombre_libro, nombre_leido)!=NULL){
                while(cont<4){
                    if(fgetc(*f)=='\n'){
                        cont++;
                    }
                    if(cont==4){
                        float precio;
                        int unidades;
                        int u_vendidas;
                        fscanf(*f, "%f %d", &precio, &unidades);
                        printf("\n Introduce el numero de unidades que deseas vender: ");
                        printf("\n --> ");
                        scanf("%d", &u_vendidas);

                        unidades=unidades-u_vendidas;
                        if(unidades<0){
                            printf("\n --> Error, el numero de unidades disponibles era %d, se han vendido todas", unidades+u_vendidas);
                            unidades=0;
                        }

                        FILE** aux;
                        aux=fopen("aux.txt", "w");
                        
                        while(!feof(*f)){
                            int i;
                            i = fgetc(*f);
                            if()
                            fputc(i, aux);
                        }
                    }
                }
            }
    }    
}