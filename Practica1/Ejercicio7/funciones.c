#include <math.h>
void estadisticasVector(float v[], int n, float *media, float *varianza, float *dt){
    float suma=0;
    float suma2=0;

    for(int i=0; i<n; i++){
        suma=suma+v[i];
        suma2+=v[i]*v[i];
    }

    *media = suma/n;
    *varianza=(suma2/(n)-((*media) * (*media)));
    *dt=sqrt(*varianza);

}