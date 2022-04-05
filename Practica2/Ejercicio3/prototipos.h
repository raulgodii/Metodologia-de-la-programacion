
struct Ficha_jugador {
 char nombre[50];
 int dorsal; /* Nº entero */
 float peso; /* Expresado en kilos */
 int estatura; /* Expresado en centímetros*/
};

void reservarmemoria(struct Ficha_jugador **jugador, int n);
struct Ficha_jugador rellena_jugador();
void introducir_jugadores(struct Ficha_jugador* jugador, int n);
void imprimir_jugadores(struct Ficha_jugador* jugador, int n);
void borra_jugadores(struct Ficha_jugador* jugador, int* n);