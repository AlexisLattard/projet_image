LIB_DIR=../../lib
HEAD_DIR=../the_headers

traitement_image: traitement_image.o
		gcc -o ../bin/traitement_image traitement_image.o

traitement_image.o: traitement_image.c $(HEAD_DIR)/traitement_image.h
	gcc -o traitement_image.o -c traitement_image.c
