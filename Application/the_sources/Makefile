HEAD_DIR = ../the_headers
BIN_DIR = ../bin
CC = gcc
EXEC = traitement_image

all : $(EXEC)

$(EXEC): $@.o main.o
	$(CC) -o $(BIN_DIR)/$(EXEC) $^

%.o: %.c
	$(CC) -o $@ -I $(HEAD_DIR) -c $^

clean :
	rm -f *.o *.pgm *.pbm $(BIN_DIR)/*
