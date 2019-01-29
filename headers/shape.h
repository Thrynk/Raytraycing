#include "objects/sphere.h"
#include "objects/plan.h"

typedef union { /* type général pour les différentes formes */
  ShapeType type;
  Sphere sphere;
  Plan plan;
} Shape;
