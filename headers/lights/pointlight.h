#include "../enumLights.h"
#include "../intersection.h"

typedef struct pointlight_ {
	Point position;
	Color color;
	LightType type;
} PointLight;
