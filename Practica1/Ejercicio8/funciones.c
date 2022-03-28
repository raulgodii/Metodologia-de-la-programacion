#include <string.h>
#include <ctype.h>

void estadisticasCadena(char cad[], int na, int *ndig, int *nmay, int *nmin, int *nesp){
    for(int i=0; i<na; i++){
        if(isdigit(cad[i])){
            (*ndig)++;
        }
    }

    for(int i=0; i<na; i++){
        if(isupper(cad[i])){
            (*nmay)++;
        }
    }

    for(int i=0; i<na; i++){
        if(islower(cad[i])){
            (*nmin)++;
        }
    }

    for(int i=0; i<na; i++){
        if(cad[i]==' '){
            (*nesp)++;
        }
    }
}