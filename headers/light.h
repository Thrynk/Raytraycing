#include "lights/pointlight.h"

typedef union {
  LightType type;
  PointLight pointLight;
} Light;

Color getDiffuseLight(PointLight light, Intersection * intersection, Material material);
