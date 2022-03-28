/*
1. Supón una matriz dinámica (float ** tabla) de 2x3 elementos, con los siguientes valores.
{ {1.1, 1.2, 1.3}, {2.1.,2.2, 2.3}}
● ¿Cual es el significado de tabla?
● ¿Cual es el significado de (tabla+1)?
● ¿Cual es el significado de *(tabla+1)?
● ¿Cual es el significado de (*(tabla+1)+1)?
● ¿Cual es el significado de (*(tabla)+1)?
● ¿Cual es el valor de *(*(tabla+1)+1)?
● ¿Cual es el valor de *(*(tabla)+1)?
● ¿Cual es el valor de *(*(tabla+1))?
*/

#include <stdio.h>
#include <stdlib.h>


void main(){
	float **tabla;
	int nFil=2;
	int nCol=3;
	if((tabla=(float**)calloc(nFil,sizeof(float*)))==NULL){
		exit(-1);
	}

	for(int i=0;i<nFil;i++)
		if((tabla[i]=(float*)calloc(nCol,sizeof(float)))==NULL){
			exit(-1);
		}

	tabla[0][0]=1.1;
	tabla[0][1]=1.2;
	tabla[0][2]=1.3;
	tabla[1][0]=2.1;
	tabla[1][1]=2.2;
	tabla[1][2]=2.3;


	printf("1.tabla,%p \n2.(tabla+1),%p \n3.*(tabla+1),%p \n4.(*(tabla+1)+1),%p \n5.(*(tabla)+1),%p \n6.*(*(tabla+1)+1),%f \n7.*(*(tabla)+1),%f \n8.*(*(tabla+1))%f \n",tabla,(tabla+1),*(tabla+1),(*(tabla+1)+1),(*(tabla)+1),*(*(tabla+1)+1),*(*(tabla)+1),*(*(tabla+1)));
	
	printf("")
}//*(tabla+1),(*(tabla+1)+1),(*(tabla)+1),*(*(tabla+1)+1),*(*(tabla)+1),*(*(tabla+1))