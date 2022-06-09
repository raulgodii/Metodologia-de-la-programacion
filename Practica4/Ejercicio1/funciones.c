#include <math.h>
#include "prototipos.h"
#define e 2.71

float completa(float n, float (*funcion)(float)){
    float res=0;
    for(float i=0; i<n; i=i+0.2){
        res=res+(*funcion)(i);
    }
    return (res/(n*5));
}

float f(float x){
    return (3*pow(e,x)-2*x);
}

float g (float x){
    return (-x*sin(x)+1.5);
}

float z (float x){
    return (pow(x,3)-2*x+1);
}