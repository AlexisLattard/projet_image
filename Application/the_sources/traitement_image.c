#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include "../the_headers/traitement_image.h"

image_s* lire_ppm(FILE* f){

}

uint64_t mask(uint64_t pixel, unsigned int longueur, unsigned int debut) {
  uint64_t mask = 0;
  mask = ((~mask)>>(64 - longueur))<<debut;
  return (pixel & mask)>>debut;
}

void to_grey_level(image_s* image, float a, float b, float c){

}

void to_binary(image_s* image, float alpha){
  for (int i = 0; i < image->largeur*image->hauteur; i++) {
    if ((mask(image->pixels[i], 16, 0)*mask(image->pixels[i], 16, 16)*mask(image->pixels[i], 16, 32))/pow(image->val_max, 3) < alpha)
      image->pixels[i] = 1;
    else
      image->pixels[i] = 0;
  }
}

void to_pgm(image_s* image){

}

void to_pbm(image_s* image){

}

int main(int argc, char const *argv[]) {
  uint64_t test = 0;
  printf("%"PRIu64"\n", mask(~test, 16, 0));

  return 0;
}
