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
/*
    if(nombre_libro[strlen(nombre_libro)-1]=='\n'){
        nombre_libro[strlen(nombre_libro)-1]='\0';
    }
*/
    char nombre_leido [50];
    
    while(!feof(*f)){
        fgets(nombre_leido, 50, *f);
            if (strcmp(nombre_libro, nombre_leido)==0){
                return 1;
            }
    }

    return 0;
    fclose(*f);
}

void introducir_libro(FILE** f, char* nombre){

    char titulo[50];
    char autor[50];
    float precio;
    int unidades;

    printf("\nIntroduce el titulo del libro: ");
    fgetc(stdin);
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

    *f=fopen(nombre, "a");
    if(*f==NULL){
        printf("\n //Error, no pudo abrirse el archivo");
        exit(-1);
    }

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

    *f=fopen(nombre, "r");
    if(*f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse");
    }

    while(!feof(*f)){
        if(fgetc(*f)=='\n'){
            i++;
        }
        if(i==7){
            i=0;
            cont++;
        }
    }
    fclose(*f);
    return cont;
}

void vender_libro(FILE** f, char* nombre, char* nombre_libro){
    int cont=0;
    char nombre_leido[50];
    *f=fopen(nombre, "r");
    if(*f==NULL){
        printf("\n  --> Error, el fichero no pudo abrirse");
    }

    while(!feof(*f)){
        int n = 0;
        fgets(nombre_leido, 50, *f);
            if (strcmp(nombre_leido, nombre_libro)==0){
                while(cont<3){
                    if(fgetc(*f)=='\n'){
                        cont++;
                    }
                    if(cont==3){
                        float precio;
                        int unidades;
                        int u_vendidas;
                        fscanf(*f, "%f", &precio);
                        fscanf(*f, "%d", &unidades);
                        printf("\n      Unidades: %d\n", unidades);
                        printf("\n Introduce el numero de unidades que deseas vender: ");
                        printf("\n --> ");
                        scanf("%d", &u_vendidas);

                        unidades=unidades-u_vendidas;
                        printf("\n      Unidades: %d\n", unidades);
                        if(unidades<0){
                            printf("\n  ////////haaaaaaaaaaaaaaaola");
                            //unidades=unidades+u_vendidas;
                            //printf("\n --> Error, el numero de unidades disponibles era %d, se han vendido todas", unidades);
                            printf("\n  ////////hola");
                            unidades=0;
                        }

                        FILE* aux;
                        aux=fopen("aux.txt", "w");
                        
                        while(!feof(*f)){

                            rewind(*f); //para poner el cursor en el principio
                            char titulo[50];
                            char autor[50];
                            float precio;
                            int u;

                            
                            fgets(titulo, 50, *f);
                            if(strcmp(titulo,nombre_libro)==0){
                                fgets(autor, 50, *f);

                                fscanf(*f, "%f", &precio);

                                fprintf(aux, "%s", titulo);
                                fprintf(aux, "\n");

                                fprintf(aux, "%s", autor);
                                fprintf(aux, "\n");

                                fprintf(aux, "%f", precio);
                                fprintf(aux, "   ");

                                fprintf(aux, "%d", unidades);
                                fprintf(aux, "\n\n\n");
                            } else{

                            fgets(autor, 50, *f);

                            fscanf(*f, "%f", &precio);

                            fscanf(*f, "%u", &u);

                            fprintf(aux, "%s", titulo);
                            fprintf(aux, "\n");

                            fprintf(aux, "%s", autor);
                            fprintf(aux, "\n");

                            fprintf(aux, "%f", precio);
                            fprintf(aux, "   ");

                            fprintf(aux, "%d", u);
                            fprintf(aux, "\n\n\n");
                            }
                        }
                        remove(nombre);
                        rename("aux.txt", nombre);

                        fclose(aux);
                    }
                }
            }
        fclose(*f);
    }    
}