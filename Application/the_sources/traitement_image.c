#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "traitement_image.h"

#define CST_A 0.299
#define CST_B 0.587
#define CST_C 0.114
#define CST_ALPHA 0.5

/* Set les valeur RGB du pixel num_pixels de l'image image */
void set_pixel(image_s* image, int num_pixel, uint64_t red, uint64_t green, uint64_t blue){
    image->pixels[num_pixel] = (red << 2*TAILLE_COULEUR) + (green << TAILLE_COULEUR) + blue;
}

/* Renvoie la valeur de rouge du pixel */
uint64_t get_r_pixel(uint64_t pixel){
  return pixel >> (2*TAILLE_COULEUR);
}

/* Renvoie la valeur de vert du pixel */
uint64_t get_g_pixel(uint64_t pixel){
  return (pixel << (64 - 2*TAILLE_COULEUR)) >> (64 - TAILLE_COULEUR);
}

/* Renvoie la valeur de bleu du pixel */
uint64_t get_b_pixel(uint64_t pixel){
  return (pixel << (64 - TAILLE_COULEUR)) >> (64 - TAILLE_COULEUR);
}

/* Renvoie une instance d'image à partir
 du pointeur de fichier passé en paramètre */
image_s* lire_ppm(FILE* f){
  image_s* image = malloc(sizeof(image_s));
  uint64_t red,green,blue;
  image->type = P3;
  if(!fscanf(f,"P3 %d %d %hd",&(image->largeur),&(image->hauteur),&(image->val_max))) {
    printf("Le fichier n'est pas au format ppm.\n");
    exit(0);
  };
  image->pixels = malloc(image->largeur*image->hauteur*sizeof(uint64_t));
  for (int i = 0; i < image->largeur*image->hauteur; i++) {
    fscanf(f,"%ld %ld %ld",&red,&green,&blue);
    set_pixel(image,i,red,green,blue);
  }
  return image;
}

/* Renvoie une instance d'image en nuance de gris à partir
d'une instance d'image couleur */
image_s* to_grey_level(image_s* image){
  image_s* new_image = malloc(sizeof(image_s));
  new_image->type = P2;
  new_image->largeur = image->largeur;
  new_image->hauteur = image->hauteur;
  new_image->val_max = image->val_max;
  new_image->pixels = malloc(image->largeur*image->hauteur*sizeof(uint64_t));
  for(int i = 0; i < image->largeur*image->hauteur;i++){
    new_image->pixels[i] = CST_A * get_r_pixel(image->pixels[i]) + CST_B * get_g_pixel(image->pixels[i]) + CST_C * get_b_pixel(image->pixels[i]);
  }
  return new_image;
}

/* Renvoie une instance d'image en noir et blanc à partir
d'une instance d'image couleur */
image_s* to_binary(image_s* image){
  image_s* new_image = malloc(sizeof(image_s));
  new_image->type = P1;
  new_image->largeur = image->largeur;
  new_image->hauteur = image->hauteur;
  new_image->val_max = image->val_max;
  new_image->pixels = malloc(image->largeur*image->hauteur*sizeof(uint64_t));
  for(int i = 0; i < image->largeur*image->hauteur;i++){
    new_image->pixels[i] = (((get_r_pixel(image->pixels[i]) * get_g_pixel(image->pixels[i]) * get_b_pixel(image->pixels[i]))/(float)(image->val_max*image->val_max*image->val_max)) < CST_ALPHA)?1:0;
    // new_image->pixels[i] = (((r_pixel(image->pixels[i]) + g_pixel(image->pixels[i]) + b_pixel(image->pixels[i]))/(float)(image->val_max*3)) < alpha)?1:0;
  }
  return new_image;
}

/* Ecris une instance d'image
 en nuance de gris dans un fichier .pgm */
void to_pgm(image_s* image, char* name){
  FILE* f = fopen(name, "w");
  fprintf(f, "P2\n%d %d\n%hd\n",image->largeur,image->hauteur,image->val_max);
  for (int i = 0; i < image->hauteur*image->largeur; i++) {
      fprintf(f, "%ld ",image->pixels[i]);
  }
}

/* Ecris une instance d'image
 en noir et blanc dans un fichier .pbm */
void to_pbm(image_s* image, char* name){
  FILE* f = fopen(name, "w");
  fprintf(f, "P1\n%d %d\n",image->largeur,image->hauteur);
  for (int i = 0; i < image->hauteur*image->largeur; i++) {
      fprintf(f, "%ld ",image->pixels[i]);
  }
}

/* Prend une image couleur et un nom
et crée le fichier .pgm correspondant en nuance de gris */
void save_pgm(image_s* image,char* name){
  char name_pgm[50];
  strcpy(name_pgm,name);
  strcat(name_pgm,".pgm");

  image_s* image_g = to_grey_level(image);
  to_pgm(image_g,name_pgm);
  printf("On sauve l'image au format PGM dans le fichier %s\n", name_pgm);
}

/* Prend une image couleur et un nom
et crée le fichier .pbm correspondant en noir et blanc */
void save_pbm(image_s* image,char* name){
  char name_pbm[50];
  strcpy(name_pbm,name);
  strcat(name_pbm,".pbm");

  image_s* image_b = to_binary(image);
  to_pbm(image_b,name_pbm);
  printf("On sauve l'image au format PBM dans le fichier %s\n", name_pbm);
}
