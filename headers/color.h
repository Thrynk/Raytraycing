#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct color_ {
	float r;
	float g;
	float b;
}Color;



Color addColors(Color a, Color b);

Color subColors(Color a, Color b);

Color multColors(Color a, Color b);

Color divColors(Color a, Color b);
