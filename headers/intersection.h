#include "ray.h"
#include "shape.h"

typedef struct intersection_{ /* Représente l'intersection d'un rayon avec un objet ainsi que la couleur de celui-ci au point d'interesection */
  Point inter;
  Vector normal;
} Intersection;

int testRayShapeIntersection(Ray ray, Shape shape, Intersection * intersection); /* teste s'il y a intersection ou non entre un rayon et un objet de la scène */

int testRayShapeIntersectionLight(Ray ray, Shape shape);

int testRaySphereIntersection(Ray ray, Sphere sphere, Intersection * intersection);

int testRaySphereIntersectionLight(Ray ray, Sphere sphere);

int testRayPlanIntersection(Ray ray, Plan plan, Intersection * intersection);

int testRayPlanIntersectionLight(Ray ray, Plan plan);
