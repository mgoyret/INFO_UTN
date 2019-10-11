
client_src = $(wildcard *_client.c)
server_src = $(wildcard *_server.c)

client_obj = $(client_src:.c=.o)
server_obj = $(server_src:.c=.o)

exec_client = client
exec_server = server


CC = gcc
C_PARAM = -c -g
LD= -lm


all: client server

client: $(client_obj)
	@echo "\n===================================================================================="
	@echo "  Linking" $(OBJ)    
	@echo "===================================================================================="
	$(CC) -o $(exec_client) $(client_obj) $(LD)

server: $(server_obj)
	@echo "\n===================================================================================="
	@echo "  Linking" $(OBJ)    
	@echo "===================================================================================="
	$(CC) -o $(exec_server) $(server_obj) $(LD)
		
%.o: %.c
	@echo "\n===================================================================================="
	@echo "  Compiling the file: " $< 
	@echo "===================================================================================="
	$(CC) $(C_PARAM) $< -o $@ 
	
clean: 
	rm -f $(exec_client) $(exec_server) $(server_obj) $(client_obj)
