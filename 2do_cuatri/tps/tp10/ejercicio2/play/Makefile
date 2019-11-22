all:
	gcc -c functions.c -o functions.o -Wall
	gcc -c play.c -o play.o -Wall
	gcc functions.o play.o -o play
	rm *.o

clean:
	rm play