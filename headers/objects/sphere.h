#include "../geometry/vector.h"
#include "../color.h"
#include "../enumObjects.h"
#include "../material.h"

typedef struct sphere_{ /* Représente une sphère par son centre son rayon et sa couleur */
  ShapeType type;
  Point center;
  float radius;
  Material material;
}Sphere;
