#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "traitement_image.h"



int main(int argc, char const *argv[]) {
  float a=0.299,b=0.587,c=0.114,alpha=0.5;
  FILE* f;
  image_s* image;

  if (argc == 1) {
    printf("Il manque des paramètres : \n- \"-g\" pour une image en nuance de gris\n- \"-b\" pour une image en noir et blanc\n- Nom d'un fichier .ppm à transformer (optionel)");
  }
  else if(strcmp(argv[1],"-g") && strcmp(argv[1],"-b")){
    printf("Mauvais paramètre: veuillez utiliser -g ou -b\n");
  } else if(argc > 2 && (f = fopen(argv[2],"r"))){ // Bon fichier
    char* name;
    strcpy(name,argv[2]);
    image = lire_ppm(f);
    if (!strcmp(argv[1],"-g")) {
      to_grey_level(image,a,b,c);
      strchr(name,'.')[2] = 'g';
      to_pgm(image,name);
      printf("On sauve l'image au format PGM dans le fichier %s\n", name);
    }
    else {
      to_binary(image,alpha);
      strchr(name,'.')[2] = 'b';
      to_pbm(image,name);
      printf("On sauve l'image au format PBM dans le fichier %s\n", name);
    }
  } else { // entrée standard
    printf("Pas de nom de fichier ou mauvais nom de fichier, on travaille sur l'entree std :\nA vous de vous assurer que les donnees que vous entrez sont valides pour obtenir un resultat coherent (CTRL+D puis entree pour terminer)\n");
    image = lire_ppm(stdin);
    if (!strcmp(argv[1],"-g")) {
      to_grey_level(image,a,b,c);
      to_pgm(image,"image.pgm");
      printf("On sauve l'image au format PGM dans le fichier image.pgm\n");
    }
    else {
      to_binary(image,alpha);
      to_pbm(image,"image.pbm");
      printf("On sauve l'image au format PBM dans le fichier image.pbm\n");
    }
  }

  return 0;
}
