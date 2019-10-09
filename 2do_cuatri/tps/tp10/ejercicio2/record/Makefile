all:
	gcc -c functions.c -o functions.o -Wall
	gcc -c record.c -o record.o -Wall
	gcc functions.o record.o -o program
	rm *.o
clean:
	rm program
