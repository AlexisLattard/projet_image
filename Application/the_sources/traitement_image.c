#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../the_headers/traitement_image.h"

image_s* lire_ppm(FILE* f){
  image_s* image = malloc(sizeof(image_s));
  fscanf(f,"%s %d %d %d",image->type,&(image->largeur),&(image->hauteur),&(image->val_max));
  printf("%s %d %d %d\n",image->type,image->largeur,image->hauteur,image->val_max );
}
/*
uint64_t mask(uint64_t, unsigned int longueur, unsigned int debut) {
  for
}

void to_grey_level(image_s* image, unsigned float a, unsigned float b, unsigned float c){

}

void to_binary(image_s* image, unsigned float alpha){
  for (int i = 0; i < count; i++) {
    if ((image->pixels[i])/pow(image->val_max, 3) < alpha) {
      image->pixels[i] = 1;
    } else {
      image->pixels[i] = 0;
    }
  }
}
*/
void to_pgm(image_s* image){

}

void to_pbm(image_s* image){

}

int main(int argc, char const *argv[]) {
  FILE* f = fopen("disney_045.ppm","r");
  image_s* image = lire_ppm(f);

  return 0;
}
