/*
6. Proyecto de pasatiempos
• Descripción
◦ Para el desarrollo de un proyecto sobre pasatiempos, se tienen los siguientes
ficheros:
▪ reservaMemoria.c
  • funciones para la reserva de memoria de diferentes estructuras de datos
▪ liberaMemoria.c
  • funciones para liberar memoria
▪ memoria.h
  • prototipos de las funciones de reserva y liberación de memoria
▪ ficheros.c – ficheros.h
  • funciones relacionadas con la E/S de datos en archivos y sus prototipos
▪ crucigrama.c – crucigrama.h
  • funciones específicas para la creación de crucigramas y sus prototipos
▪ main.c
  • programa que llama a las funciones de los crucigramas y ficheros

◦ El resultado final del proyecto será el ejecutable crucigrama.x que permitirá la
creación de crucigramas.
• Objetivo
◦ Crea un fichero makefile con las siguientes características:
▪ Construirá una biblioteca (libMemoria.a) a partir de los ficheros objeto (.o) de
reservaMemoria.c y liberaMemoria.c.
▪ Construirá el ejecutable crucigrama.x a partir de la biblioteca y los ficheros
objeto (.o) de main.c, ficheros.c y crucigrama.c
▪ Permitirá eliminar los ficheros objeto generados mediante un destino phony
llamado clean.
▪ Incluirá un destino simbólico para generar el ejecutable y eliminar los ficheros
objeto generados con una sola llamada a make.
▪ Para probarlo, puedes utilizar los ficheros que se encuentran en Moodle.
*/

/*! 
    \file main.c
    \brief  Programa principal que permite resolver un crucigrama
    \note Metodología de la Programación
    \note Práctica 4
    \note Curso académico 2014-2015
*/

#include <stdio.h>
#include "ficheros.h"
#include "memoria.h"
#include "crucigrama.h"

/*!
 \fn int main()
 \brief Programa principal
 */
int main(){

  /* Comprueba si existe el fichero */
   existeFichero();

   /* Carga el fichero */
   cargaFicheroBinario();

   /* Reserva memoria para el crucigrama */
   reservaCrucigrama();

   /* Crea el crucigrama */
   creaCrucigrama();

   /* Imprime el crucigrama */
   imprimeCrucigrama(); 

   /* Se librera la memoria */
   liberaCrucigrama();  
      
   return 0;
}   

