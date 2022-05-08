#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void escribir_fichero(FILE** f, int inferior, int superior, int nele){
    
    time_t t;
    srand(time(&t)); //definimos la semilla
    int j=1;

    for(int i=0; i<nele; i++){
        if(j%20==0){
            fprintf(*f, "\n");
        }
        int aleatorio = rand() % (superior-inferior+1)+inferior; //genera un num. aleatorio entre inferior y superior
        fprintf(*f, "%d ", aleatorio);
        j++;
    }
}