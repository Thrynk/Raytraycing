#include "../headers/scene.h"

Scene createScene(Shape shape, Light light, Camera cam){
  Scene a;
  /*a.objects = (Shape *) malloc(sizeof(Shape));
  a.lights = (Light *) malloc(sizeof(Light));*/
  a.cam = cam;
  a.objects[0] = shape;
  a.lights[0] = light;
  a.numLights = 1;
  a.numObjects = 1;

  return a;
}

void addSceneShape(Scene * scene, Shape shape){
  /*Shape * newObjects = realloc(scene->objects, sizeof(scene->objects) + sizeof(Shape));
  if(newObjects != NULL){
    scene->objects = newObjects;
    scene->objects[scene->numObjects] = shape;
    scene->numObjects = scene->numObjects + 1;
  }
  else{
    printf("Erreur de réallocation mémoire.\n");
  }*/
  scene->objects[scene->numObjects] = shape;
  scene->numObjects = scene->numObjects + 1;
}

void addSceneLight(Scene * scene, Light light){
  /*scene->lights = realloc(scene->lights, (scene->numLights + 1) * sizeof(Light));*/
  scene->lights[scene->numLights] = light;
  scene->numLights = scene->numLights + 1;
}
