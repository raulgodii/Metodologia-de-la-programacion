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

int comprobar_existencia(char* nombre);

#endif