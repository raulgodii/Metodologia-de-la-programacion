#ifndef funciones
#define funciones

struct nodo{
    int c; //coeficiente
    int e; //exponente
    struct nodo* sig; //siguiente nodo
};

void imprimir_menu();

int buscar_monomio(struct nodo* cabeza, int e);

struct nodo* nuevo_monomio();

void insertar_monomio(struct nodo** cabeza, int e, int c);

void evaluar_polinomio(struct nodo* cabeza, int x);

#endif