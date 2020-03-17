all:
	gcc -c user1.c -o user1.o -Wall
	gcc -c user2.c -o user2.o -Wall
	gcc -c functions.c -o functions.o -Wall
	gcc user1.o functions.o -o user1
	gcc user2.o functions.o -o user2

clean:
	rm *.o
	rm user1 user2
	rm MIFIFO1 MIFIFO2

view:
	cat Makefile

edit:
	nano Makefile
