all:
	gcc -c main.c -o main.o -Wall
	gcc -c functions.c -o functions.o -Wall
	gcc *.o -o program
	rm *.o

clean:
	rm *.o program

view:
	cat Makefile

edit:
	nano Makefile
