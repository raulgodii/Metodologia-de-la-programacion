#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

void crear_pila(struct contenedor** cabeza, int* nmax){
    printf("\n Introduce el numero de contenedores maximos de la pila: ");
    scanf("%d", &(*nmax));

}

void imprimir_menu(){

    printf("\nSeleccione una opcion: \n");
    printf("\n  1. Listar los contenedores de la pila");
    printf("\n  2. Encontrar contenedor por su codigo");
    printf("\n  3. Sacar contenedor por su codigo");
    printf("\n  4. Anadir contenedor");
    printf("\n  5. Salir");

}

void push (struct contenedor ** cabeza, int codigo) {

   struct contenedor * nuevo;
    
   // Se reserva memoria para el nuevo contenedor
   nuevo=nuevoElementoPila();
    
   // Se actualizan los campos del contenedor
   nuevo->codigo=codigo;
   nuevo->sig=*cabeza;
    
   // Se indica que el contenedor es la nueva cabeza de la pila
   *cabeza=nuevo;
}

struct contenedor * nuevoElementoPila()
{
   struct contenedor* nuevo;

   /* Se reserva la memoria para un nuevo contenedor */
   nuevo = (struct contenedor *) malloc(sizeof(struct contenedor));

   if (nuevo == NULL) {
      printf("\nError al reservar memoria para el contenedor\n");
      exit(-1);
   }

   // Se devuelve el contenedor reservado 
   return nuevo;
}

int encontrar_contenedor(struct contenedor* cabeza, int codigo){
    int encontrado;
    encontrado=0;

    struct contenedor* aux = cabeza;

    while(aux!=NULL && encontrado==0){
        if(codigo==aux->codigo){
            encontrado=1;
        }
        aux=aux->sig;
    }
    return encontrado;
}

void imprimir_pila(struct contenedor* cabeza){
    struct contenedor* aux = cabeza;

    while(aux!=NULL){
        printf("\n -Contenedor %d", aux->codigo);
        aux=aux->sig;
    }
}

int pop(struct contenedor ** cabeza){
   struct contenedor * aux;
   int codigo;
    
   // Se accede al contenedor situado en la cabeza de la pila 
   aux=(*cabeza);
    
   // Se copia el valor del campo codigo del contenedor de la cabeza de la pila 
   codigo=(*cabeza)->codigo;
    
   // Se desapila la cima de la pila 
   *cabeza=(*cabeza)->sig;
    
   // Se libera la memoria del contenedor que estaba en la cabeza de la pila 
   free(aux);
    
   // Se devuelve el número que estaba en la cabeza de la pila 
   return codigo;
}

int pilaVacia(struct contenedor * cabeza){
    
   // Se comprueba si la pila está vacía 
   if (cabeza==NULL)
      return 1;
   // En caso contrario 
   else
      return 0;
}