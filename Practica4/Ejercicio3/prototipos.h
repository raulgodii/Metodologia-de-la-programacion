#ifndef funciones
#define funciones

struct alumno {
     char nombre[50];
     int DNI;
     float nota;
};

void existe_fichero(char* nombre_fichero);

void rellenar_fichero(char* nombre_fichero);

int contar_registros(char* nombre_fichero);

struct alumno* reservar_vector(int nele);

void rellenar_vector(struct alumno vec[], int nele, char nombre_fichero[]);

void ordenar_vector(struct alumno vec[], int nele);

void imprimir_vector(struct alumno vec[], int nele);

#endif