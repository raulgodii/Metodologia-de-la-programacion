#include <stdio.h>
#include <stdlib.h>
    void reserva (int **vector, int n){
        if ((*vector = (int*)calloc(n, sizeof(int)))==NULL){
            printf("\n Error, la memoria no pudo ser reservada");
            exit(-1);
        } else {
            printf("\n /// Memoria reservada con exito /// \n");
        }
    }

    void rellenar(int vector[], int n){
        printf("\n A continuacion introduce los elementos del vector: \n");
        
        for(int i=0; i<n; i++){
            printf("\n El elemento numero %d del vector es: \n", i);
            scanf("%d", &(vector[i]));
        }
    }

    void imprimir(int vector[], int n, int *cont){
        for(int i=0; i<n; i++){                
            printf("\n vector%d[%d] = %d", *cont, i, vector[i]);
        }
        (*cont)++;
    }

    void comparar(int num, int n, int vector[], int *nmay, int *nmen){
        for(int i=0; i<n; i++){
            if(vector[i]>num){
                (*nmay)++;
            } else {
                (*nmen)++;
            }
        }
        printf("\n Mayores: %d   Menores: %d", *nmay, *nmen);
    }

    void rellena_vectores(int vector[], int n, int mayores[], int nmay, int menores[], int nmen, int num){
        int j=0;
        int h=0;
        for(int i=0; i<n; i++){
            if(vector[i]>num){
                mayores[j]=vector[i];
                j++;
            } else {
                menores[h]=vector[i];
                h++;
            }
        }
    }
    