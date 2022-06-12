#ifndef funciones
#define funciones

struct nomina{
    int codigo;
    char nombre[100];
    float retenciones;
    float salarioBruto;
};

struct nomina* reservar_vector(int nele);

void rellena_vector(struct nomina* vec, int nele);

int ordena_nombre(const void* x_void, const void* y_void);

int ordena_salario(const void* x_void, const void* y_void);

void imprimir_vector_recursivo(struct nomina* vec, int nele, int i);

void imprimir_vector_salarioNeto(struct nomina* vec, int nele);

void imprimir_vector_nombre(struct nomina* vec, int nele);

#endif