#include "../headers/light.h"

Color getDiffuseLight(PointLight light, Intersection * intersection, Material material){
  Color pixel;
  Vector lightVector = createVectorFromPoints(light.position, (*intersection).inter);
  float coef = dotProduct((*intersection).normal, negative(normalize(lightVector)) );
  if(coef <= 0){
    pixel.r = 0;
    pixel.g = 0;
    pixel.b = 0;
  }
  else {
    pixel.r = coef * material.DiffuseColor.r * light.color.r;
    pixel.g = coef * material.DiffuseColor.g * light.color.g;
    pixel.b = coef * material.DiffuseColor.b * light.color.b;
  }
  return pixel;
}
