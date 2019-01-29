#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/image.h"
#include "../headers/parser.h"


int main() {

	printf("Content-type: text/html;\n\n");

	printf("<html lang=\"fr\">\n");
	printf("<head>\n");
	printf("<title>Image</title>\n");
	printf("<meta charset=\"utf-8\"\n");
	printf("</title>\n");
	printf("</head>\n");
	printf("<body>\n");

	FILE * fichier = NULL;

	fichier = fopen("scene.txt", "r");

	Scene scene;

	if(fichier != NULL){
		scene = get(fichier);

		Intersection * intersection = (Intersection *) malloc(sizeof(Intersection));

		Ray ray;

		Image* I = NouvelleImage(scene.cam.xRes, scene.cam.yRes);
		Color c;
		ColorRGB cRGB;
		int numObject = -1;
		int inShadow = 0;
		Point inter;
		Vector normal;
		float distance = 1000000; /* On l'initialise très grand pour la comparaison avec distanceFromOrigin */
		for (int i = 0; i < I->w ; i++) {
		  for (int j = 0; j < I->h; j++) {
		    ray = initRay(scene.cam, i, j); /* On initialise un rayon passant par le pixel de coordonnees i, j */



		    distance = 1000000;

		    numObject = -1;

		    for(int k = 0; k < scene.numObjects; k++){
		      if(testRayShapeIntersection(ray, scene.objects[k], intersection) == 1){
		        if(distanceFromOrigin(scene.cam.position, intersection->inter) < distance){
		          distance = distanceFromOrigin(scene.cam.position, intersection->inter);
		          inter.x = intersection->inter.x;
		          inter.y = intersection->inter.y;
		          inter.z = intersection->inter.z;
		          normal = intersection->normal;
		          numObject = k;
		        }
		      }
		    }

				c.r = 0.1 * scene.objects[numObject].sphere.material.DiffuseColor.r;
		    c.g = 0.1 * scene.objects[numObject].sphere.material.DiffuseColor.g;
		    c.b = 0.1 * scene.objects[numObject].sphere.material.DiffuseColor.b;

		    for(int l = 0; l < scene.numLights; l++){
		      Ray rayLight;
		      Vector lightVector = createVectorFromPoints(inter, scene.lights[l].pointLight.position);
		      rayLight.origin = inter;
		      rayLight.vecDir = lightVector;
		      inShadow = 0;
		      for(int k = 0; k < scene.numObjects; k++){
		          if(testRayShapeIntersectionLight(rayLight, scene.objects[k]) == 1 || numObject == -1){
		            inShadow = 1;
		            break;
		          }
		        }

		      if(inShadow == 0){
		        float lambert = dotProduct(normalize(rayLight.vecDir), normal);
		        if(lambert < 0){
		          lambert = - lambert;
		        }
		        c.r += 0.9 * lambert * scene.lights[l].pointLight.color.r * scene.objects[numObject].sphere.material.DiffuseColor.r;
		        c.g += 0.9 * lambert * scene.lights[l].pointLight.color.g * scene.objects[numObject].sphere.material.DiffuseColor.g;
		        c.b += 0.9 * lambert * scene.lights[l].pointLight.color.b * scene.objects[numObject].sphere.material.DiffuseColor.b;
		        /*if(numObject != -1){
		          printf("numObject : %d\n", numObject);
		          printf("lambert : %f\n", lambert);
		          printf("raylight : %f %f %f\n", rayLight.vecDir.x, rayLight.vecDir.y, rayLight.vecDir.z);
		          printf("normal : %f %f %f\n", normal.x, normal.y, normal.z);
		          printf("couleur lum : %f %f %f\n", scene.lights[l].pointLight.color.r,scene.lights[l].pointLight.color.g,scene.lights[l].pointLight.color.b);
		          printf("couleur finale pixel : %f %f %f\n", c.r, c.g, c.b);
		        }*/
		        /*float coef = fmax(pow(dotProduct(negative(normalize(rayLight.vecDir)), reflect(normalize(rayLight.vecDir), normal)), scene.objects[numObject].sphere.material.Shininess),0);
		        c.r += coef * scene.lights[l].pointLight.color.r;
		        c.g += coef * scene.lights[l].pointLight.color.g;
		        c.b += coef * scene.lights[l].pointLight.color.b;*/
		      }
		    }
		    cRGB = convertColorInRgbFormat(c.r, c.g, c.b); /* On convertit la couleur en RGB */
		    SetPixel(I, i, j, cRGB); /* On met le pixel dans le tableau image */
		  }
		}
		Sauver(I, "image.bmp");
		DelImage(I);

		printf("<img src=\"image.bmp\" alt=\"raytracing\">\n");

		printf("</body>\n");
		printf("</html>\n");

		return 0;
	}
	else{
		return -1;
	}



}
