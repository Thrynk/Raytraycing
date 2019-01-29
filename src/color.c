#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/color.h"




Color addColors(Color a, Color b){
  Color c;

  c.r = fmax(fmin(a.r + b.r ,1) ,0);
  c.g = fmax(fmin(a.g + b.g ,1) ,0);
  c.b = fmax(fmin(a.b + b.b ,1) ,0);

  return c;
}

Color multColors(Color a, Color b){
  Color c;

  c.r = fmax(fmin(a.r * b.r ,1) ,0);
  c.g = fmax(fmin(a.g * b.g ,1) ,0);
  c.b = fmax(fmin(a.b * b.b ,1) ,0);

  return c;
}
