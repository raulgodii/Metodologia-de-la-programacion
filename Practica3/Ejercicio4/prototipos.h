#ifndef funciones
#define funciones

#include <stdbool.h>

void imprimir_menu();
bool buscar_titulo(FILE** f, char* nombre, char* nombre_libro);
void introducir_libro(FILE** f, char* nombre);
int cont_libros(FILE** f, char* nombre);
void vender_libro(FILE** f, char* nombre, char* nombre_libro);
int cero_unidades(FILE** f, char* nombre_leido);
void borrar_libro(FILE** f, char* nombre);

#endif