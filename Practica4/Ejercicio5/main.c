/*5. Pilas de contenedores
• Descripción
◦ Para mover los contenedores de mercancía de un importante puerto comercial, se
utiliza un método de almacenamiento basado en el concepto de pila.
▪ De este modo, el contenedor situado más abajo en la pila fue el primero que se
apiló, y, para moverlo, es necesario mover a otra pila todos los contenedores que
hay encima de él.
◦ Cada contenedor de mercancía está identificado por un código entero, X.
◦ Por motivos de seguridad, como mucho se pueden apilar N contenedores en una
misma pila.
▪ De este modo, si la pila no está llena, entonces se puede apilar un nuevo
contenedor.
◦ Si se desea sacar un contenedor de código X entonces:
▪ Se deben desapilar previamente los contenedores encima de él colocándolos en
una nueva pila auxiliar.
▪ Se extrae el contenedor X y se vuelven a introducir los contenedores extraídos
previamente.
• Objetivo
◦ Codifica un programa que, utilizando las funciones push (apilar), pop (desapilar), y
vacia que están implementadas en la biblioteca pilas.a, permita gestionar una pila de
contenedores con la siguiente funcionalidad:
▪ Crear una pila de N contenedores.
▪ Listar los contenedores que hay en pila.
• Se muestra por pantalla un listado de los contenedores contenidos en la pila.
▪ Conocer si un contenedor de código X está en la pila.
▪ Sacar el contenedor de código X que puede estar en cualquier posición de la pila.
• NOTA: no se podrá recorrer en ningún caso la pila secuencialmente como si fuera una
lista, sino que solo se hará uso de una pila auxiliar y de las funciones vacia, push y pop. 
*/

#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
    
    int opcion, ncont, nmax, codigo, encontrado, cod;
    ncont=0;

    struct contenedor* cabeza = NULL;
    crear_pila(&cabeza, &nmax); //Creamos la pila
    imprimir_menu();
    printf("\n---> ");
    scanf("%d", &opcion);

    do{
        switch (opcion){
            case 1: //Listar los contenedores de la pila
                if(pilaVacia(cabeza)==1){
                    printf("\n Error, la pila esta vacia");
                } else {
                    imprimir_pila(cabeza);
                }
            break;

            case 2: //Encontrar contenedor por su codigo
                if(pilaVacia(cabeza)==1){
                    printf("\n Error, la pila esta vacia");
                } else {
                    printf("\n Indica el codigo del contenedor: ");
                    scanf("%d", &codigo);
                    encontrado = encontrar_contenedor(cabeza, codigo);
                    if(encontrado == 1){
                        printf("\n El contenedor ha sido encontrado");
                    }
                    if(encontrado == 0){
                        printf("\n El contenedor no ha sido encontrado");
                    }
                }
            break;

            case 3:; //Sacar contenedor por su codigo
                if(pilaVacia(cabeza)==1){
                    printf("\n Error, la pila esta vacia");
                } else {
                    printf("\n Indica el codigo del contenedor: ");
                    scanf("%d", &codigo);
                    encontrado = encontrar_contenedor(cabeza, codigo);
                    if(encontrado == 1){
                        struct contenedor* cabeza_aux=NULL;

                        while(codigo!=cod){
                            cod=pop(&cabeza);   //Retorna el codigo del contenedor desapilado
                            if(cod!=codigo){
                                push(&cabeza_aux, cod); //Apila el contenedor desapilado en una nueva pila
                            }
                        }

                        while(cabeza_aux!=NULL){
                            cod=pop(&cabeza_aux);   //Retorna el codigo del contenedor desapilado
                            push(&cabeza, cod); //Apila el contenedor desapilado en la pila anterior
                        }
                        ncont--;
                    }
                    if(encontrado == 0){
                        printf("\n El contenedor no existe");
                    }
                }
            break;

            case 4: //Añadir nuevo contenedor
                if(nmax==ncont){
                    printf("\n Error, no se pueden anadir mas contenedores");
                } else {
                    printf("\n Indica el codigo del nuevo contenedor: ");
                    scanf("%d", &codigo);
                    encontrado = encontrar_contenedor(cabeza, codigo);
                    if(encontrado == 1){
                        printf("\n El contenedor ya existe");
                    }
                    if(encontrado == 0){
                        push (&cabeza, codigo);
                        ncont++;
                    }
                }
            break;

            case 5: //Salir
                printf("\n  --> Fin del programa\n\n");
                exit(-1);
            break;

            default:
                printf("\n  --> Error, debes de seleccionar una opcion del menu\n");
            break;
        }
        imprimir_menu();
        printf("\n---> ");
        scanf("%d", &opcion);

    } while (opcion!=5);

    printf("\n  --> Fin del programa\n\n");
}
