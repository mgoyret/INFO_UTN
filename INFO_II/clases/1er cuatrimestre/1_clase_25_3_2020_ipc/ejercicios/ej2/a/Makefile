all:
	rm -r -f build prog1 prog2
	mkdir build
	gcc -c src/main.c -o build/main.o -Wall
	gcc -c src/main2.c -o build/main2.o -Wall
	gcc -c src/functions.c -o build/functions.o -Wall
	gcc build/main.o build/functions.o -o prog1
	gcc build/main2.o build/functions.o -o prog2

clean:
	rm -r build prog1 prog2

view:
	cat Makefile

edit:
	nano Makefile
