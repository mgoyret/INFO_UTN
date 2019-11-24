all:
	gcc -c functions.c -o functions.o -Wall
	gcc -c main.c -o main.o -Wall
	gcc functions.o main.o -o program
	rm *.o
clean:
	rm program