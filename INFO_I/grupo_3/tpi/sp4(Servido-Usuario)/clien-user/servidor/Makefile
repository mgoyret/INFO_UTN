################################################################
# AUTHOR INFORMATION                                           #
################################################################

AUTHOR      = "JavierBalloffet"
CLASS       = "R1042"
TP          = "TP1"
YEAR        = "2019"

################################################################
# COMPILER AND ARGUMENTS                                       #
################################################################

CC          = gcc
CFLAGS      = -c -Wall
LDFLAGS     = -lm -Llib -lsockets_server

################################################################
# SOURCES, HEADERS, OBJECTS AND EXECUTABLE                     #
################################################################

SRC_DIR     = src
BUILD_DIR   = build
BIN_DIR     = bin

SOURCES     = $(shell find $(SRC_DIR) -name '*.c')
OBJS        = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES))
HEADERS     = $(shell find $(SRC_DIR) -name '*.h')
EXEC        = servidor

################################################################
# TAR FILE INFORMATION                                         #
################################################################

FILE_NAME   = $(AUTHOR)-$(CLASS)-$(TP)-$(YEAR).tar.gz

################################################################
# TEXT EDITOR                                                  #
################################################################

TEXT_EDITOR = code

################################################################
# DOCUMENTATION                                                #
################################################################

DOC_GEN     = doxygen
DOC_FILE    = Doxyfile
DOC_DIR     = doxy

################################################################
# MAKE TARGETS                                                 #
################################################################

.PHONY: all clean compress edit doc run help

all: $(EXEC)

$(EXEC): $(OBJS)
	@echo ''
	@echo '*****************************************************'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $(BIN_DIR)/$@
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(BUILD_DIR)/%.o: %.c Makefile
	@echo ''
	@echo '*****************************************************'
	@echo '---> Compiling...'
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
	@echo '---> Compiling Complete!'
	@echo '*****************************************************'
	@echo ''

clean:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Cleaning...'
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(DOC_DIR)
	@echo '---> Cleaning Complete!'
	@echo '*****************************************************'
	@echo ''

compress: $(SRC_DIR) Makefile $(DOC_FILE)
	@echo ''
	@echo '*****************************************************'
	@echo '---> Packing...'
	tar -zcvf $(FILE_NAME) $(SRC_DIR) Makefile $(DOC_FILE)
	@echo '---> Packing Complete!'
	@echo '*****************************************************'
	@echo ''

edit:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Editing...'
	$(TEXT_EDITOR) .

doc:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Generating Code Documentation...'
	$(DOC_GEN) $(DOC_FILE)
	@echo '---> Generating Code Documentation Complete!'
	@echo '*****************************************************'
	@echo ''

run:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Running...'
	./$(BIN_DIR)/$(EXEC)

help:
	@echo ''
	@echo '*****************************************************'
	@echo '  Uso:'
	@echo '    make all:       Compiles and Links'
	@echo '    make clean:     Removes objects and executable'
	@echo '    make compress:  Generates .tar.gz file'
	@echo '    make edit:      Opens code files with text editor'
	@echo '    make doc:       Generates code documentation'
	@echo '    make run:       Runs executable'
	@echo '    make help:      Shows help'
	@echo '*****************************************************'
	@echo ''