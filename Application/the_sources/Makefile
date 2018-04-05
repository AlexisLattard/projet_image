# Creation des variables
HEAD_DIR = ../the_headers
BIN_DIR = ../bin
CC = gcc
EXEC = traitement_image

all : $(EXEC)

# Utilisation des variables internes ^ (la liste des dependances),
#	ainsi que @ (la cible de l'action) dans l'action suivante
$(EXEC): $(EXEC).o main.o
	$(CC) -o $(BIN_DIR)/$(EXEC) $^

# Utilisation de la règle générique .o.c qui effectue l'action de
# generation, decrite a la suite, de tous les .c a partir des .o
%.o: %.c
	$(CC) -o $@ -I $(HEAD_DIR) -c $^

# Nettoyage de tous les fichiers crees par le make ou par l'appel
# de l'executable
clean :
	rm -f *.o *.pgm *.pbm $(BIN_DIR)/*
