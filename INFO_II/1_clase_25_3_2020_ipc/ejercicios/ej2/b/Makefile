all:
	rm -r -f build program
	mkdir build
	gcc -c src/main.c -o build/main.o -Wall
	gcc -c src/functions.c -o build/functions.o -Wall
	gcc build/main.o build/functions.o -o program

clean:
	rm -r build program

view:
	cat Makefile

edit:
	nano Makefile
