all:
	mkdir build
	gcc -c src/main.c -o build/main.o -Wall
	gcc build/*.o -o program

clean:
	rm -r build program

view:
	cat Makefile

edit:
	nano Makefile
