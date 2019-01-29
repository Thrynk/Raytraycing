#include <string.h>
#include "../headers/parser.h"

Scene get(FILE * f){
  Scene scene;
  if(f != NULL){
    char chaine[TAILLE_MAX];
    char * type;
    char * token;
    float x, y, z, radius, r, g , b;
    float shininess;
    Sphere sphere;
    Camera cam;
    Shape shape;
    PointLight pointLight;
    Light light;
    int isLight = 0, isShape = 0, isCam = 0;
    int xRes, yRes;
    while(fgets(chaine, TAILLE_MAX, f) != NULL){

      type =  strtok(chaine, SEPARATEUR);

      if(strcmp(type, "sphere") == 0){

        sphere.type = SPHERE;

        /* Coord du centre */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &x);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &y);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &z);
        sphere.center.x = x;
        sphere.center.y = y;
        sphere.center.z = z;

        /* rayon */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &radius);
        sphere.radius = radius;

        /* couleur diffuse */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &r);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &g);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &b);
        sphere.material.DiffuseColor.r = r;
        sphere.material.DiffuseColor.g = g;
        sphere.material.DiffuseColor.b = b;

        /* Couleur spéculaire */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &r);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &g);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &b);
        sphere.material.SpecularColor.r = r;
        sphere.material.SpecularColor.g = g;
        sphere.material.SpecularColor.b = b;

        /* Brillance */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &shininess);
        sphere.material.Shininess = shininess;

        shape.sphere = sphere;
        shape.type = SPHERE;
        isShape++;
        if(isCam >= 1 && isLight >= 1 && isShape > 1){
          addSceneShape(&scene, shape);
        }
      }
      else if(strcmp(type, "camera") == 0){
        /* Coord de la cam */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &x);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &y);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &z);
        cam.position.x = x;
        cam.position.y = y;
        cam.position.z = z;

        /* Coord vecteur haut */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &x);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &y);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &z);
        cam.haut.x = x;
        cam.haut.y = y;
        cam.haut.z = z;

        /* Coord du point regardé et création du vecteur directeur */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &x);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &y);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &z);
        Point b;
        b.x = x;
        b.y = y;
        b.z = z;
        cam.lookDir = createVectorFromPoints(cam.position, b);
        cam.lookDir = normalize(cam.lookDir);

        /* Distance focale, largeur, vue */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &x);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &y);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &z);
        cam.distVue = x;
        cam.longVue = y;
        cam.largVue = z;

        /* Resolution */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%d", &xRes);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%d", &yRes);
        cam.xRes = xRes;
        cam.yRes = yRes;

        /* Determination du vecteur droit de la caméra */
        cam.droit = vectorProduct(cam.lookDir, cam.haut);
      	cam.droit = normalize(cam.droit);

        /* Détermination des coord du pixel haut */
        cam.pointHGVue.x = cam.distVue * cam.lookDir.x + (cam.longVue / 2) * cam.haut.x - (cam.largVue / 2) * cam.droit.x + cam.position.x;
      	cam.pointHGVue.y = cam.distVue * cam.lookDir.y + (cam.longVue / 2) * cam.haut.y - (cam.largVue / 2) * cam.droit.y + cam.position.y;
      	cam.pointHGVue.z = cam.distVue * cam.lookDir.z + (cam.longVue / 2) * cam.haut.z - (cam.largVue / 2) * cam.droit.z + cam.position.z;

        isCam++;
      }
      else if(strcmp(type, "pointLight") == 0){

        pointLight.type = POINTLIGHT;

        /* Position de la lumiere */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &x);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &y);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &z);
        pointLight.position.x = x;
        pointLight.position.y = y;
        pointLight.position.z = z;

        /* Intensité de la lumière */
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &r);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &g);
        token = strtok(NULL, SEPARATEUR);
        sscanf(token, "%f", &b);
        pointLight.color.r = r;
        pointLight.color.g = g;
        pointLight.color.b = b;

        light.pointLight = pointLight;
        light.type = POINTLIGHT;

        isLight++;

        if(isCam >= 1 && isLight > 1 && isShape >= 1){
          addSceneLight(&scene, light);
        }
      }

      if(isCam == 1 && isLight == 1 && isShape == 1){
        light.pointLight = pointLight;
        scene = createScene(shape, light, cam);
      }

    }
  }

  return scene;

}
