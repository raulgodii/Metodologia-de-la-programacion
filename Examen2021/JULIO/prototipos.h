#ifndef funciones
#define funciones

struct alumno{
    long dni;
    char nombre[100];
    float media;
};

void contar_alumnos(int* na);

struct alumno* reservar_vector(int nele);

void clean(char* nombre);

void crear_fichero(char* nombre, struct alumno* vec);

#endif