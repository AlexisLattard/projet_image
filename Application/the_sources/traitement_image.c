#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "traitement_image.h"

uint64_t r_pixel(uint64_t pixel){
  return pixel >> 32;
}

uint64_t g_pixel(uint64_t pixel){
  return (pixel << 32) >> 48;
}

uint64_t b_pixel(uint64_t pixel){
  return (pixel << 48) >> 48;
}

image_s* lire_ppm(FILE* f){
  image_s* image = malloc(sizeof(image_s));
  uint64_t red,green,blue;
  char type[50];
  fscanf(f,"%s",type);
  if(type[1] == '3')
    image->type = P3;
  else if(type[1] == '2')
    image->type = P2;
  else
    image->type = P1;
  fscanf(f,"%d %d %hd",&(image->largeur),&(image->hauteur),&(image->val_max));
  image->pixels = malloc(image->largeur*image->hauteur*sizeof(uint64_t));
  for (int i = 0; i < image->largeur*image->hauteur; i++) {
    fscanf(f,"%ld %ld %ld",&red,&green,&blue);
    image->pixels[i] = (red << 32) + (green << 16) + blue;
  }
  return image;
}

void to_grey_level(image_s* image, float a, float b, float c){
  if (image->type == 1) {
    printf("Impossible de passer une image noir et blanc en nuance de gris.\n");
  } else if (image->type == 2){
    printf("Image deja en nuance de gris.\n");
  } else {
    for(int i = 0; i < image->largeur*image->hauteur;i++){
      image->type = P2;
      image->pixels[i] = a * r_pixel(image->pixels[i]) + b * g_pixel(image->pixels[i]) + c * b_pixel(image->pixels[i]);
    }
  }
}

void to_binary(image_s* image, float alpha){
  if (image->type == 1) {
    printf("Image deja binarise.\n");
  } else if (image->type == 2){
    printf("Impossible de binariser une image en nuance de gris.\n");
  } else {
    for(int i = 0; i < image->largeur*image->hauteur;i++){
      image->type = P1;
      image->pixels[i] = (((r_pixel(image->pixels[i]) * g_pixel(image->pixels[i]) * b_pixel(image->pixels[i]))/(float)(image->val_max*image->val_max*image->val_max)) < alpha)?1:0;
    }
  }
}

void to_pgm(image_s* image, char* name){
  FILE* f = fopen(name, "w");
  fprintf(f, "P2\n%d %d\n%hd\n",image->largeur,image->hauteur,image->val_max);
  for (int i = 0; i < image->hauteur*image->largeur; i++) {
      fprintf(f, "%ld ",image->pixels[i]);
  }
}

void to_pbm(image_s* image, char* name){
  FILE* f = fopen(name, "w");
  fprintf(f, "P1\n%d %d\n",image->largeur,image->hauteur);
  for (int i = 0; i < image->hauteur*image->largeur; i++) {
      fprintf(f, "%ld ",image->pixels[i]);
  }
}
