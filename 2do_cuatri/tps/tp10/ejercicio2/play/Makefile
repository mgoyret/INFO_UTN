all:
	gcc -c functions.c -o functions.o -Wall
	gcc -c play.c -o play.o -Wall
	gcc functions.o play.o -o program

clean:
	rm *.o
	rm program