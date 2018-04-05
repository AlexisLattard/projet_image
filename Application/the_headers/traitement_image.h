#ifndef STRUCT_IMAGE_H
#define STRUCT_IMAGE_H

typedef enum image_type {
  P1 = 1, P2 = 2, P3 = 3
}image_type;

typedef struct {
  image_type type;
  uint32_t largeur;
  uint32_t hauteur;
  uint16_t val_max;
  uint64_t* pixels;
}image_s;

uint64_t r_pixel(uint64_t pixel);

uint64_t g_pixel(uint64_t pixel);

uint64_t b_pixel(uint64_t pixel);

image_s* lire_ppm(FILE* f);

void to_grey_level(image_s* image, float a, float b, float c);

void to_binary(image_s* image, float alpha);

void to_pgm(image_s* image, char* name);

void to_pbm(image_s* image, char* name);


#endif
