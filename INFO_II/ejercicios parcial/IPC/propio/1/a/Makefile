all:
	gcc -c send.c -o send.o -Wall
	gcc -c recv.c -o recv.o -Wall
	gcc send.o -o send
	gcc recv.o -o recv
	rm *.o

clean:
	rm -f *.o send recv

view:
	cat Makefile

edit:
	nano Makefile
