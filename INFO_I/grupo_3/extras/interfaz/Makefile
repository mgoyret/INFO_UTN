all:
	g++ -c main.c -o main.o -Wall
	gcc main.o -o prog `pkg-config --cflags --libs opencv`
	rm *.o