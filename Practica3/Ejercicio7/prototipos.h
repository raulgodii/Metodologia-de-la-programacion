#ifndef funciones
#define funciones

struct libro {
        char titulo[100];
        char autor[50];
        float precio;
        int unidades;
};
void existe_fichero(char* nombre);

void imprimir_menu();

int comprobar_existencia(char* nombre, char* titulo);

void anadir_libro(char* nombre);

int contar_registros(char* nombre);

struct libro* reservar_memoria(int nele);

void listar_libros(struct libro* vec, char* nombre, int nele);

void vender_libros(char* nombre);

void borrar_libros(char* nombre);
#endif