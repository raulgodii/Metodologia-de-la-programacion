#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int* reservar_vector(int nele){
    
    int* vec;
    
    if ((vec = (int*)calloc(nele, sizeof(int)))==NULL){
        printf("\n Error, la memoria no pudo ser reservada");
        exit(-1);
    }

    return vec;
}

void rellenar_vector(int* vec, int nele, int superior, int inferior){
    time_t t;
    srand(time(&t));

    for(int i=0; i<nele; i++){
        vec[i]=rand()%(superior-inferior+1)+inferior;
    }
}

void escribir_fichero(char* nombre, int nele, int* vec){

    FILE *f;
    f=fopen(nombre, "wb");   
    if(f==NULL){
        printf("\n Error, el fichero no pudo abrirse\n");
        exit(-1);
    }

    fwrite(vec, sizeof(int), nele, f);

    fclose(f);
}

void visualizar_fichero(char* nombre, int nele){
    int vec[nele];

    FILE* f;
    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\nError, el fichero no pudo abrirse\n");
        fclose(f);
        exit(-1);
    }

    fread(vec, sizeof(int), nele, f);

    for(int i=0; i<nele; i++){
        printf("\n  V[%d]=%d", i, vec[i]);
    }

    printf("\n");
    fclose(f);

}