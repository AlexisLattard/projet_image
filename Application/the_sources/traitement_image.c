#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../the_headers/traitement_image.h"

image_s* lire_ppm(FILE* f){

}

uint64_t mask(uint64_t pixel, unsigned int longueur, unsigned int debut) {
  uint64_t mask = 0;
  mask = ((~mask)>>(64 - longueur))<<debut;
  return (pixel & mask)>>debut;
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

void to_pgm(image_s* image){

}

void to_pbm(image_s* image){

}

int main(int argc, char const *argv[]) {

  return 0;
}
