all:
	gcc -c servidor.c -o servidor.o -Wall
	gcc -c cliente.c -o cliente.o -Wall
	gcc -c functions.c -o functions.o -Wall
	gcc servidor.o functions.o -o server
	gcc cliente.o functions.o -o client

clean:
	rm -f *.o
	rm -f client server
	rm -f MIFIFO1

view:
	cat Makefile

edit:
	nano Makefile
