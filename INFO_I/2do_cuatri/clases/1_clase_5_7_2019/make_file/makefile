################################################################
# AUTHOR INFORMATION                                           #
################################################################

AUTHOR = "Marcos_Goyret"
CLASS = "R1042"
#TP = "TP1"
YEAR = "2019"

################################################################
# COMPILER AND ARGUMENTS                                       #
################################################################

CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lm

################################################################
# SOURCES, HEADERS, OBJECTS AND EXECUTABLE                     #
################################################################

SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SOURCES))
HEADERS = $(wildcard *.h)
EXE = program

################################################################
# TAR FILE INFORMATION                                         #
################################################################

FILE_NAME = $(AUTHOR)-$(CLASS)-$(TP)-$(YEAR).tar.gz

################################################################
# MAKE TARGETS                                                 #
################################################################

.PHONY: all clean compress edit run help

all: $(EXE)

$(EXE): $(OBJS)
	@echo ''
	@echo '*****************************************************'
	@echo '---> Linking...'
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

%.o: %.c makefile
	@echo ''
	@echo '*****************************************************'
	@echo '---> Compiling...'
	$(CC) $(CFLAGS) $< -o $@
	@echo '---> Compiling Complete!'
	@echo '*****************************************************'
	@echo ''

clean:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Cleaning...'
	rm -f $(OBJS) $(EXE)
	@echo '---> Cleaning Complete!'
	@echo '*****************************************************'
	@echo ''

compress: $(SOURCES) $(HEADERS) makefile
	@echo ''
	@echo '*****************************************************'
	@echo '---> Packing...'
	tar -zcvf $(FILE_NAME) $(SOURCES) $(HEADERS) makefile
	@echo '---> Packing Complete!'
	@echo '*****************************************************'
	@echo ''

edit:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Editing...'
	code .

run: $(EXE)
	@echo ''
	@echo '*****************************************************'
	@echo '---> Running...'
	./$(EXE)

help:
	@echo ''
	@echo '*****************************************************'
	@echo '  Uso:'
	@echo '    make all:       Compiles and Links'
	@echo '    make file.o:    Compiles file.c'
	@echo '    make clean:     Removes objects and executable'
	@echo '    make compress:  Generates .tar.gz file'
	@echo '    make edit:      Opens code files with text editor'
	@echo '    make run:       Runs executable'
	@echo '    make help:      Shows help'
	@echo '*****************************************************'
	@echo ''
