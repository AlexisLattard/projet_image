#ifndef STRUCT_IMAGE_H
#define STRUCT_IMAGE_H

#define TAILLE_COULEUR 16

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

void set_pixel(image_s* image,int num_pixel, uint64_t red, uint64_t green, uint64_t blue);

uint64_t get_r_pixel(uint64_t pixel);

uint64_t get_g_pixel(uint64_t pixel);

uint64_t get_b_pixel(uint64_t pixel);

image_s* lire_ppm(FILE* f);

image_s* to_grey_level(image_s* image);

image_s* to_binary(image_s* image);

void to_pgm(image_s* image, char* name);

void to_pbm(image_s* image, char* name);

void save_pgm(image_s* image,char* name);

void save_pbm(image_s* image,char* name);


#endif
