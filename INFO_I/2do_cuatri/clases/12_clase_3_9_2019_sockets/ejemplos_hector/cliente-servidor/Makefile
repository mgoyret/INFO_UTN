all:
	gcc -c cliente.c -o cliente.o -Wall
	gcc -c servidor.c -o servidor.o -Wall
	gcc servidor.o -o servidor
	gcc cliente.o -o cliente
	rm *.o
clean:
	rm cliente servidor
