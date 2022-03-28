/*
6. Crea una biblioteca (libMatrices.a) a partir de las cuatro funciones del ejercicio 4
(reservarMemoria, liberarMemoria, rellenaMatriz e imprimeMatriz) y su correspondiente
fichero de cabecera. Reproduce los resultados del ejercicio 4, pero esta vez haciendo uso de la
biblioteca creada (por tanto sólo necesitarás un main(), la inclusión del .h de la biblioteca y
enlazar con ella). Utiliza Doxygen para documentar todas las funciones de la biblioteca.
*/

gcc -c main_4.c (creamos el .o)
gcc -c funciones_4.c (creamos el .o)

ar -rsv libMatrices.a funciones_4.o

gcc -o main4.exe main_4.o libMatrices.a