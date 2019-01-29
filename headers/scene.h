#include "light.h"

typedef struct scene_{ /* contient toute la scène rentrée par l'utilisateur */
  int numObjects, numLights; /* nombre d'objets dans le tableau de Shapes */
  Shape objects[50]; /* tableau dynamique d'objets de la scène */
  Light lights[50];
  Camera cam;
} Scene;

Scene createScene(Shape shape, Light light, Camera cam);

void addSceneShape(Scene * scene, Shape shape);

void addSceneLight(Scene * scene, Light light);
