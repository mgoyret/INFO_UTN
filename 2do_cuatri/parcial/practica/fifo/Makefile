all:
	gcc -c server.c -o server.o -Wall
	gcc server.o -o server
	gcc -c client.c -o client.o -Wall
	gcc client.o -o client
	rm *.o
clean:
	rm server client
edit:
	code Makefile