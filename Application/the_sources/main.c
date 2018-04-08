#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "traitement_image.h"

/* Initialise les variable du programme
en analysant les termes passé en paramètre */
void commande(char const *argv[], int* b, int* g, int* nb_file, char** tab_name, FILE** tab_f){
  for (int i = 1; argv[i] ; i++) {
    if (!strcmp(argv[i],"-b")) {
      *b = 1;
    }
    else if (!strcmp(argv[i],"-g")) {
      *g = 1;
    }
    else if (fopen(argv[i],"r")) {
      tab_f[*nb_file] = fopen(argv[i],"r");
      tab_name[*nb_file] = malloc(strlen(argv[i]) * sizeof(char));
      strncpy(tab_name[(*nb_file)++],argv[i],strlen(argv[i])-4);
    }
  }
}

int main(int argc, char const *argv[]) {
  FILE** tab_f = malloc(argc * sizeof(FILE*));
  tab_f[0] = stdin;
  image_s* image;
  int op_b=0,op_g=0,nb_file = 0;

  char** tab_name = malloc(argc * sizeof(char*));
  tab_name[0] = "image";

  commande(argv,&op_b,&op_g,&nb_file,tab_name,tab_f);

  if (!(op_b || op_g))
    printf("Il manque des paramètres : \n- \"-g\" pour une image en nuance de gris\n- \"-b\" pour une image en noir et blanc\n- Nom d'un fichier .ppm à transformer (optionel)\n");
  else{
    if (!nb_file){
      printf("Pas de nom de fichier ou mauvais nom de fichier, on travaille sur l'entree std\n");
    }
    int num_boucle = 0;
    while(tab_f[num_boucle]){
      image = lire_ppm(tab_f[num_boucle]);
      if (op_g)
      save_pgm(image,tab_name[num_boucle]);
      if (op_b)
      save_pbm(image,tab_name[num_boucle]);
      num_boucle++;
    }
  }

  return 0;
}
