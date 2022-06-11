#ifndef funciones
#define funciones

struct contenedor{
    int codigo; //Codigo de cada contenedor
    struct contenedor* sig; //Puntero a siguiente contenedor
};
void crear_pila(struct contenedor** cabeza, int* nmax);

void imprimir_menu();

void push (struct contenedor ** cabeza, int codigo);

struct contenedor * nuevoElementoPila();

int encontrar_contenedor(struct contenedor* cabeza, int codigo);

void imprimir_pila(struct contenedor* cabeza);

int pop(struct contenedor ** cabeza);

int pilaVacia(struct contenedor * cabeza);
#endif