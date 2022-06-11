#Fichero Makefile

destino simbolico: crucigrama.x clean

crucigrama.x: main.o ficheros.o crucigrama.o liberaMemoria.a
	@echo Creando ejecutable...
	@gcc -o crucigrama.x main.o ficheros.o crucigrama.o liberaMemoria.a
main.o: main.c
	@gcc -c main.c
ficheros.o: ficheros.c
	@gcc -c ficheros.c
crucigrama.o: crucigrama.c
	@gcc -c crucigrama.c
liberaMemoria.a: liberaMemoria.o reservaMemoria.o
	@echo Creando biblioteca...
	@ar -rsv liberaMemoria.a liberaMemoria.o reservaMemoria.o
reservaMemoria.o: reservaMemoria.c
	@gcc -c reservaMemoria.c
liberaMemoria.o: liberaMemoria.c
	@gcc -c liberaMemoria.c
.PHONY: clean

clean:
	@echo Borrando archivos .o...
	@rm *.o