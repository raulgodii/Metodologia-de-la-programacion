#include <stdio.h>
#include <stdlib.h>

    int ** reservarMemoria (int nFil, int nCol){
        int ** matriz;
        
        matriz = (int**) malloc(nFil*sizeof(int*));
        if(matriz == NULL){
            printf("\n Error, la matriz no pudo reservase");
            exit(-1);
        } else {
            printf("\n La memoria ha sido reservada con exito \n");
        }

        for(int i=0; i<nFil; i++){
            matriz[i]=(int*)malloc(nCol*sizeof(int));

            if(matriz [i] == NULL){
            printf("\n Error, la matriz no pudo reservase");
            exit(-1);
            }
        }
        return matriz;
    }

    void rellenaMatriz (int **matriz, int nFil, int nCol){

        for(int i=0; i<nFil; i++){
            for(int j=0; j<nCol; j++){
                printf("\n Dime el valor de matriz[%d][%d]: ", i, j);
                scanf("%d", &(matriz[i][j]));
            }
        }
        printf("\n");
    }

    void imprimeMatriz (int **matriz, int nFil, int nCol){
        printf("La matriz quedaria tal que asi: \n");
        for(int i=0; i<nFil; i++){
            for(int j=0; j<nCol; j++){
                printf("    %d", matriz[i][j]);
            }
            printf("\n");
        }
    }

    int* minCol (int **matriz, int nFil, int nCol){
        int* vector;

        vector = (int*)malloc(nCol*sizeof(int));

        if(vector==NULL){
            printf("\n Error, el vector dinamico no pudo ser reservado");
        }

        for(int j=0; j<nCol; j++){
            vector[j]=matriz[0][j];

            for(int i=0; i<nFil; i++){
                if(matriz[i][j]<vector[j]){
                    vector[j]=matriz[i][j];
                }
            }
        }

        return vector;
    }

    void liberarMemoria(int ***matriz, int nFil){
        
        for(int i=0; i<nFil; i++){
        free((*matriz)[i]);
        }
        free(*matriz);
        (*matriz) = NULL;
    }