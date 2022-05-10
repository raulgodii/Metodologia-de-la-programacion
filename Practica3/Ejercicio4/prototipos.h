#include <stdbool.h>

void imprimir_menu();
bool buscar_titulo(FILE** f, char* nombre, char* nombre_libro);
void introducir_libro(FILE** f, char* nombre);
int cont_libros(FILE** f, char* nombre);