/**
 * @file funciones.c
 * @author raulgodii
 * @brief funciones del programa
 * @version 1.0
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///FUNCIONES

/**
 * @fn es_prefijo
 * @brief funcion que determina si es prefijo o no
 * 
 * @param cad 
 * @param prefijo 
 * @return ninguno
 */
void es_prefijo(char cad[], char *prefijo){

    char* p;
    int lpref=strlen(prefijo);
    int cont=0; 

    p=strstr(cad, prefijo);

    if(p==NULL){
        printf("\n No existe el prefijo en la cadena \n");
    } else {
        /*for(int i=0; i<lpref; i++){
            if(cad[i]==prefijo[i]){
                cont++;
            }
        }
        */
       for(int i=0; i<lpref; i++){
            if(*(p+i) == prefijo[i] ){
                cont++;
            }
        }
        if(cont==lpref){
            printf("\n Si existe el prefijo en la cadena \n");
        } else{
            printf("\n No existe el prefijo en la cadena \n");
        }
    }

  
}

/**
 * @fn es_sufijo
 * @brief funcion que determina si es sufjo o no
 * 
 * 
 * @param cad 
 * @param sufijo 
 * @return ninguno
 */
void es_sufijo(char cad[], char *sufijo){

    char* p;
    int lsuf=strlen(sufijo);
    int lcad=strlen(cad);
    int cont=0; 

    p=strstr(cad, sufijo);

    if(p==NULL){
        printf("\n No existe el sufijo en la cadena \n");
    } else {
        
        /*for(int i=lcad; i>(lcad-lsuf); i--){
            if(cad[i]==sufijo[i-(lcad-lsuf)]){
                cont++;
            }
        }
        */

        for(int i=0; i<lsuf; i++){
            if(*(p+i) == sufijo[i] ){
                cont++;
            }
        }

        if(cont==lsuf){
        printf("\n Si existe el sufijo en la cadena \n");
        } else {
        printf("\n No existe el sufijo en la cadena \n");
    }
    }
    
}
