all :

traitement_image: traitement_image.o main.o
		gcc -o ../bin/traitement_image traitement_image.o main.o

main.o: main.c
	gcc -o main.o -I ../the_headers -c main.c

traitement_image.o: traitement_image.c
	gcc -o traitement_image.o -I ../the_headers -c traitement_image.c
