#ifndef TRAITEMENT_H
#define TRAITEMENT_H

typedef enum image_type{
  P1 = 1, P2 = 2, P3 = 3
}image_type;

typedef struct {
  image_type type;
  uint32_t largeur;
  uint32_t hauteur;
  unsigned int val_max;
  uint64_t* pixels;
}image_s;

#endif
