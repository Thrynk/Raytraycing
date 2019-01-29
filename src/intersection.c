#include "../headers/intersection.h"
#include <math.h>
#include <stdio.h>


int testRayShapeIntersection(Ray ray, Shape shape, Intersection * intersection){
  if(shape.type == SPHERE){
    return testRaySphereIntersection(ray, shape.sphere, intersection);
  }
  else if(shape.type == PLAN){
    return testRayPlanIntersection(ray, shape.plan, intersection);
  }
  else{
    return 0;
  }
}

int testRayShapeIntersectionLight(Ray ray, Shape shape){
  if(shape.type == SPHERE){
    return testRaySphereIntersectionLight(ray, shape.sphere);
  }
  else if(shape.type == PLAN){
    return testRayPlanIntersectionLight(ray, shape.plan);
  }
  else{
    return 0;
  }
}

int testRaySphereIntersection(Ray ray, Sphere sphere, Intersection * intersection) {
  /* On doit résoudre l'équation */
  float t1, t2, t;
  float a = pow(ray.vecDir.x, 2) + pow(ray.vecDir.y, 2) + pow(ray.vecDir.z, 2);
  float b = 2 * (ray.vecDir.x * (ray.origin.x - sphere.center.x) + ray.vecDir.y * (ray.origin.y - sphere.center.y) + ray.vecDir.z * (ray.origin.z - sphere.center.z) );
  float c = ( pow( (ray.origin.x - sphere.center.x), 2) + pow( (ray.origin.y - sphere.center.y), 2) + pow( (ray.origin.z - sphere.center.z), 2) ) - pow(sphere.radius, 2);
  float delta = pow(b,2) - 4 * a * c;
  /*printf("delta : %f\n", delta);*/
  if(delta < 0){
    /*printf("pas d'intersection\n");*/
    intersection->inter.x = 0;
    intersection->inter.y = 0;
    intersection->inter.z = 0;
    return 0;
  }
  else if(delta == 0){
    /*printf("une seule solution\n");*/
    t = (-b / (2*a));
    intersection->inter.x = ray.origin.x + ray.vecDir.x * t;
    intersection->inter.y = ray.origin.y + ray.vecDir.y * t;
    intersection->inter.z = ray.origin.z + ray.vecDir.z * t;
    Vector normalVector = createVectorFromPoints(sphere.center, intersection->inter);
	  normalVector = normalize(normalVector);
    intersection->normal = normalVector;
    return 1;
  }
  else{
    /*printf("deux solutions\n");*/
    t1 = (-b + sqrt(delta)) / (2*a);
    t2 = (-b - sqrt(delta)) / (2*a);
    if (t1 < t2) {
      intersection->inter.x = ray.origin.x + ray.vecDir.x * t1;
      intersection->inter.y = ray.origin.y + ray.vecDir.y * t1;
      intersection->inter.z = ray.origin.z + ray.vecDir.z * t1;
    }
    else {
      intersection->inter.x = ray.origin.x + ray.vecDir.x * t2;
      intersection->inter.y = ray.origin.y + ray.vecDir.y * t2;
      intersection->inter.z = ray.origin.z + ray.vecDir.z * t2;
    }
	  Vector normalVector = createVectorFromPoints(sphere.center, intersection->inter);
	  normalVector = normalize(normalVector);
    intersection->normal = normalVector;
    return 1;
  }
}

int testRaySphereIntersectionLight(Ray ray, Sphere sphere) {
  /* On doit résoudre l'équation */
  float t1, t2, t;
  float a = pow(ray.vecDir.x, 2) + pow(ray.vecDir.y, 2) + pow(ray.vecDir.z, 2);
  float b = 2 * (ray.vecDir.x * (ray.origin.x - sphere.center.x) + ray.vecDir.y * (ray.origin.y - sphere.center.y) + ray.vecDir.z * (ray.origin.z - sphere.center.z) );
  float c = ( pow( (ray.origin.x - sphere.center.x), 2) + pow( (ray.origin.y - sphere.center.y), 2) + pow( (ray.origin.z - sphere.center.z), 2) ) - pow(sphere.radius, 2);
  float delta = pow(b,2) - 4 * a * c;
  /*printf("delta : %f\n", delta);*/
  if(delta > 0.01){
    t1 = (-b + sqrt(delta)) / (2 * a);
    t2 = (-b - sqrt(delta)) / (2 * a);
    if(t1 > t2){
      t = t1;
    }
    else if(t2 > t1){
      t = t2;
    }
    if(t > 0.01 && t < 1){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if(delta > -0.01){
    t = -b / (2 * a);
    if(t > 0.01 && t < 1){
      return 1;
    }
    else{
      return 0;
    }
  }
  return 0;
}

int testRayPlanIntersection(Ray ray, Plan plan, Intersection * intersection) {
	float t;
	float d;
	Vector normalVector = vectorProduct(plan.firstVecDir, plan.secondVecDir);
  normalVector = normalize(normalVector);
	if (dotProduct(normalVector, ray.vecDir) == 0) {
		/*printf("pas d'intersection\n");*/
    intersection->inter.x = 0;
    intersection->inter.y = 0;
    intersection->inter.z = 0;
    return 0;
	}
	else {
		d = -(normalVector.x)*(plan.point.x) + (normalVector.y)*(plan.point.y) + (normalVector.z)*(plan.point.z);


		t = -((normalVector.x)*(ray.origin.x - plan.point.x) + (normalVector.y)*(ray.origin.y - plan.point.y) + (normalVector.z)*(ray.origin.z - plan.point.z) + d) / ((normalVector.x)*(ray.vecDir.x) + (ray.vecDir.y)*(normalVector.y) + (ray.vecDir.z)*(normalVector.z));

		intersection->inter.x = ray.origin.x + ray.vecDir.x * t;
		intersection->inter.y = ray.origin.y + ray.vecDir.y * t;
		intersection->inter.z = ray.origin.z + ray.vecDir.z * t;
		intersection->normal = normalVector;
    return 1;
	}
}

int testRayPlanIntersectionLight(Ray ray, Plan plan) {
	/*float t;
	float d;
	Vector normalVector = vectorProduct(plan.firstVecDir, plan.secondVecDir);
  normalVector = normalize(normalVector);
	if (dotProduct(normalVector, ray.vecDir) == 0) {
	}*/
  return 0;
}
