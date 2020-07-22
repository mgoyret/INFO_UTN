all:
	gcc -c send.c -o send.o -Wall
	gcc -c temp.c -o temp.o -Wall
	gcc -c pres.c -o pres.o -Wall
	gcc -c hum.c -o hum.o -Wall
	gcc send.o -o send
	gcc temp.o -o temp
	gcc pres.o -o pres
	gcc hum.o -o hum
	rm *.o

clean:
	rm -f *.o send temp pres hum

view:
	cat Makefile

edit:
	nano Makefile
