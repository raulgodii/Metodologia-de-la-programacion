#include <stdio.h>
#include <stdlib.h>

float media (FILE** f){
    int aux, val;
    int suma=0;
    int i=0;
    while((aux = fscanf(*f, "%d", &val))!=EOF){
        suma = suma + val;
        i++;
    }
    float j = (float)i;
    float sum = (float)suma;
    float media = sum/j;
    return media;
}