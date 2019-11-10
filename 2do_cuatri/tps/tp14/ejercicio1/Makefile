all:
	gcc -c src/servidor/servidor.c -o bin/servidor.o -Wall
	gcc -c src/servidor/functions_s.c -o bin/functions_s.o -Wall
	gcc -c src/cliente/cliente.c -o bin/cliente.o -Wall
	g++ -c src/cliente/functions_c.c -o bin/functions_c.o -Wall
	gcc bin/servidor.o bin/functions_s.o -o servidor
	gcc bin/cliente.o bin/functions_c.o -o cliente  `pkg-config --cflags --libs opencv`
	mv bin/servidor exe/servidor/
	mv bin/cliente exe/cliente/
