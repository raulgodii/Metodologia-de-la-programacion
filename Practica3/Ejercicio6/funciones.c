
int contar_registros(char* nombre){
    FILE* f;
    long tam;
    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n Error, no pudo abrirse el fichero\n");
        fclose(f);
        exit(-1);
    }

    if(fseek(f, 0L, SEEK_END)){ //devuelve cierto (distinto de 0) si se produce algun error
        printf("\n Error, no se puede usar el fichero\n");
        fclose(f);
        exit(-1);
    }

    tam = ftell(f);
    fclose(f);

    int nres=(tam/sizeof(int));

    return nres;
}

int* reservar_vector(int nele){
    int* vec;
    vec = (int*)calloc(nele, sizeof(int));
    if(vec==NULL){
        printf("\n Error, la memoria no pudo reservarse\n");
        exit(-1);
    }
    return vec;
}

void rellenar_vector(char* nombre, int nele, int* vec){
    FILE* f;
    f=fopen(nombre, "rb");
    if(f==NULL){
        printf("\n Error, no pudo abrirse el fichero\n");
        fclose(f);
        exit(-1);
    }

    fread(vec, sizeof(int), nele, f);

}

int suma_pares(int* vec, int nele){
    int suma=0;
    for(int i=0; i<nele; i++){
        if(v[i]%2==0){
            suma+=v[i];
        }
    }
    return suma;
}