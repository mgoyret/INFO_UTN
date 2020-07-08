all:
	rm -r -f build
	mkdir build
	gcc -c src/functions.c -o build/functions.o -Wall
	gcc -c src/main.c -o build/main.o -Wall
	gcc build/*.o -o program

clean:
	rm -r -f build program

view:
	cat Makefile

edit:
	nano Makefile
