#include "../../headers/geometry/vector.h"
#include <math.h>

Vector initVector(float x, float y, float z){
  Vector a;

  a.x = x;
  a.y = y;
  a.z = z;

  return a;
}

Vector createVectorFromPoints(Point a, Point b){
  Vector c;

  c.x = b.x - a.x;
  c.y = b.y - a.y;
  c.z = b.z - a.z;

  return c;
}

Vector addVectors(Vector a, Vector b){
	Vector c = { 0,0,0 };

  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = c.z + b.z;

  return c;
}

Vector subVectors(Vector a, Vector b){
	Vector c = { 0,0,0 };

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = c.z - b.z;

  return c;
}

Vector multVector(Vector a, float b){
  Vector c;

  c.x = b*a.x;
  c.y = b*a.y;
  c.z = b*a.z;

  return c;
}

Vector divVector(Vector a, float b){
  Vector c;

  c.x = a.x / b;
  c.y = a.y / b;
  c.z = a.z / b;

  return c;
}

float dotProduct(Vector a, Vector b){
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float norm(Vector a){
  return ( sqrt(dotProduct(a, a)) );
}

Vector normalize(Vector a){
  return divVector(a, norm(a));
}

Vector vectorProduct(Vector a, Vector b){
  Vector c;

  c.x = a.y * b.z - a.z * b.y;
  c.y = a.z * b.x - a.x * b.z;
  c.z = a.x * b.y - a.y * b.x;

  return c;
}

float distanceFromOrigin(Point a, Point o){
  Vector oa = createVectorFromPoints(o, a);
  return norm(oa);
}

Vector negative(Vector a){
  Vector b;
	b.x = - a.x;
	b.y = - a.y;
	b.z = - a.z;
	return b;
}
