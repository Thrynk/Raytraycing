#include "camera.h"

typedef struct ray_{ /* Représente un rayon passant de la cam et passant par un pixel */
  Point origin;
  Vector vecDir;
} Ray;

Ray initRay(Camera a, int posX, int posY);

Vector reflect(Vector rayLight, Vector normal);
